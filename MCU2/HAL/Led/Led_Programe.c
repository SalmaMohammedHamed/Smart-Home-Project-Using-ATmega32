/*
 * Led_Programe.c
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */

#include "Led_Interface.h"
#include <util/delay.h>
void LED_voidInit (u8 Group, u8 pin)
{
	DIO_voidSetPinDir(Group, pin, Output);
}

void LED_voidOn (u8 Group, u8 pin)
{
	DIO_voidSetPinValue(Group, pin, High);
}

void LED_voidOff (u8 Group, u8 pin)
{
	DIO_voidSetPinValue(Group, pin, Low);
}

void LED_voidToggle (u8 Group, u8 pin)
{
	if (DIO_u8ReadPinValue(Group,pin)==High)
	{
		LED_voidOff(Group,pin);
	}
	else
	{
		LED_voidOn(Group,pin);
	}

}
