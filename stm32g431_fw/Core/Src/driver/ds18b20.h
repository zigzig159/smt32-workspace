/*
 * ds18b20.h
 *
 *  Created on: Mar 18, 2026
 *      Author: RND1
 */

#ifndef SRC_DRIVER_DS18B20_H_
#define SRC_DRIVER_DS18B20_H_

#include "main.h"
#include <stdint.h>

typedef struct
{
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
} DS18B20_HandleTypeDef;

void DS18B20_Init(DS18B20_HandleTypeDef *hds, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
uint8_t DS18B20_ResetPulse(DS18B20_HandleTypeDef *hds);
void DS18B20_WriteByte(DS18B20_HandleTypeDef *hds, uint8_t data);
uint8_t DS18B20_ReadByte(DS18B20_HandleTypeDef *hds);

HAL_StatusTypeDef DS18B20_StartConversion(DS18B20_HandleTypeDef *hds);
HAL_StatusTypeDef DS18B20_ReadScratchpad(DS18B20_HandleTypeDef *hds, uint8_t *scratchpad);
HAL_StatusTypeDef DS18B20_ReadTemperature(DS18B20_HandleTypeDef *hds, float *temperature_c);

#endif /* SRC_DRIVER_DS18B20_H_ */
