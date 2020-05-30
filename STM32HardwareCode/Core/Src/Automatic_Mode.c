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
#include "Automatic_Mode.h"

/* USER CODE END Includes */

/* USER CODE BEGIN PFP */


#define OPERATION_1 0
#define OPERATION_2 1

Machine_info Machine_information={0};
uint32_t Cylinder_position[END_STATION]={0};
uint32_t Timer_counter[END_STATION]={0};
uint32_t Timer_timeout[END_STATION]={0};
extern uint8_t running_Automatic;



/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


void Run_AutomaticMode(void)
{
	/* Automatic Mode for Unit 1 starts here */

	for(int Id=0;Id<6;Id++)
	{
		if(Cylinder_position[Id] != SET_OFF)
		{
			Start_Machine(Id);
			//running_Automatic=AUTOMATIC;
		}
	}
    /* Automatic Mode for Unit 1 ends here */
}


void Start_Machine(uint32_t Id)
{
	switch(Cylinder_position[Id])
		{

		  case POSITION_1:{
//			  	  	  	   if(Get_Pedal_State(Id,FORWARD)==GPIO_PIN_RESET)
//			  			    {
//			  	  	  		          Timer_counter[Id]=0;
//			  	  	  		          Stop_APBx_Timer_Interrupt(Id);
//			  			  	  	  	  Set_Cylinder_Direction(Id,FORWARD);
//			  			  	  	  	  Set_Cylinder_Position(Id,POSITION_2);
//			  			  	  	      Start_APBx_Timer_Interrupt(Id,Machine_information.Station_Information[Id].Down_Movement_Duration);
//			  			  	}

			  	  	  	  	if(Get_Pedal_State(Id,FORWARD)==GPIO_PIN_RESET)
			  	  	  	  	{
			  	  	  	              Set_Cylinder_Direction(Id,FORWARD);
			  	  	  	  			  Start_APBx_Timer_Interrupt(Id,Machine_information.Station_Information[Id].Down_Movement_Duration);

			  	  	  	  			  if(Timer_counter[Id]>=Timer_timeout[Id])
			  	  	  	  			  {
			  	  	  	  				  Set_Cylinder_Position(Id,POSITION_2);
			  	  	  	  			  }
			  	  	  	  	}
			  	  	  	    else if(Get_Pedal_State(Id,REVERSE)==GPIO_PIN_RESET)
			  	  	  	  	{
			  	  	  	  			  if(Timer_counter[Id]>0)
			  	  	  	  			  {
			  	  	  	  				  Start_APBx_Timer_Interrupt(Id,Machine_information.Station_Information[Id].Down_Movement_Duration);
			  	  	  	  				  Set_Cylinder_Direction(Id,REVERSE);
			  	  	  	  				  if(Timer_counter[Id]>=Timer_timeout[Id])
			  	  	  	  				  {
			  	  	  	  					  Set_Cylinder_Position(Id,POSITION_1);
			  	  	  	  				  }
			  	  	  	  			  }
			  	  	  	  			  else
			  	  	  	  			  {
			  	  	  	  				  Set_Cylinder_Direction(Id,STOP);
			  	  	  	  			  }
			  	  	  	  	}
			  	  	  	  	else if(Get_Pedal_State(Id,FORWARD)==GPIO_PIN_SET || Get_Pedal_State(Id,REVERSE)==GPIO_PIN_SET)
			  	  	  	  	{
			  	  	  	  			  Stop_APBx_Timer_Interrupt(Id);
			  	  	  	  			  Set_Cylinder_Direction(Id,STOP);
			  	  	  	  	}
			  	  	  	   }
		  	  	  	  	  	break;

		  case POSITION_2:  if(Timer_counter[Id]>=Timer_timeout[Id])
		    				{
			  	  	  	  	  	Stop_APBx_Timer_Interrupt(Id);
		    					Set_Cylinder_Direction(Id,STOP);
		    					Set_Cylinder_Position(Id,POSITION_3);
		    					Start_APBx_Timer_Interrupt(Id,Machine_information.Station_Information[Id].Stop_Movement_Duration);
		    				}
		  	  	  	  	  	break;

		  case POSITION_3: if(Timer_counter[Id]>=Timer_timeout[Id])
		  	  	  	  	   {
			  	  	  	  	  	Stop_APBx_Timer_Interrupt(Id);
			  	  	  	  	  	Start_APBx_Timer_Interrupt(Id,Machine_information.Station_Information[Id].Up_Movement_Duration);
								Set_Cylinder_Position(Id,POSITION_4);
								Set_Cylinder_Direction(Id,REVERSE);
		  	  	  	  	   }
		  	  	  	  	  	break;

		  case POSITION_4: if(Timer_counter[Id]>=Timer_timeout[Id])
		  	  	  	  	   {
			  	  	  	  	  	Stop_APBx_Timer_Interrupt(Id);
		    					Set_Cylinder_Direction(Id,STOP);
		    					Set_Cylinder_Position(Id,POSITION_1);
		  	  	  	  	   }
		  	  	  	  	   break;

		  default         : break;
		}

}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM1)
	{
		if(Cylinder_position[STATION_1]==POSITION_1)
		{
			if(Machine_information.Station_Information[STATION_1].Cylinder_direction==FORWARD)
			{
				Timer_counter[STATION_1]++;
			}
			else if(Machine_information.Station_Information[STATION_1].Cylinder_direction==REVERSE)
			{
				if(Timer_counter[STATION_1]>0)
				  Timer_counter[STATION_1]--;
			}
			else
			{

			}
		}
		else
		{
			Timer_counter[STATION_1]++;
		}
	}

	if(htim->Instance == TIM2)
	{
		if(Cylinder_position[STATION_2]==POSITION_1)
		{
			if(Machine_information.Station_Information[STATION_2].Cylinder_direction==FORWARD)
			{
				Timer_counter[STATION_2]++;
			}
			else if(Machine_information.Station_Information[STATION_2].Cylinder_direction==REVERSE)
			{
				if(Timer_counter[STATION_2]>0)
				  Timer_counter[STATION_2]--;
			}
			else
			{

			}
		}
		else
		{
			Timer_counter[STATION_2]++;
		}
	}

	if(htim->Instance == TIM3)
	{
		if(Cylinder_position[STATION_3]==POSITION_1)
		{
			if(Machine_information.Station_Information[STATION_3].Cylinder_direction==FORWARD)
			{
				Timer_counter[STATION_3]++;
			}
			else if(Machine_information.Station_Information[STATION_3].Cylinder_direction==REVERSE)
			{
				if(Timer_counter[STATION_3]>0)
				  Timer_counter[STATION_3]--;
			}
			else
			{

			}
		}
		else
		{
			Timer_counter[STATION_3]++;
		}
	}

	if(htim->Instance == TIM4)
	{
		if(Cylinder_position[STATION_4]==POSITION_1)
		{
			if(Machine_information.Station_Information[STATION_4].Cylinder_direction==FORWARD)
			{
				Timer_counter[STATION_4]++;
			}
			else if(Machine_information.Station_Information[STATION_4].Cylinder_direction==REVERSE)
			{
				if(Timer_counter[STATION_4]>0)
				  Timer_counter[STATION_4]--;
			}
			else
			{

			}
		}
		else
		{
			Timer_counter[STATION_4]++;
		}
	}

	if(htim->Instance == TIM5)
	{
		if(Cylinder_position[STATION_5]==POSITION_1)
		{
			if(Machine_information.Station_Information[STATION_5].Cylinder_direction==FORWARD)
			{
				Timer_counter[STATION_5]++;
			}
			else if(Machine_information.Station_Information[STATION_5].Cylinder_direction==REVERSE)
			{
				if(Timer_counter[STATION_5]>0)
				  Timer_counter[STATION_5]--;
			}
			else
			{

			}
		}
		else
		{
			Timer_counter[STATION_5]++;
		}
	}

	if(htim->Instance == TIM6)
	{
		if(Cylinder_position[STATION_6]==POSITION_1)
		{
			if(Machine_information.Station_Information[STATION_6].Cylinder_direction==FORWARD)
			{
				Timer_counter[STATION_6]++;
			}
			else if(Machine_information.Station_Information[STATION_6].Cylinder_direction==REVERSE)
			{
				if(Timer_counter[STATION_6]>0)
				  Timer_counter[STATION_6]--;
			}
			else
			{

			}
		}
		else
		{
			Timer_counter[STATION_6]++;
		}
	}
}


void Stop_Machine(void)
{

	Device_init();

	while(1)
	{
		HAL_GPIO_WritePin(ALARM_GPIO_Port, ALARM_Pin, GPIO_PIN_SET);
		HAL_Delay(200);
		HAL_GPIO_WritePin(ALARM_GPIO_Port, ALARM_Pin, GPIO_PIN_RESET);
		HAL_Delay(200);
	}


}




uint32_t Get_Cylinder_Position(Station_Id Id)
{
	uint32_t temp;

	temp=Cylinder_position[Id];

	return temp;
}

void Set_Cylinder_Position(Station_Id Id,uint32_t Position)
{

	Cylinder_position[Id]=Position;
}



uint32_t Get_Cylinder_Position_hold_Duration(Station_Id Id,Cylinder_Movement Direction)
{
	uint32_t duration;

	if(Direction==FORWARD)
	{
		duration=(Machine_information.Station_Information[Id].Down_Movement_Duration)*(TIMER_ERROR_FACTOR);
	}
	else if(Direction==REVERSE)
	{
		duration=(Machine_information.Station_Information[Id].Up_Movement_Duration)*(TIMER_ERROR_FACTOR);
	}
	else if(Direction==STOP)
	{
		duration=(Machine_information.Station_Information[Id].Stop_Movement_Duration)*(TIMER_ERROR_FACTOR);
	}
	else
	{

	}
	return duration;
}




void Start_APBx_Timer_Interrupt(Station_Id Id,uint32_t Duration)
{
	Timer_timeout[Id]=Duration;

	switch(Id)
	{
		case STATION_1: {TIM1->PSC = APB1_CLOCK_FREQ;
						 TIM1->ARR = TIMER_CALLBACK_TIMEOUT;
						 HAL_TIM_Base_Start_IT(&htim1);}
						 break;

		case STATION_2: {TIM2->PSC = APB1_CLOCK_FREQ;
						 TIM2->ARR = TIMER_CALLBACK_TIMEOUT;
						 HAL_TIM_Base_Start_IT(&htim2);}
						 break;

		case STATION_3: {TIM3->PSC = APB1_CLOCK_FREQ;
						 TIM3->ARR = TIMER_CALLBACK_TIMEOUT;
						 HAL_TIM_Base_Start_IT(&htim3);}
						 break;

		case STATION_4: {TIM4->PSC = APB1_CLOCK_FREQ;
						 TIM4->ARR = TIMER_CALLBACK_TIMEOUT;
						 HAL_TIM_Base_Start_IT(&htim4);}
						 break;

		case STATION_5: {TIM5->PSC = APB1_CLOCK_FREQ;
						 TIM5->ARR = TIMER_CALLBACK_TIMEOUT;
						 HAL_TIM_Base_Start_IT(&htim5);}
						 break;

		case STATION_6: {TIM6->PSC = APB1_CLOCK_FREQ;
						 TIM6->ARR = TIMER_CALLBACK_TIMEOUT;
						 HAL_TIM_Base_Start_IT(&htim6);}
						 break;

		default       :  break;
	}
}



void Stop_APBx_Timer_Interrupt(Station_Id Id)
{

	if(Cylinder_position[Id] != POSITION_1)
	{
		Timer_counter[Id]=0;
	}
	switch(Id)
		{
			case STATION_1: HAL_TIM_Base_Stop_IT(&htim1);
							break;

			case STATION_2: HAL_TIM_Base_Stop_IT(&htim2);
							break;

			case STATION_3: HAL_TIM_Base_Stop_IT(&htim3);
							break;

			case STATION_4: HAL_TIM_Base_Stop_IT(&htim4);
							break;

			case STATION_5: HAL_TIM_Base_Stop_IT(&htim5);
							break;

			case STATION_6: HAL_TIM_Base_Stop_IT(&htim6);
							break;

			default       : break;
		}
}



/* USER CODE END 0 */

