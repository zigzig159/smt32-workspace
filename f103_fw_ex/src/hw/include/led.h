/*
 * led.h
 *
 *  Created on: Feb 2, 2025
 *      Author: user
 */

#ifndef SRC_HW_INCLUDE_LED_H_
#define SRC_HW_INCLUDE_LED_H_

#include "hw_def.h"


#ifdef _USE_HW_LED

#define LED_MAX_CH           HW_LED_MAX_CH



bool ledInit(void);
void ledon(uint8_t ch);
void ledoff(uint8_t ch);
void ledToggle(uint8_t ch);

#endif

#endif /* SRC_HW_INCLUDE_LED_H_ */
