/*
 * Eeprom.h
 *
 *  Created on: May 26, 2020
 *      Author: Athishay
 */
/* USER CODE BEGIN Includes */
#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include <string.h>


void Write_Byte_toFlash(uint32_t address, uint32_t data);
uint32_t Read_Byte_fromFlash(uint32_t address);


#endif /* INC_EEPROM_H_ */
/* USER CODE END Includes */
