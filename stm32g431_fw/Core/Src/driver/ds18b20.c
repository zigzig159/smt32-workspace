/*
 * ds18b20.c
 *
 *  Created on: Mar 18, 2026
 *      Author: RND1
 */


#include "ds18b20.h"

/* -------------------- Private defines -------------------- */
#define DS18B20_CMD_SKIP_ROM          0xCC
#define DS18B20_CMD_CONVERT_T         0x44
#define DS18B20_CMD_READ_SCRATCHPAD   0xBE

/************************************************************
 * DWT based microsecond delay
 ************************************************************/
static void DWT_Delay_Init(void)
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

static void delay_us(uint32_t us)
{
    uint32_t start = DWT->CYCCNT;
    uint32_t cycles = us * (HAL_RCC_GetHCLKFreq() / 1000000U);
    while ((DWT->CYCCNT - start) < cycles)
    {
    }
}

/************************************************************
 * GPIO control for 1-Wire
 * Low 출력 시: Open-Drain Output
 * Release 시: Input mode (외부 4.7k pull-up으로 High)
 ************************************************************/
static void OW_Pin_OutputLow(DS18B20_HandleTypeDef *hds)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = hds->GPIO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(hds->GPIOx, &GPIO_InitStruct);

    HAL_GPIO_WritePin(hds->GPIOx, hds->GPIO_Pin, GPIO_PIN_RESET);
}

static void OW_Pin_Release(DS18B20_HandleTypeDef *hds)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = hds->GPIO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(hds->GPIOx, &GPIO_InitStruct);
}

static uint8_t OW_ReadPin(DS18B20_HandleTypeDef *hds)
{
    return (uint8_t)HAL_GPIO_ReadPin(hds->GPIOx, hds->GPIO_Pin);
}

/************************************************************
 * CRC8 (Dallas/Maxim)
 * Polynomial: x^8 + x^5 + x^4 + 1
 ************************************************************/
static uint8_t DS18B20_CRC8(const uint8_t *data, uint8_t len)
{
    uint8_t crc = 0;

    for (uint8_t i = 0; i < len; i++)
    {
        uint8_t inbyte = data[i];
        for (uint8_t j = 0; j < 8; j++)
        {
            uint8_t mix = (crc ^ inbyte) & 0x01;
            crc >>= 1;
            if (mix)
                crc ^= 0x8C;
            inbyte >>= 1;
        }
    }
    return crc;
}

/************************************************************
 * 1-Wire low level
 ************************************************************/
void DS18B20_Init(DS18B20_HandleTypeDef *hds, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    hds->GPIOx = GPIOx;
    hds->GPIO_Pin = GPIO_Pin;

    DWT_Delay_Init();
    OW_Pin_Release(hds);
}

uint8_t DS18B20_ResetPulse(DS18B20_HandleTypeDef *hds)
{
    uint8_t presence = 0;

    /* Master reset pulse: low for >= 480us */
    OW_Pin_OutputLow(hds);
    delay_us(500);

    /* Release bus and wait 15~60us */
    OW_Pin_Release(hds);
    delay_us(70);

    /* Presence pulse: slave pulls low */
    presence = !OW_ReadPin(hds);

    /* Wait end of timeslot */
    delay_us(430);

    return presence;
}

static void DS18B20_WriteBit(DS18B20_HandleTypeDef *hds, uint8_t bit)
{
    if (bit)
    {
        /* Write 1: pull low briefly then release */
        OW_Pin_OutputLow(hds);
        delay_us(5);
        OW_Pin_Release(hds);
        delay_us(60);
    }
    else
    {
        /* Write 0: hold low for whole slot */
        OW_Pin_OutputLow(hds);
        delay_us(65);
        OW_Pin_Release(hds);
        delay_us(5);
    }
}

static uint8_t DS18B20_ReadBit(DS18B20_HandleTypeDef *hds)
{
    uint8_t bit;

    /* Start read slot */
    OW_Pin_OutputLow(hds);
    delay_us(3);

    /* Release and sample within ~15us */
    OW_Pin_Release(hds);
    delay_us(10);

    bit = OW_ReadPin(hds);

    /* Complete slot */
    delay_us(53);

    return bit;
}

void DS18B20_WriteByte(DS18B20_HandleTypeDef *hds, uint8_t data)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        DS18B20_WriteBit(hds, data & 0x01);
        data >>= 1;
    }
}

uint8_t DS18B20_ReadByte(DS18B20_HandleTypeDef *hds)
{
    uint8_t data = 0;

    for (uint8_t i = 0; i < 8; i++)
    {
        data >>= 1;
        if (DS18B20_ReadBit(hds))
        {
            data |= 0x80;
        }
    }

    return data;
}

/************************************************************
 * High level functions
 ************************************************************/
HAL_StatusTypeDef DS18B20_StartConversion(DS18B20_HandleTypeDef *hds)
{
    if (!DS18B20_ResetPulse(hds))
        return HAL_ERROR;

    /* Single device on bus -> Skip ROM */
    DS18B20_WriteByte(hds, DS18B20_CMD_SKIP_ROM);
    DS18B20_WriteByte(hds, DS18B20_CMD_CONVERT_T);

    return HAL_OK;
}

HAL_StatusTypeDef DS18B20_ReadScratchpad(DS18B20_HandleTypeDef *hds, uint8_t *scratchpad)
{
    if (!DS18B20_ResetPulse(hds))
        return HAL_ERROR;

    DS18B20_WriteByte(hds, DS18B20_CMD_SKIP_ROM);
    DS18B20_WriteByte(hds, DS18B20_CMD_READ_SCRATCHPAD);

    for (uint8_t i = 0; i < 9; i++)
    {
        scratchpad[i] = DS18B20_ReadByte(hds);
    }

    if (DS18B20_CRC8(scratchpad, 8) != scratchpad[8])
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

HAL_StatusTypeDef DS18B20_ReadTemperature(DS18B20_HandleTypeDef *hds, float *temperature_c)
{
    uint8_t scratchpad[9];
    int16_t raw;

    if (DS18B20_StartConversion(hds) != HAL_OK)
        return HAL_ERROR;

    /* 12-bit default conversion time max 750ms */
    HAL_Delay(750);

    if (DS18B20_ReadScratchpad(hds, scratchpad) != HAL_OK)
        return HAL_ERROR;

    raw = (int16_t)((scratchpad[1] << 8) | scratchpad[0]);
    *temperature_c = (float)raw / 16.0f;

    return HAL_OK;
}
