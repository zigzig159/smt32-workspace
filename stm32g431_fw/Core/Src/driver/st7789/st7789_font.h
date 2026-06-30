/*
 * ssd1306_font.h
 *
 *  Created on: Apr 24, 2025
 *      Author: RND1
 */

#ifndef DRIVER_ST7789_ST7789_FONT_H_
#define DRIVER_ST7789_ST7789_FONT_H_

#include <stdint.h>


/* ST7789 Include Font */
#define ST7789_INCLUDE_FONT_6X8
//#define ST7789_INCLUDE_FONT_7X10
//#define ST7789_INCLUDE_FONT_11X18
//#define ST7789_INCLUDE_FONT_16X26


/* ST7789 Font Structure */
typedef struct
{
    uint8_t width;
    uint8_t height;
    uint16_t *data;

} ST7789_FONT ;


/* ST7789 Font Variable */
#ifdef ST7789_INCLUDE_FONT_6X8
extern ST7789_FONT font6x8;
#endif

#ifdef ST7789_INCLUDE_FONT_7X10
extern ST7789_FONT font7x10;
#endif

#ifdef ST7789_INCLUDE_FONT_11X18
extern ST7789_FONT font11x18;
#endif

#ifdef ST7789_INCLUDE_FONT_16X26
extern ST7789_FONT font16x26;
#endif

#endif /* DRIVER_ST7789_ST7789_FONT_H_ */
