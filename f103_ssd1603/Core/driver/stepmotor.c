/*
 * stepmotor.c
 *
 *  Created on: May 21, 2025
 *      Author: RND1
 */

#include "stepmotor.h"



uint8_t step_sequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

// 스텝핀 제어 함수
void set_step(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, a);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, b);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, c);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, d);
}

void step_motor_forward(uint16_t steps) {
  for (uint16_t i = 0; i < steps; i++) {
    for (uint8_t j = 0; j < 8; j++) {
      set_step(step_sequence[j][0], step_sequence[j][1],
               step_sequence[j][2], step_sequence[j][3]);
      HAL_Delay(1); // 속도 조절
    }
  }
}
