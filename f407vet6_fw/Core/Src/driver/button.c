/*
 * button.c
 *
 *  Created on: Jul 8, 2025
 *      Author: RND1
 */
/*-----------버튼 드라이버 코드 ---------*/


#include "button.h"
#include "gpio.h"

#define BUTTON_DEBOUNCE_TIME_MS    30

/*button 구조체 및 배열 선언*/
typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;

    uint8_t current_state;
    uint8_t previous_state;

    uint32_t debounce_tick;

    button_event_t event;

} button_t;

static button_t button_tbl[BUTTON_MAX] =
{
    [BUTTON_BT1] =
    {
        .port = GPIOC,
        .pin = GPIO_PIN_0,
    },

    [BUTTON_BT2] =
    {
        .port = GPIOC,
        .pin = GPIO_PIN_2,
    },

    [BUTTON_BT3] =
    {
        .port = GPIOC,
        .pin = GPIO_PIN_3,
    }
};

static uint8_t button_read(button_t *btn)
{
    return (HAL_GPIO_ReadPin(btn->port, btn->pin)
            == GPIO_PIN_RESET);
}

/*버튼 초기화 */
void button_init(void)
{
    uint8_t i;

    for(i = 0; i < BUTTON_MAX; i++)
    {
        button_tbl[i].current_state =
                button_read(&button_tbl[i]);

        button_tbl[i].previous_state =
                button_tbl[i].current_state;

        button_tbl[i].event =
                BUTTON_EVENT_NONE;
    }
}

/*버튼 프로세스 메인 함수*/
void button_process(void)
{
    uint8_t i;

    uint32_t tick = HAL_GetTick();

    for(i = 0; i < BUTTON_MAX; i++)
    {
        button_t *btn = &button_tbl[i];

        uint8_t state = button_read(btn);

        if(state != btn->previous_state)
        {
            btn->debounce_tick = tick;
            btn->previous_state = state;
        }

        if((tick - btn->debounce_tick)
                >= BUTTON_DEBOUNCE_TIME_MS)
        {
            if(state != btn->current_state)
            {
                btn->current_state = state;

                if(state)
                {
                    btn->event =
                            BUTTON_EVENT_PRESS;
                }
                else
                {
                    btn->event =
                            BUTTON_EVENT_RELEASE;
                }
            }
        }
    }
}

uint8_t button_is_pressed(button_id_t id)
{
    return button_tbl[id].current_state;
}

button_event_t button_get_event(button_id_t id)
{
    button_event_t event;

    event = button_tbl[id].event;

    button_tbl[id].event =
            BUTTON_EVENT_NONE;

    return event;
}
