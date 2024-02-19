/*
 * LDR_Interface.h
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#ifndef HAL_LDR_LDR_INTERFACE_H_
#define HAL_LDR_LDR_INTERFACE_H_

#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/definition.h"
#include "LDR_Config.h"

void LDR_voidInit();
void LDR_voidRead(u16 *Light);

#endif /* HAL_LDR_LDR_INTERFACE_H_ */
