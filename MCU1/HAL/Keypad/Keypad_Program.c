/*
 * Keypad_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: salma
 */
#include "Keypad_Interface.h"
#include "../../Common/definition.h"
u8 keypad_value1[Row][Column]= KEYPAD_ARR1;
u8 keypad_value2[Row][Column]=KEYPAD_ARR2;
void KEYPAD_voidInit()
{
	DIO_voidSetPortDir(KeypadGroup,0xF0);
	DIO_voidSetPortValue(KeypadGroup,0xFF);
}

u8 KEYPAD_u8GetValue1()
{
	u8 C , R ;
	for(C=0;C<Column;C++)
	{
		DIO_voidSetPortValue(KeypadGroup,0xFF);
		DIO_voidSetPinValue(KeypadGroup,C+Column,Low);
		for(R=0;R<Row;R++)
		{
			if(DIO_u8ReadPinValue(KeypadGroup,R)== Pressed)
			{
				return keypad_value1[R][C];
			}
		}
		DIO_voidSetPinValue(KeypadGroup,C+Column,High);
	}
	return Unpressed ;
}

char KEYPAD_charGetValue2()
{
	int C , R ;
	for(C=0;C<Column;C++)
	{
		DIO_voidSetPinValue(KeypadGroup,C+Column,Low);
		for(R=0;R<Row;R++)
		{
			if(DIO_u8ReadPinValue(KeypadGroup,R)== Pressed)
			{
				return keypad_value1[R][C];
			}
		}
		DIO_voidSetPinValue(KeypadGroup,C+Column,Low);
	}
	return Unpressed ;
}
