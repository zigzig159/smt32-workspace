/*
 * ssd1306_font.h
 *
 *  Created on: Apr 24, 2025
 *      Author: RND1
 */

#ifndef DRIVER_SSD1306_FONT_H_
#define DRIVER_SSD1306_FONT_H_

#include <stdint.h>


/* SSD1306 Include Font */
#define SSD1306_INCLUDE_FONT_6X8
#define SSD1306_INCLUDE_FONT_7X10
#define SSD1306_INCLUDE_FONT_11X18
#define SSD1306_INCLUDE_FONT_16X26


/* SSD1306 Font Structure */
typedef struct
{
    uint8_t width;
    uint8_t height;
    uint16_t *data;

} SSD1306_FONT;


/* SSD1306 Font Variable */
#ifdef SSD1306_INCLUDE_FONT_6X8
extern SSD1306_FONT font6x8;
#endif

#ifdef SSD1306_INCLUDE_FONT_7X10
extern SSD1306_FONT font7x10;
#endif

#ifdef SSD1306_INCLUDE_FONT_11X18
extern SSD1306_FONT font11x18;
#endif

#ifdef SSD1306_INCLUDE_FONT_16X26
extern SSD1306_FONT font16x26;
#endif

#endif /* DRIVER_SSD1306_FONT_H_ */
