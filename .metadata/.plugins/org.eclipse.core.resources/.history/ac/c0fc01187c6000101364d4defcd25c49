/*
 * button.c
 *
 *  Created on: Jul 8, 2025
 *      Author: RND1
 */

#include "button.h"
#include "main.h"



int count = 0;
uint32_t pre_time;

void swcount(){
switch (count)
       {
      case 0 :  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);

      case 1 :
               if (millis()- pre_time >= 200)
               {
                 pre_time = millis();
                HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
               }
                  break;
       case 2 :
         if (millis()- pre_time >= 500)
         {
           pre_time = millis();
          HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
         }
                  break;
       case 3 :
         if (millis()- pre_time >= 1000)
         {
           pre_time = millis();
          HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
         }
                  break;
       case 4 :  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
             count = 0;

       }
}

void button_countup(){

if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)== GPIO_PIN_RESET )
    {
  HAL_Delay(200);
  count++;

    }

}
