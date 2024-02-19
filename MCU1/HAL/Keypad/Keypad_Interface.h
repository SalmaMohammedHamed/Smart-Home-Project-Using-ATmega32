/*
 * Keypad_Interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: salma
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_
#include "Keypad_Config.h"
#include "Keypad_Private.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/STD_Types.h"
#include "../../Common/definition.h"
u8 keypad_value1[Row][Column];
u8 keypad_value2[Row][Column];
void KEYPAD_voidInit();
u8 KEYPAD_u8GetValue1();
char KEYPAD_charGetValue2();

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
