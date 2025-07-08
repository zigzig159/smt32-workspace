/*
 * ap.c
 *
 *  Created on: Dec 26, 2024
 *      Author: RND1
 */

#include "ap.h"


uint32_t count = 0;

void apInit(void)
{

}

void apMain(void)
{
  while(1)
  {
    if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)== GPIO_PIN_RESET )
    {
      if(count>4){
        count = 0;
        return;}
      }
      else{
      count++;
      switch (count) // a는 입력할 변수
         {
         case 1 :
                  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
                  delay(300);
                    break;
         case 2 :
           HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_1);
              delay(300);
                    break;
         case 3 :
                  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
                  delay(300);
                  count = 0;
                    break;

         }
    }






  }

}
