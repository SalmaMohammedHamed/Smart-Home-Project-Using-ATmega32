/*
 * Switch_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */

#include "Switch_Interface.h"
void SWITCH_voidInit (u8 Group, u8 pin)
{
	DIO_voidSetPinDir(Group,pin,Input);
	DIO_voidControlPullupPin(Group,pin,High);
}

u8 SWITCH_u8GetValue (u8 Group, u8 pin)
{
	return DIO_u8ReadPinValue(Group,pin);
}
