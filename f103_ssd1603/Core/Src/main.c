/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ssd1306.h"
#include "bme280.h"
#include "stepmotor.h"
#include "hx711.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
hx711_t sensor;
BME280_Data_t BME280;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Sensor_Init(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
char buf[32];
/* USER CODE END 0 */
void Sensor_Init(void)
{

  //Init structure definition section
  BME280_Init_t BME280_InitStruct = {0};

  //Reset section
  Reset_BME280();

  /*============================ *BME280 Initialization* ============================*/

  BME280_InitStruct.Filter = FILTER_8;            //FILTER_X
  BME280_InitStruct.Mode = BME280_NORMAL_MODE;      //SLEEP, NORMAL or FORCE can be written
  BME280_InitStruct.OverSampling_H = OVERSAMPLING_16;   //OVERSAMPLING_X
  BME280_InitStruct.OverSampling_P = OVERSAMPLING_16;   //OVERSAMPLING_X
  BME280_InitStruct.OverSampling_T = OVERSAMPLING_16;   //OVERSAMPLING_X
  BME280_InitStruct.SPI_EnOrDıs = SPI3_W_DISABLE;     //SPI3_W_DISABLE or SPI3_W_ENABLE can be written
  BME280_InitStruct.T_StandBy = T_SB_250;         //T_SB_X

  BME280Init(BME280_InitStruct);
}
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  MX_ADC1_Init();

  /* USER CODE BEGIN 2 */
  ssd1306_init();

  ssd1306_set_cursor(5, 0);

  ssd1306_write_string(font6x8, "Rotech ssd1603");
  ssd1306_enter();
  ssd1306_set_cursor(5, 8);
  ssd1306_write_string(font6x8, "load cell test");

  ssd1306_set_cursor(5, 24);
  ssd1306_write_string(font6x8, "         ");

  ssd1306_set_cursor(5, 40);
  ssd1306_write_string(font11x18, "            ");
  ssd1306_update_screen();
  /* USER CODE END 2 */
uint32_t count = 0;
float weight = 0;
int32_t low = 0;

  hx711_init(&sensor, GPIOA, GPIO_PIN_8, GPIOB, GPIO_PIN_8);
  //hx711_tare(&sensor, 10);
  hx711_calibration(&sensor,8701460,8748208,354.5);
  //hx711_coef_set(&sensor, 467.56); // read afer calibration


  Sensor_Init();

  uint32_t pre_time;
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    pre_time = HAL_GetTick();
    BME280Calculation(&BME280);

    weight = hx711_weight(&sensor,1);
    snprintf(buf, sizeof(buf), "  %4.2f kg", weight);

    ssd1306_set_cursor(5, 40);
    ssd1306_write_string(font11x18, buf);

    count = HAL_GetTick()- pre_time;
    snprintf(buf, sizeof(buf), "FPS(ms) : %d", (int)count);
    ssd1306_set_cursor(5, 24);
    ssd1306_write_string(font6x8, buf);
    ssd1306_update_screen();





    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
uint32_t millis(void)
{
  return HAL_GetTick();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

