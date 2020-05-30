/*
 * Automatic_Mode.h
 *
 *  Created on: May 25, 2020
 *      Author: Athishay
 */
/**
  ******************************************************************************
  * File Name          : temp.h
  * Description        : This file contains all the functions prototypes for
  *                      the gpio
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_AUTOMATIC_MODE_H_
#define INC_AUTOMATIC_MODE_H_
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "System_variables.h"
#include "main.h"
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
#define TIMER_ERROR_FACTOR 2.55f
#define APB1_CLOCK_FREQ 108000   //Divide value by 1000 to get timer interrupt in seconds
#define APB2_CLOCK_FREQ 108000
#define TIMER_CALLBACK_TIMEOUT 1000


 typedef enum
  {
  	MANUAL=0,
  	AUTOMATIC,
  	EMERGENCY_STOP
  }Mode_Selection;

  typedef enum
  {
  	FORWARD=0,
  	REVERSE,
  	STOP
  }Cylinder_Movement;



  typedef enum
  {
  	STATION_1=0,
  	STATION_2,
  	STATION_3,
  	STATION_4,
  	STATION_5,
  	STATION_6,
  	END_STATION
  }Station_Id;



  typedef enum
  {
  	POSITION_1=0,
  	POSITION_2,
  	POSITION_3,
  	POSITION_4,
  	SET_OFF
  }Cylinder_stages;


  typedef struct station_Info
  {
  	int Production_Count;
  	uint8_t Cylinder_direction;
  	uint32_t Down_Movement_Duration;
  	uint32_t Stop_Movement_Duration;
  	uint32_t Up_Movement_Duration;
  }station_info;


  typedef struct Machine_Info
  {
  	int Machine_Id;
  	station_info Station_Information[END_STATION];
  }Machine_info;





/* USER CODE END Private defines */



/* USER CODE BEGIN Prototypes */
 uint32_t Get_Cylinder_Position(Station_Id Id);
 void Set_Cylinder_Position(Station_Id Id,uint32_t Position);
 uint32_t Get_Cylinder_Position_hold_Duration(Station_Id Id,Cylinder_Movement Direction);
 void Start_Machine(uint32_t Id);
 void Run_AutomaticMode(void);
 void Stop_Machine(void);
 void Start_APBx_Timer_Interrupt(Station_Id Id,uint32_t Duration);
 void Stop_APBx_Timer_Interrupt(Station_Id Id);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /* INC_AUTOMATIC_MODE_H_ */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

