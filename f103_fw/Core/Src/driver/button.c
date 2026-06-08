/*
 * button.c
 *
 *  Created on: Jul 8, 2025
 *      Author: RND1
 */

#include "button.h"
#include "main.h"



/*button 관련 전역 변수 선언 부 시작 --------------*/
  uint32_t button_count;
  uint32_t button_release_count;
  uint32_t button_state = false;
  uint32_t button_event = false;

/*button 관련 전역 변수 선언 부 끝 --------------*/


uint32_t keyPressed()
{
  uint32_t ret = false;

  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin) == GPIO_PIN_RESET)
      {
      ret = false;
      }
  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin) == GPIO_PIN_SET)
        {
      ret = true;
        }

  return ret;
}


void keyProcess(){

  if(keyPressed()){
    HAL_Delay(10);
    button_state = true;
    button_count++;
  }
  else {
    button_release_count = button_count;
    button_count = 0;
    return;
    }
}

void keyEvent(uint32_t *event){
  if(button_release_count >= 10){
    *event = true;
    button_event = true;
    button_state = false;
  }
  else return;
}




/* 초장기 테스트 할 시에 작성된 어플리케이션 소스 코드 시작 -----------------------------*/

/*
void swchose()
{
  uint32_t mode = 0;
  uint32_t button_state = 0;

  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin) == GPIO_PIN_RESET )
      {
      HAL_Delay(100);
      mode++;
      button_state = 1;
      }
  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin) == GPIO_PIN_SET )
        {
      button_state = 0;
        }

      return mode;

}


void swcount(){
  uint32_t pre_time;
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

/* 초장기 테스트 할 시에 작성된 어플리케이션 소스 코드 끝 ---------------------------------*/
