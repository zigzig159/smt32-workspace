/*
 * button.c
 *
 *  Created on: Jul 8, 2025
 *      Author: RND1
 */

#include "button.h"
#include "main.h"






uint32_t pre_time;

void swchose()
{
  uint32_t mode = 0;
  uint32_t button_state = 0;

  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin)== GPIO_PIN_RESET )
      {
      HAL_Delay(100);
      mode++;
      button_state = 1;
      }
  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin)== GPIO_PIN_SET )
        {
      button_state = 0;
        }

      return mode;

}

/*
void swcount(){
switch (mode)
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


*/
