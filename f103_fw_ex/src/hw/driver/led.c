/*
 * led.c
 *
 *  Created on: Feb 2, 2025
 *      Author: user
 */
#include "led.h"


typedef struct
{
	GPIO_TypeDef *port;
	uint16_t      Pin;
	GPIO_PinState on_state;
	GPIO_PinState off_state;
} led_tbl_t;

led_tbl_t led_tbl[LED_MAX_CH] =
{
		{GPIOA, GPIO_PIN_11, GPIO_PIN_RESET, GPIO_PIN_SET}
};


bool ledInit(void)
{
	bool ret = true;

	  GPIO_InitTypeDef GPIO_InitStruct = {0};

	  /*Configure GPIO pin Output Level */

	  /*Configure GPIO pin : PB12 */

	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;


	  for (int i = 0; i<LED_MAX_CH; i++)
	  {
		GPIO_InitStruct.Pin = led_tbl[i].Pin;
		HAL_GPIO_Init(led_tbl[i].port, &GPIO_InitStruct);
		ledoff(i);
	  }

	return ret;
}


void ledon(uint8_t ch)
{
	if (ch >= LED_MAX_CH) return;
	HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].Pin ,led_tbl[ch].on_state);
}


void ledoff(uint8_t ch)
{
	if (ch >= LED_MAX_CH) return;
	HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].Pin ,led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
	if (ch >= LED_MAX_CH) return;
	HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].Pin);
}


