/*
 * EEPROM_Program.cc
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#include "EEPROM_Interface.h"

void IN_EEPROM_voidWriteByte( u8 Address , u8 data)
{
	while(get_bit(EE_EECR,EE_EECR_EEWE));
	while(get_bit(E_SPMCR,E_SPMCR_SPMEN));
	EE_EEARL = Address ;
	EE_EEDR  = data ;
	set_bit(EE_EECR,EE_EECR_EEMWE);
	set_bit(EE_EECR,EE_EECR_EEWE);
}
void IN_EEPROM_voidReadByte( u8 Address , u8* data)
{
	while(get_bit(EE_EECR,EE_EECR_EEWE));
	while(get_bit(E_SPMCR,E_SPMCR_SPMEN));
	EE_EEARL = Address ;
	set_bit(EE_EECR,EE_EECR_EERE);
	*data = EE_EEDR ;
}

void IN_EEPROM_voidEraseAll(void)
{
	u16 EEPROM_Add ;
	for(EEPROM_Add = 0 ; EEPROM_Add < Max_Array ; EEPROM_Add++)
	{
		IN_EEPROM_voidWriteByte( EEPROM_Add , 0x00 );
	}
}

void IN_EEPROM_voidEraseByte(u8 Address)
{
	IN_EEPROM_voidWriteByte( Address , 0x00 );
}
