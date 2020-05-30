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
#include "Eeprom.h"
#include "stm32f7xx_hal_flash_ex.h"
#include "string.h"

/* USER CODE END Includes */

/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void Write_Byte_toFlash(uint32_t address, uint32_t data) {
   // FLASH_Status status = FLASH_COMPLETE;
    address = address + 0x08080000;
    HAL_FLASH_Unlock();  //Unprotect the EEPROM to allow writing
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,address, data);
    HAL_FLASH_Lock();  // Reprotect the EEPROM
    //return status;
}

uint32_t Read_Byte_fromFlash(uint32_t address) {
    uint32_t tmp = 0;
    address = address + 0x08080000;
    tmp = *(__IO uint32_t*)address;

    return tmp;
}




/* USER CODE END 0 */

