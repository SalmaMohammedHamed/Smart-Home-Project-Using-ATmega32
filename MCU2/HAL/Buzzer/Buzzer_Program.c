/*
 * Buzzer_Program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: salma
 */
#include "Buzzer_Interface.h"
#include <util/delay.h>
void BUZZER_voidInit ()
{
	DIO_voidSetPinDir(BuzzerGruop,BuzzerPin,Output);
}

void BUZZER_voidOn ()
{
	DIO_voidSetPinValue(BuzzerGruop,BuzzerPin,High);
}

void BUZZER_voidOff ()
{
	DIO_voidSetPinValue(BuzzerGruop,BuzzerPin,Low);
}

void BUZZER_voidToggle ()
{
	if (DIO_u8ReadPinValue(BuzzerGruop,BuzzerPin)==High)
	{
		BUZZER_voidOff();
	}
	else
	{
		BUZZER_voidOn();
	}
}
