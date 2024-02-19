/*
 * Relay.c
 *
 *  Created on: Feb 2, 2024
 *      Author: salma
 */
#include "Relay.h"

void Relay_voidInit (u8 Group, u8 pin)
{
	DIO_voidSetPinDir(Group, pin, Output);
}

void Relay_voidOn (u8 Group, u8 pin)
{
	DIO_voidSetPinValue(Group, pin, High);
}

void Relay_voidOff (u8 Group, u8 pin)
{
	DIO_voidSetPinValue(Group, pin, Low);
}

void Relay_voidToggle (u8 Group, u8 pin)
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
