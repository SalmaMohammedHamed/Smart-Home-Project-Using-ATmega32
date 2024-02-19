/*
 * DIO_Interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: hisha
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "DIO_Praivte.h"
//salma recommandation

void DIO_voidSetPinDir(u8 Group_Type, u8 Pin_No, u8 DirStatus);
void DIO_voidSetPinValue(u8 Group_Type, u8 Pin_No, u8 Value);
u8 DIO_u8ReadPinValue(u8 Group_Type, u8 Pin_No);
void DIO_voidControlPullupPin(u8 Group_Type,u8 Pin_No , u8 PullUp_Status);
void DIO_voidSetPortDir(u8 Group_Type , u8 DirStatus);
void DIO_voidSetPortValue(u8 Group_Type , u8 Value);
u8 DIO_u8ReadPortValue(u8 Group_Type);
void DIO_voidControlPullupPort(u8 Group_Type , u8 PullUp_Status);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
