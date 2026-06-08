/*
 * button.h
 *
 *  Created on: Jul 8, 2025
 *      Author: RND1
 */

#ifndef __BUTTON_H__
#define __BUTTON_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <stdint.h>

typedef enum
{
    BUTTON_BT1 = 0,
    BUTTON_BT2,
    BUTTON_BT3,

    BUTTON_MAX
} button_id_t;

typedef enum
{
    BUTTON_EVENT_NONE = 0,
    BUTTON_EVENT_PRESS,
    BUTTON_EVENT_RELEASE
} button_event_t;

void button_init(void);
void button_process(void);

uint8_t button_is_pressed(button_id_t id);
button_event_t button_get_event(button_id_t id);

#ifdef __cplusplus
}
#endif

#endif
