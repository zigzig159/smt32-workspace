/*
 * stepmotor.h
 *
 *  Created on: May 21, 2025
 *      Author: RND1
 */

#ifndef DRIVER_STEPMOTOR_H_
#define DRIVER_STEPMOTOR_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>

void set_step(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
void step_motor_forward(uint16_t steps);

#endif /* DRIVER_STEPMOTOR_H_ */
