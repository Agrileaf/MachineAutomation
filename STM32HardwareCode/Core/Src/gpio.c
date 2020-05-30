/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
extern Machine_info Machine_information;
extern uint32_t Cylinder_position[END_STATION];
uint8_t Machine_Mode;

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, ALARM_Pin|CYLINDER_1F_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, MOTOR_1_Pin|MOTOR_2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, CYLINDER_6R_Pin|CYLINDER_6F_Pin|CYLINDER_5R_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, CYLINDER_5F_Pin|CYLINDER_4R_Pin|CYLINDER_4F_Pin|CYLINDER_3R_Pin 
                          |CYLINDER_3F_Pin|CYLINDER_2R_Pin|CYLINDER_2F_Pin|CYLINDER_1R_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = EMERGENCY_STOP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(EMERGENCY_STOP_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = AUTOMATIC_MODE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(AUTOMATIC_MODE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin */
  GPIO_InitStruct.Pin = ALARM_Pin|USB_PowerSwitchOn_Pin|CYLINDER_1F_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PEPin PEPin */
  GPIO_InitStruct.Pin = MOTOR_1_Pin|MOTOR_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin 
                           PEPin PEPin */
  GPIO_InitStruct.Pin = PEDAL_A1_Pin|PEDAL_A2_Pin|PEDAL_B1_Pin|PEDAL_B2_Pin 
                          |PEDAL_C1_Pin|PEDAL_C2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = PEDAL_F2_Pin|PEDAL_F1_Pin|PEDAL_E2_Pin|PEDAL_E1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin */
  GPIO_InitStruct.Pin = PEDAL_D1_Pin|PEDAL_D2_Pin|USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = CYLINDER_6R_Pin|CYLINDER_6F_Pin|CYLINDER_5R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin 
                           PDPin PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = CYLINDER_5F_Pin|CYLINDER_4R_Pin|CYLINDER_4F_Pin|CYLINDER_3R_Pin 
                          |CYLINDER_3F_Pin|CYLINDER_2R_Pin|CYLINDER_2F_Pin|CYLINDER_1R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */
void Set_Cylinder_Direction(Station_Id Id,Cylinder_Movement Action)
{
	switch(Id)
	{
	case STATION_1 : Cylinder1_Action(Action);break;
	case STATION_2 : Cylinder2_Action(Action);break;
	case STATION_3 : Cylinder3_Action(Action);break;
	case STATION_4 : Cylinder4_Action(Action);break;
	case STATION_5 : Cylinder5_Action(Action);break;
	case STATION_6 : Cylinder6_Action(Action);break;
	default        : break;
	}
}

void Cylinder1_Action(Cylinder_Movement Action)
{
	switch(Action)
	{
		case FORWARD:  {
						HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
					   }
					   break;

		case REVERSE:  {
					    HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_RESET);
					    HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
					   }
					   break;

		case STOP:     {
					    HAL_GPIO_WritePin(CYLINDER_1R_GPIO_Port, CYLINDER_1R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_1F_GPIO_Port, CYLINDER_1F_Pin, GPIO_PIN_SET);
					    if(Machine_Mode==AUTOMATIC)
					    {
					    	if(Cylinder_position[STATION_2]!=POSITION_2 && Cylinder_position[STATION_2]!=POSITION_4 && Cylinder_position[STATION_3]!=POSITION_2 && Cylinder_position[STATION_3]!=POSITION_4 &&  Get_Pedal_State(STATION_2,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_2,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_3,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_3,REVERSE)!=GPIO_PIN_RESET)
					    	{HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);}
					    }
					    else if(Machine_Mode==MANUAL)
					    {
					    	if(Get_Pedal_State(STATION_2,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_2,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_3,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_3,REVERSE)!=GPIO_PIN_RESET)
					    	{HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);}
					    }
					    else
					    {

					    }
					   }
					   break;

		default    :   break;
	}
}

void Cylinder2_Action(Cylinder_Movement Action)
{
	switch(Action)
	{
		case FORWARD:  {
						HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
					   }
					   break;

		case REVERSE:  {
					    HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_RESET);
					    HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
					   }
					   break;

		case STOP:     {
					    HAL_GPIO_WritePin(CYLINDER_2R_GPIO_Port, CYLINDER_2R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_2F_GPIO_Port, CYLINDER_2F_Pin, GPIO_PIN_SET);
					    if(Machine_Mode==AUTOMATIC)
					  	{
					    	  if(Cylinder_position[STATION_1]!=POSITION_2 && Cylinder_position[STATION_1]!=POSITION_4 && Cylinder_position[STATION_3]!=POSITION_2 && Cylinder_position[STATION_3]!=POSITION_4 && Get_Pedal_State(STATION_1,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_1,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_3,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_3,REVERSE)!=GPIO_PIN_RESET)
					    	  {HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);}
					    }
					  	else if(Machine_Mode==MANUAL)
					  	{
					  		if(Get_Pedal_State(STATION_1,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_1,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_3,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_3,REVERSE)!=GPIO_PIN_RESET)
					  		{HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);}
					  	}
					  	else
					  	{

					  	}
						}
					   break;

		default    :   break;
	}
}

void Cylinder3_Action(Cylinder_Movement Action)
{
	switch(Action)
	{
		case FORWARD:  {
						HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
					   }
					   break;
		case REVERSE:  {
					    HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_RESET);
					    HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_RESET);
					   }
					   break;
		case STOP:     {
					    HAL_GPIO_WritePin(CYLINDER_3R_GPIO_Port, CYLINDER_3R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_3F_GPIO_Port, CYLINDER_3F_Pin, GPIO_PIN_SET);
					    if(Machine_Mode==AUTOMATIC)
					  	{
						    if(Get_Cylinder_Position(STATION_2)!=POSITION_2 && Get_Cylinder_Position(STATION_2)!=POSITION_4 && Get_Cylinder_Position(STATION_1)!=POSITION_2 && Get_Cylinder_Position(STATION_1)!=POSITION_4 && Get_Pedal_State(STATION_1,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_1,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_2,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_2,REVERSE)!=GPIO_PIN_RESET)
						    {HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);}
					    }
					  	else if(Machine_Mode==MANUAL)
					  	{
					  		if(Get_Pedal_State(STATION_1,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_1,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_2,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_2,REVERSE)!=GPIO_PIN_RESET)
					  		{HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, GPIO_PIN_SET);}
					    }
					  	else
					  	{

					  	}
						}
					   break;
		default    :   break;
	}
}

void Cylinder4_Action(Cylinder_Movement Action)
{
	switch(Action)
	{
		case FORWARD:  {
						HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
					   }
					   break;
		case REVERSE:  {
					    HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_RESET);
					    HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
					   }
					   break;
		case STOP:     {
					    HAL_GPIO_WritePin(CYLINDER_4R_GPIO_Port, CYLINDER_4R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_4F_GPIO_Port, CYLINDER_4F_Pin, GPIO_PIN_SET);
					    if(Machine_Mode==AUTOMATIC)
					    {
						    if(Get_Cylinder_Position(STATION_5)!=POSITION_2 && Get_Cylinder_Position(STATION_5)!=POSITION_4 && Get_Cylinder_Position(STATION_6)!=POSITION_2 && Get_Cylinder_Position(STATION_6)!=POSITION_4 && Get_Pedal_State(STATION_5,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_5,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_6,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_6,REVERSE)!=GPIO_PIN_RESET)
						    {HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);}
					    }
					    else if(Machine_Mode==MANUAL)
					    {
					  		if(Get_Pedal_State(STATION_5,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_5,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_6,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_6,REVERSE)!=GPIO_PIN_RESET)
					  		{HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);}
					    }
					    else
					    {

					    }
					   }
					   break;
		default    :   break;
	}
}

void Cylinder5_Action(Cylinder_Movement Action)
{
	switch(Action)
	{
		case FORWARD:  {
						HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
					   }
					   break;
		case REVERSE:  {
					    HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_RESET);
					    HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
					   }
					   break;
		case STOP:     {
					    HAL_GPIO_WritePin(CYLINDER_5R_GPIO_Port, CYLINDER_5R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_5F_GPIO_Port, CYLINDER_5F_Pin, GPIO_PIN_SET);
					    if(Machine_Mode==AUTOMATIC)
					    {
						    if(Get_Cylinder_Position(STATION_4)!=POSITION_2 && Get_Cylinder_Position(STATION_4)!=POSITION_4 && Get_Cylinder_Position(STATION_6)!=POSITION_2 && Get_Cylinder_Position(STATION_6)!=POSITION_4 && Get_Pedal_State(STATION_4,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_4,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_6,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_6,REVERSE)!=GPIO_PIN_RESET)
						    {HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);}
					    }
					    else if(Machine_Mode==MANUAL)
					    {
					  		if(Get_Pedal_State(STATION_4,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_4,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_6,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_6,REVERSE)!=GPIO_PIN_RESET)
					  		{HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);}
					    }
					    else
					    {

					    }
					   }
					   break;
		default    :   break;
	}
}

void Cylinder6_Action(Cylinder_Movement Action)
{
	switch(Action)
	{
		case FORWARD:  {
						HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
					   }
					   break;
		case REVERSE:  {
					    HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_RESET);
					    HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_RESET);
					   }
					   break;
		case STOP:     {
					    HAL_GPIO_WritePin(CYLINDER_6R_GPIO_Port, CYLINDER_6R_Pin, GPIO_PIN_SET);
					    HAL_GPIO_WritePin(CYLINDER_6F_GPIO_Port, CYLINDER_6F_Pin, GPIO_PIN_SET);
					    if(Machine_Mode==AUTOMATIC)
					    {
						    if(Get_Cylinder_Position(STATION_4)!=POSITION_2 && Get_Cylinder_Position(STATION_4)!=POSITION_4 && Get_Cylinder_Position(STATION_5)!=POSITION_2 && Get_Cylinder_Position(STATION_5)!=POSITION_4 && Get_Pedal_State(STATION_4,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_4,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_5,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_5,REVERSE)!=GPIO_PIN_RESET)
						    {HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);}
					    }
					    else if(Machine_Mode==MANUAL)
						{
						    if(Get_Pedal_State(STATION_4,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_4,REVERSE)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_5,FORWARD)!=GPIO_PIN_RESET && Get_Pedal_State(STATION_5,REVERSE)!=GPIO_PIN_RESET)
							{HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, GPIO_PIN_SET);}
					    }
					    else
					    {

					    }
					   }
					   break;
		default    :   break;
	}
}

GPIO_PinState Get_Pedal_State(Station_Id Id,Cylinder_Movement Direction)
{
	GPIO_PinState status;
	Machine_information.Station_Information[Id].Cylinder_direction=Direction;

	switch(Id)
	{
	  case STATION_1: {if(Direction==FORWARD)
		  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_A1_GPIO_Port, PEDAL_A1_Pin);
	  	  	  	  	  else if(Direction==REVERSE)
	  	  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_A2_GPIO_Port, PEDAL_A2_Pin);
	  	  	  	  	  break;}

	  case STATION_2: {if(Direction==FORWARD)
		  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_B1_GPIO_Port, PEDAL_B1_Pin);
	  	  	  	  	  else if(Direction==REVERSE)
	  	  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_B2_GPIO_Port, PEDAL_B2_Pin);
	  	  	  	  	  break;}

	  case STATION_3: {if(Direction==FORWARD)
		  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_C1_GPIO_Port, PEDAL_C1_Pin);
	  	  	  	  	  else if(Direction==REVERSE)
	  	  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_C2_GPIO_Port, PEDAL_C2_Pin);
	  	  	  	  	  break;}

	  case STATION_4: {if(Direction==FORWARD)
		  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_D1_GPIO_Port, PEDAL_D1_Pin);
	  	  	  	  	  else if(Direction==REVERSE)
	  	  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_D2_GPIO_Port, PEDAL_D2_Pin);
	  	  	  	  	  break;}

	  case STATION_5: {if(Direction==FORWARD)
		  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_E1_GPIO_Port, PEDAL_E1_Pin);
	  	  	  	  	  else if(Direction==REVERSE)
	  	  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_E2_GPIO_Port, PEDAL_E2_Pin);
	  	  	  	  	  break;}

	  case STATION_6: {if(Direction==FORWARD)
		  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_F1_GPIO_Port, PEDAL_F1_Pin);
	  	  	  	  	  else if(Direction==REVERSE)
	  	  	  	  	  status=HAL_GPIO_ReadPin(PEDAL_F2_GPIO_Port, PEDAL_F2_Pin);
	  	  	  	  	  break;}

	  default       : break;
	}

	return status;
}






/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
