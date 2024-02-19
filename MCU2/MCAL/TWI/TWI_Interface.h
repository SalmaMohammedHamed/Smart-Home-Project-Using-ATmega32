/*
 * T0_Program.c
 *
 *  Created on: dec 2, 2023
 *      Author:salma
 */

#ifndef MCAL_COMMUNICATION_TWI_TWI_INTERFACE_H_
#define MCAL_COMMUNICATION_TWI_TWI_INTERFACE_H_

#include "TWI_Private.h"
#include "TWI_configuration.h"
#include "../../Common/Bit_Math.h"

/*Init*/
void TWI_voidMasterInit();
void TWI_voidSlaveInit();
/*************************************/
/*Start Condtion */
void TWI_voidStartCondition();
void TWI_voidRestartCondition();
/*************************************/
/*Stop Condtion */
void TWI_voidStopCondition();
/*************************************/
/*Slave Address */
void TWI_voidSendSlAWithWrite(u8 DestinationAddress);
void TWI_voidSendSlAWithRead(u8 DestinationAddress);
/*************************************/
/*Data Byte */
void TWI_voidWriteDataByte(u8 Data);
void TWI_voidReadDataByte(u8 *Data);





#endif /* MCAL_COMMUNICATION_TWI_TWI_INTERFACE_H_ */
