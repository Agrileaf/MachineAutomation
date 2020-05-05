/*
 * Automatic_Mode.c
 *
 *  Created on: Mar 26, 2020
 *      Author: Athishay
 */
/* USER CODE BEGIN Includes */
#include "main.h"
#include "gpio.h"
#include "tim.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PFP */
Pedal_s Pedal_data;
bool Unit_A1=false;
bool Unit_B1=false;
bool Unit_C1=false;
bool Unit_D1=false;
bool Unit_E1=false;
bool Unit_F1=false;

bool Step_A1=false,Step_B1=false,Step_C1=false,Step_D1=false,Step_E1=false,Step_F1=false;
bool Step_A2=false,Step_B2=false,Step_C2=false,Step_D2=false,Step_E2=false,Step_F2=false;
bool Step_A3=false,Step_B3=false,Step_C3=false,Step_D3=false,Step_E3=false,Step_F3=false;
bool Step_A4=false,Step_B4=false,Step_C4=false,Step_D4=false,Step_E4=false,Step_F4=false;
bool Step_A5=false,Step_B5=false,Step_C5=false,Step_D5=false,Step_E5=false,Step_F5=false;
bool Step_A6=false,Step_B6=false,Step_C6=false,Step_D6=false,Step_E6=false,Step_F6=false;

#define APB1_Clock 108000000 // Mhz
#define APB1_timerClock 108000000 // Mhz
#define APB1_Prescalar 108000000/1000
#define Down_time 5000 // Milli seconds
#define Up_time 5000 //Milli seconds
int Stop_time=900; // milli seconds

uint8_t APB1ARR_DownMovement=0;
uint8_t APB1ARR_UpMovement =0;
uint8_t APB1ARR_Stop=0;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void Run_AutomaticMode(void)
{

	APB1ARR_DownMovement=(APB1_Prescalar*Down_time*2)/(APB1_Clock);
	APB1ARR_UpMovement =(APB1_Prescalar*Up_time*2)/(APB1_Clock);
	APB1ARR_Stop=(APB1_Prescalar*Stop_time*2)/(APB1_Clock);
/*
	// Automatic Mode for Unit 1 starts here

	if(HAL_GPIO_ReadPin(PEDAL_A1_GPIO_Port, PEDAL_A1_Pin) && !HAL_GPIO_ReadPin(PEDAL_A2_GPIO_Port, PEDAL_A2_Pin) && Unit_A1==false)
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
		Unit_A1=true;
		Step_A1=true;
		TIM1->PSC = APB1_Prescalar;
		TIM1->ARR = APB1ARR_DownMovement;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(Step_A2)
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim1);
		Step_A2=false;
		Step_A3=true;
		TIM1->PSC = APB1_Prescalar;
		TIM1->ARR = APB1ARR_Stop;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(Step_A4 )
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
		HAL_TIM_Base_Stop_IT(&htim1);
		TIM1->PSC = APB1_Prescalar;
		TIM1->ARR = APB1ARR_UpMovement;
		HAL_TIM_Base_Start_IT(&htim1);
		Step_A5=true;
	}
	else if(Step_A6)
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim1);
		Unit_A1=false;
	    Step_A1=false;
	    Step_A2=false;
	    Step_A3=false;
	    Step_A4=false;
	    Step_A5=false;
	    Step_A6=false;
	}

	// Automatic Mode for Unit 1 Ends here
*/
	// Automatic Mode for Unit 1 starts here

	if(HAL_GPIO_ReadPin(PEDAL_A1_GPIO_Port, PEDAL_A1_Pin) && !HAL_GPIO_ReadPin(PEDAL_A2_GPIO_Port, PEDAL_A2_Pin) && Unit_A1==false)
	{
		HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);
		Unit_A1=true;
		Step_A1=true;
		TIM1->PSC = APB1_Prescalar;
		TIM1->ARR = APB1ARR_DownMovement;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(Step_A2)
	{
		HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim1);
		Step_A2=false;
		Step_A3=true;
		TIM1->PSC = APB1_Prescalar;
		TIM1->ARR = APB1ARR_Stop;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(Step_A4 )
	{
		HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);
		HAL_TIM_Base_Stop_IT(&htim1);
		TIM1->PSC = APB1_Prescalar;
		TIM1->ARR = APB1ARR_UpMovement;
		HAL_TIM_Base_Start_IT(&htim1);
		Step_A5=true;
	}
	else if(Step_A6)
	{
		HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim1);
		Unit_A1=false;
	    Step_A1=false;
	    Step_A2=false;
	    Step_A3=false;
	    Step_A4=false;
	    Step_A5=false;
	    Step_A6=false;
	}

	// Automatic Mode for Unit 1 Ends here

	// Automatic Mode for Unit 2 starts here

	if(HAL_GPIO_ReadPin(PEDAL_B1_GPIO_Port, PEDAL_B1_Pin) && !HAL_GPIO_ReadPin(PEDAL_B2_GPIO_Port, PEDAL_B2_Pin) && Unit_B1==false)
	{
		HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);
		Unit_B1=true;
		Step_B1=true;
		TIM2->PSC = APB1_Prescalar;
		TIM2->ARR = APB1ARR_DownMovement;
		HAL_TIM_Base_Start_IT(&htim2);
	}
	else if(Step_B2)
	{
		HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim2);
		Step_B2=false;
		Step_B3=true;
		TIM2->PSC = APB1_Prescalar;
		TIM2->ARR = APB1ARR_Stop;
		HAL_TIM_Base_Start_IT(&htim2);
	}
	else if(Step_B4 )
	{
		HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);
		HAL_TIM_Base_Stop_IT(&htim2);
		TIM2->PSC = APB1_Prescalar;
		TIM2->ARR = APB1ARR_UpMovement;
		HAL_TIM_Base_Start_IT(&htim2);
		Step_B5=true;
	}
	else if(Step_B6)
	{
		HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim2);
		Unit_B1=false;
	    Step_B1=false;
	    Step_B2=false;
	    Step_B3=false;
	    Step_B4=false;
	    Step_B5=false;
	    Step_B6=false;
	}

	// Automatic Mode for Unit 2 Ends here

	// Automatic Mode for Unit 3 starts here

	if(HAL_GPIO_ReadPin(PEDAL_C1_GPIO_Port, PEDAL_C1_Pin) && !HAL_GPIO_ReadPin(PEDAL_C2_GPIO_Port, PEDAL_C2_Pin) && Unit_C1==false)
	{
		HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);
		Unit_C1=true;
		Step_C1=true;
		TIM3->PSC = APB1_Prescalar;
		TIM3->ARR = APB1ARR_DownMovement;
		HAL_TIM_Base_Start_IT(&htim3);
	}
	else if(Step_C2)
	{
		HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim3);
		Step_C2=false;
		Step_C3=true;
		TIM3->PSC = APB1_Prescalar;
		TIM3->ARR = APB1ARR_Stop;
		HAL_TIM_Base_Start_IT(&htim3);
	}
	else if(Step_C4 )
	{
		HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);
		HAL_TIM_Base_Stop_IT(&htim3);
		TIM3->PSC = APB1_Prescalar;
		TIM3->ARR = APB1ARR_UpMovement;
		HAL_TIM_Base_Start_IT(&htim3);
		Step_C5=true;
	}
	else if(Step_C6)
	{
		HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim3);
		Unit_C1=false;
	    Step_C1=false;
	    Step_C2=false;
	    Step_C3=false;
	    Step_C4=false;
	    Step_C5=false;
	    Step_C6=false;
	}

	// Automatic Mode for Unit 3 Ends here

	// Automatic Mode for Unit 4 starts here

		if(HAL_GPIO_ReadPin(PEDAL_D1_GPIO_Port, PEDAL_D1_Pin) && !HAL_GPIO_ReadPin(PEDAL_D2_GPIO_Port, PEDAL_D2_Pin) && Unit_D1==false)
		{
			HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);
			Unit_D1=true;
			Step_D1=true;
			TIM4->PSC = APB1_Prescalar;
			TIM4->ARR = APB1ARR_DownMovement;
			HAL_TIM_Base_Start_IT(&htim4);
		}
		else if(Step_D2)
		{
			HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
			HAL_TIM_Base_Stop_IT(&htim4);
			Step_D2=false;
			Step_D3=true;
			TIM4->PSC = APB1_Prescalar;
			TIM4->ARR = APB1ARR_Stop;
			HAL_TIM_Base_Start_IT(&htim4);
		}
		else if(Step_D4 )
		{
			HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);
			HAL_TIM_Base_Stop_IT(&htim4);
			TIM4->PSC = APB1_Prescalar;
			TIM4->ARR = APB1ARR_UpMovement;
			HAL_TIM_Base_Start_IT(&htim4);
			Step_D5=true;
		}
		else if(Step_D6)
		{
			HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
			HAL_TIM_Base_Stop_IT(&htim4);
			Unit_D1=false;
		    Step_D1=false;
		    Step_D2=false;
		    Step_D3=false;
		    Step_D4=false;
		    Step_D5=false;
		    Step_D6=false;
		}

		// Automatic Mode for Unit 4 Ends here

		// Automatic Mode for Unit 5 starts here

		if(HAL_GPIO_ReadPin(PEDAL_E1_GPIO_Port, PEDAL_E1_Pin) && !HAL_GPIO_ReadPin(PEDAL_E2_GPIO_Port, PEDAL_E2_Pin) && Unit_E1==false)
		{
			HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);
			Unit_E1=true;
			Step_E1=true;
			TIM5->PSC = APB1_Prescalar;
			TIM5->ARR = APB1ARR_DownMovement;
			HAL_TIM_Base_Start_IT(&htim5);
		}
		else if(Step_E2)
		{
			HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
			HAL_TIM_Base_Stop_IT(&htim5);
			Step_E2=false;
			Step_E3=true;
			TIM5->PSC = APB1_Prescalar;
			TIM5->ARR = APB1ARR_Stop;
			HAL_TIM_Base_Start_IT(&htim5);
		}
		else if(Step_E4 )
		{
			HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);
			HAL_TIM_Base_Stop_IT(&htim5);
			TIM5->PSC = APB1_Prescalar;
			TIM5->ARR = APB1ARR_UpMovement;
			HAL_TIM_Base_Start_IT(&htim5);
			Step_E5=true;
		}
		else if(Step_E6)
		{
			HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
			HAL_TIM_Base_Stop_IT(&htim5);
			Unit_E1=false;
			Step_E1=false;
			Step_E2=false;
			Step_E3=false;
			Step_E4=false;
			Step_E5=false;
			Step_E6=false;
		}

		// Automatic Mode for Unit 5 Ends here

		// Automatic Mode for Unit 6 starts here

		if(HAL_GPIO_ReadPin(PEDAL_F1_GPIO_Port, PEDAL_F1_Pin) && !HAL_GPIO_ReadPin(PEDAL_F2_GPIO_Port, PEDAL_F2_Pin) && Unit_F1==false)
		{
			HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);
			Unit_F1=true;
			Step_F1=true;
			TIM6->PSC = APB1_Prescalar;
			TIM6->ARR = APB1ARR_DownMovement;
			HAL_TIM_Base_Start_IT(&htim6);
		}
		else if(Step_F2)
		{
			HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
			HAL_TIM_Base_Stop_IT(&htim6);
			Step_F2=false;
			Step_F3=true;
			TIM6->PSC = APB1_Prescalar;
			TIM6->ARR = APB1ARR_Stop;
			HAL_TIM_Base_Start_IT(&htim6);
		}
		else if(Step_F4 )
		{
			HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);
			HAL_TIM_Base_Stop_IT(&htim6);
			TIM6->PSC = APB1_Prescalar;
			TIM6->ARR = APB1ARR_UpMovement;
			HAL_TIM_Base_Start_IT(&htim6);
			Step_F5=true;
		}
		else if(Step_F6)
		{
			HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
			HAL_TIM_Base_Stop_IT(&htim6);
			Unit_F1=false;
			Step_F1=false;
			Step_F2=false;
			Step_F3=false;
			Step_F4=false;
			Step_F5=false;
			Step_F6=false;
		}

		// Automatic Mode for Unit 6 Ends here
}





void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM1)
	{
		if(Step_A1)
		{
			Step_A2=true;
		}
		else if(Step_A3)
		{
			Step_A4=true;
		}
		else if(Step_A5)
		{
			Step_A6=true;
		}
	}

	if(htim->Instance == TIM2)
	{
		if(Step_B1)
		{
			Step_B2=true;
		}
		else if(Step_B3)
		{
			Step_B4=true;
		}
		else if(Step_B5)
		{
			Step_B6=true;
		}

	}

	if(htim->Instance == TIM3)
	{
		if(Step_C1)
		{
			Step_C2=true;
		}
		else if(Step_C3)
		{
			Step_C4=true;
		}
		else if(Step_C5)
		{
			Step_C6=true;
		}

	}

	if(htim->Instance == TIM4)
	{
		if(Step_D1)
		{
			Step_D2=true;
		}
		else if(Step_D3)
		{
			Step_D4=true;
		}
		else if(Step_D5)
		{
			Step_D6=true;
		}
	}

	if(htim->Instance == TIM5)
	{
		if(Step_E1)
		{
		    Step_E2=true;
		}
		else if(Step_E3)
		{
			Step_E4=true;
		}
		else if(Step_E5)
		{
			Step_E6=true;
		}
	}

	if(htim->Instance == TIM6)
	{
		if(Step_F1)
		{
			Step_F2=true;
		}
		else if(Step_F3)
		{
			Step_F4=true;
		}
		else if(Step_F5)
		{
			Step_F6=true;
		}
	}
}


void Stop_Machine(void)
{
	Unit_A1=false;
	Unit_B1=false;
	Unit_C1=false;
	Unit_D1=false;
	Unit_E1=false;
	Unit_F1=false;

	Step_A1=false,Step_B1=false,Step_C1=false,Step_D1=false,Step_E1=false,Step_F1=false;
	Step_A2=false,Step_B2=false,Step_C2=false,Step_D2=false,Step_E2=false,Step_F2=false;
	Step_A3=false,Step_B3=false,Step_C3=false,Step_D3=false,Step_E3=false,Step_F3=false;
	Step_A4=false,Step_B4=false,Step_C4=false,Step_D4=false,Step_E4=false,Step_F4=false;
	Step_A5=false,Step_B5=false,Step_C5=false,Step_D5=false,Step_E5=false,Step_F5=false;
	Step_A6=false,Step_B6=false,Step_C6=false,Step_D6=false,Step_E6=false,Step_F6=false;

	HAL_GPIO_WritePin(GPIOE, MOTOR_1_Pin|MOTOR_2_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_RESET);

	HAL_TIM_Base_Stop_IT(&htim1);
	HAL_TIM_Base_Stop_IT(&htim2);
	HAL_TIM_Base_Stop_IT(&htim3);
	HAL_TIM_Base_Stop_IT(&htim4);
	HAL_TIM_Base_Stop_IT(&htim5);
	HAL_TIM_Base_Stop_IT(&htim6);

	while( HAL_GPIO_ReadPin(EMERGENCY_STOP_GPIO_Port, EMERGENCY_STOP_Pin))
	{
		HAL_GPIO_WritePin(ALARM_GPIO_Port, ALARM_Pin, GPIO_PIN_SET);
		HAL_Delay(200);
		HAL_GPIO_WritePin(ALARM_GPIO_Port, ALARM_Pin, GPIO_PIN_RESET);
		HAL_Delay(200);

	}


}
/* USER CODE END 0 */

