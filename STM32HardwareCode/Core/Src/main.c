/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "eth.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint8_t Machine_Mode=MANUAL;
extern Machine_info Machine_information;
extern uint32_t Cylinder_position[END_STATION];
uint8_t running_Automatic=0;
extern uint32_t Timer_counter[END_STATION];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/* USER CODE END 0 */

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
  MX_ETH_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
  Device_init();
  HAL_GPIO_EXTI_Callback(AUTOMATIC_MODE_Pin);
  //running_Automatic=Machine_Mode;
  //HAL_Delay(2000);
  //Machine_Mode=AUTOMATIC;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  switch (Machine_Mode)
	  {
	   	 case AUTOMATIC      : Run_AutomaticMode();
	                           break;

	   	 case MANUAL         : Run_ManualMode();
	  	  	  	  	           break;

	   	 case EMERGENCY_STOP : Stop_Machine();
	   	   	   	   	   	   	   break;

	   	 default             : break;
	  }

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
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure LSE Drive Capability 
  */
  HAL_PWR_EnableBkUpAccess();
  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void Device_init(void)
{
	Cylinder_position[STATION_1]=POSITION_1;
	Cylinder_position[STATION_2]=POSITION_1;
	Cylinder_position[STATION_3]=POSITION_1;
	Cylinder_position[STATION_4]=POSITION_1;
	Cylinder_position[STATION_5]=POSITION_1;
	Cylinder_position[STATION_6]=POSITION_1;

	Machine_information.Station_Information[STATION_1].Up_Movement_Duration=3*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_1].Stop_Movement_Duration=120*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_1].Down_Movement_Duration=5*TIMER_ERROR_FACTOR;

	Machine_information.Station_Information[STATION_2].Up_Movement_Duration=3*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_2].Stop_Movement_Duration=120*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_2].Down_Movement_Duration=5*TIMER_ERROR_FACTOR;

	Machine_information.Station_Information[STATION_3].Up_Movement_Duration=3*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_3].Stop_Movement_Duration=120*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_3].Down_Movement_Duration=5*TIMER_ERROR_FACTOR;

	Machine_information.Station_Information[STATION_4].Up_Movement_Duration=3*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_4].Stop_Movement_Duration=120*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_4].Down_Movement_Duration=5*TIMER_ERROR_FACTOR;

	Machine_information.Station_Information[STATION_5].Up_Movement_Duration=3*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_5].Stop_Movement_Duration=120*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_5].Down_Movement_Duration=5*TIMER_ERROR_FACTOR;

	Machine_information.Station_Information[STATION_6].Up_Movement_Duration=3*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_6].Stop_Movement_Duration=120*TIMER_ERROR_FACTOR;
	Machine_information.Station_Information[STATION_6].Down_Movement_Duration=5*TIMER_ERROR_FACTOR;


	HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);

	Timer_counter[STATION_1]=0;
	Timer_counter[STATION_1]=0;
	Timer_counter[STATION_1]=0;
	Timer_counter[STATION_1]=0;
	Timer_counter[STATION_1]=0;
	Timer_counter[STATION_1]=0;

	HAL_TIM_Base_Stop_IT(&htim1);
	HAL_TIM_Base_Stop_IT(&htim2);
	HAL_TIM_Base_Stop_IT(&htim3);
	HAL_TIM_Base_Stop_IT(&htim4);
	HAL_TIM_Base_Stop_IT(&htim5);
	HAL_TIM_Base_Stop_IT(&htim6);

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
