/*
 * EEPROM_Private.h
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#ifndef MCAL_EEPROM_INTERNAL_EEPROM_PRIVATE_H_
#define MCAL_EEPROM_INTERNAL_EEPROM_PRIVATE_H_
#include "../../Common/STD_Types.h"

#define EE_EEARH  *((volatile u8*)0x3F)
#define EE_EEARL  *((volatile u8*)0x3E)
#define EE_EEDR   *((volatile u8*)0x3D)
#define EE_EECR   *((volatile u8*)0x3C)
#define E_SPMCR   *((volatile u8*)0x57)


// EEPROM control Register
#define EE_EECR_EERIE  3
#define EE_EECR_EEMWE  2
#define EE_EECR_EEWE   1
#define EE_EECR_EERE   0


#define E_SPMCR_SPMEN  0
#define Max_Array  1024

#endif /* MCAL_EEPROM_INTERNAL_EEPROM_PRIVATE_H_ */
