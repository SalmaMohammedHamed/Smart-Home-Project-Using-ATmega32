/*
 * EEPROM_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#ifndef MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_

#include "EEPROM_Config.h"
#include "EEPROM_Private.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/definition.h"

void IN_EEPROM_voidWriteByte( u8 Address , u8 data);
void IN_EEPROM_voidReadByte( u8 Address , u8* data);
void IN_EEPROM_voidEraseAll(void);
void IN_EEPROM_voidEraseByte(u8 Address);

#endif /* MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_ */
