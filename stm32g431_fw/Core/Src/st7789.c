/*
 * st7789.c
 *
 *  Created on: Sep 9, 2025
 *      Author: RND1
 */


#include "st7789.h"

// --- 내부 유틸 ---
static inline void CS_Select(void)   { HAL_GPIO_WritePin(ST7789_CS_GPIO_Port, ST7789_CS_Pin, GPIO_PIN_RESET); }
static inline void CS_Unselect(void) { HAL_GPIO_WritePin(ST7789_CS_GPIO_Port, ST7789_CS_Pin, GPIO_PIN_SET); }
static inline void DC_Command(void)  { HAL_GPIO_WritePin(ST7789_DC_GPIO_Port, ST7789_DC_Pin, GPIO_PIN_RESET); }
static inline void DC_Data(void)     { HAL_GPIO_WritePin(ST7789_DC_GPIO_Port, ST7789_DC_Pin, GPIO_PIN_SET); }

static void ST7789_Reset(void) {
    HAL_GPIO_WritePin(ST7789_RST_GPIO_Port, ST7789_RST_Pin, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(ST7789_RST_GPIO_Port, ST7789_RST_Pin, GPIO_PIN_SET);
    HAL_Delay(120);
}

static void WriteCommand(uint8_t cmd) {
    CS_Select();
    DC_Command();
    HAL_SPI_Transmit(&ST7789_SPI_HANDLE, &cmd, 1, HAL_MAX_DELAY);
    CS_Unselect();
}

static void WriteData(const uint8_t *data, uint16_t len) {
    CS_Select();
    DC_Data();
    HAL_SPI_Transmit(&ST7789_SPI_HANDLE, (uint8_t*)data, len, HAL_MAX_DELAY);
    CS_Unselect();
}

static void WriteData16(uint16_t data) {
    uint8_t buf[2] = { data >> 8, data & 0xFF };
    WriteData(buf, 2);
}

static void SetAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
    x0 += ST7789_X_OFFSET; x1 += ST7789_X_OFFSET;
    y0 += ST7789_Y_OFFSET; y1 += ST7789_Y_OFFSET;

    uint8_t caset[] = { (x0 >> 8) & 0xFF, x0 & 0xFF, (x1 >> 8) & 0xFF, x1 & 0xFF };
    uint8_t raset[] = { (y0 >> 8) & 0xFF, y0 & 0xFF, (y1 >> 8) & 0xFF, y1 & 0xFF };

    WriteCommand(0x2A); // CASET
    WriteData(caset, 4);
    WriteCommand(0x2B); // RASET
    WriteData(raset, 4);
    WriteCommand(0x2C); // RAMWR
}

static uint8_t rotation = 0; // 0~3

void ST7789_SetRotation(uint8_t rot) {
    rotation = rot & 0x03;
    WriteCommand(0x36); // MADCTL
    uint8_t madctl = 0x00; // RGB
    switch(rotation) {
        case 0: madctl = 0x00; break;           // Portrait
        case 1: madctl = 0x60; break;           // Landscape (MV|MX)
        case 2: madctl = 0xC0; break;           // Portrait 180 (MY|MX)
        case 3: madctl = 0xA0; break;           // Landscape 180 (MV|MY)
    }
    WriteData(&madctl, 1);
}

void ST7789_Init(void) {
    // 하드 리셋
    ST7789_Reset();

    // SWRESET
    WriteCommand(0x01);
    HAL_Delay(150);

    // SLPOUT
    WriteCommand(0x11);
    HAL_Delay(120);

    // 컬러 포맷 16bit
    WriteCommand(0x3A);
    uint8_t colmod = 0x55; // 16-bit/pixel
    WriteData(&colmod, 1);

    // 인버트: 패널에 따라 다름. 보통 INVON(0x21)이 색감이 정상인 경우가 많음.
    WriteCommand(0x20); // INVON
    HAL_Delay(10);

    // 노멀 디스플레이
    WriteCommand(0x13); // NORON
    HAL_Delay(10);

    // 디스플레이 ON
    WriteCommand(0x29); // DISPON
    HAL_Delay(100);

    // 기본 회전
    ST7789_SetRotation(0);
}

void ST7789_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
    if (x >= ST7789_WIDTH || y >= ST7789_HEIGHT) return;
    SetAddrWindow(x, y, x, y);
    WriteData16(color);
}

void ST7789_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) {
    if (x >= ST7789_WIDTH || y >= ST7789_HEIGHT) return;
    if ((x + w) > ST7789_WIDTH)  w = ST7789_WIDTH - x;
    if ((y + h) > ST7789_HEIGHT) h = ST7789_HEIGHT - y;

    SetAddrWindow(x, y, x + w - 1, y + h - 1);

    // 한 번에 너무 크게 보내지 말고 적당히 쪼개서
    // (스택/버퍼 문제 방지)
    uint32_t pixels = (uint32_t)w * h;
    uint8_t buf[256]; // 128픽셀(2바이트/픽셀)
    for (int i = 0; i < sizeof(buf); i += 2) {
        buf[i] = color >> 8;
        buf[i+1] = color & 0xFF;
    }
    while (pixels) {
        uint16_t chunk = (pixels > (sizeof(buf)/2)) ? (sizeof(buf)/2) : pixels;
        WriteData(buf, chunk * 2);
        pixels -= chunk;
    }
}

void ST7789_DrawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) {
    if (w == 0 || h == 0) return;
    // 상/하
    ST7789_FillRect(x, y, w, 1, color);
    ST7789_FillRect(x, y + h - 1, w, 1, color);
    // 좌/우
    ST7789_FillRect(x, y, 1, h, color);
    ST7789_FillRect(x + w - 1, y, 1, h, color);
}

void ST7789_FillScreen(uint16_t color) {
    ST7789_FillRect(0, 0, ST7789_WIDTH, ST7789_HEIGHT, color);
}

void ST7789_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t *data_rgb565) {
    if (x >= ST7789_WIDTH || y >= ST7789_HEIGHT) return;
    if ((x + w) > ST7789_WIDTH)  w = ST7789_WIDTH - x;
    if ((y + h) > ST7789_HEIGHT) h = ST7789_HEIGHT - y;

    SetAddrWindow(x, y, x + w - 1, y + h - 1);

    // 송신 (RGB565 -> big-endian)
    uint32_t pixels = (uint32_t)w * h;
    // 작은 버퍼를 사용해 변환/전송
    uint8_t buf[256]; // 128픽셀
    uint32_t idx = 0;
    while (pixels) {
        uint16_t chunk = (pixels > 128) ? 128 : pixels;
        for (uint16_t i = 0; i < chunk; i++) {
            uint16_t c = *data_rgb565++;
            buf[2*i]   = c >> 8;
            buf[2*i+1] = c & 0xFF;
        }
        WriteData(buf, chunk * 2);
        pixels -= chunk;
        idx += chunk;
    }
}
