/**
  ******************************************************************************
  * File Name          : gpio.h
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
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "System_variables.h"
#include "Automatic_Mode.h"
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

void Set_Cylinder_Direction(Station_Id Id,Cylinder_Movement Action);
void Cylinder1_Action(Cylinder_Movement Action);
void Cylinder2_Action(Cylinder_Movement Action);
void Cylinder3_Action(Cylinder_Movement Action);
void Cylinder4_Action(Cylinder_Movement Action);
void Cylinder5_Action(Cylinder_Movement Action);
void Cylinder6_Action(Cylinder_Movement Action);
extern uint32_t Get_Cylinder_Position(Station_Id Id);

GPIO_PinState Get_Pedal_State(Station_Id Id,Cylinder_Movement Direction);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
