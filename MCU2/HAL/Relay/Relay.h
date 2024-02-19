/*
 * Relay.h
 *
 *  Created on: Feb 2, 2024
 *      Author: salma
 */

#ifndef HAL_RELAY_RELAY_H_
#define HAL_RELAY_RELAY_H_

#include "../../Common/Bit_Math.h"
#include "../../Common/STD_Types.h"
#include "../../Common/definition.h"
void Relay_voidInit (u8 Group, u8 pin);
void Relay_voidOn (u8 Group, u8 pin);
void Relay_voidOff (u8 Group, u8 pin);
void Relay_voidToggle (u8 Group, u8 pin);

#endif /* HAL_RELAY_RELAY_H_ */
