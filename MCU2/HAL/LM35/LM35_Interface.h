/*
 * LM35_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: salma
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_
#include "LM35_Config.h"
#include "LM35_Private.h"
#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"


void LM35_voidInit();
void LM35_voidRead(u16 *temp);


#endif /* HAL_LM35_LM35_INTERFACE_H_ */
