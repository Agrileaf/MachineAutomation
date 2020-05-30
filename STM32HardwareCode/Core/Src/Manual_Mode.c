/*
 * Manual_Mode.c
 *
 *  Created on: Mar 26, 2020
 *      Author: Athishay
 *
 *
 */
/* USER CODE BEGIN Includes */
#include "main.h"
#include "gpio.h"
#include "Manual_Mode.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PFP */
extern uint8_t running_Automatic;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void Run_ManualMode(void)
{
	//if(running_Automatic==AUTOMATIC)
	//{
		//Device_init();
		//running_Automatic=MANUAL;
	//}
  	for(int Id=STATION_1;Id<END_STATION;Id++)
  	{
  		Start_Manual_Operation(Id);
  	}
}

void Start_Manual_Operation(Station_Id Id)
{
	if(Get_Pedal_State(Id,FORWARD)==GPIO_PIN_RESET)
	{
		Set_Cylinder_Direction(Id,FORWARD);
	}
	else if(Get_Pedal_State(Id,REVERSE)==GPIO_PIN_RESET)
	{
		Set_Cylinder_Direction(Id,REVERSE);
	}
	else
	{
		Set_Cylinder_Direction(Id,STOP);
	}
}


/* USER CODE END 0 */
