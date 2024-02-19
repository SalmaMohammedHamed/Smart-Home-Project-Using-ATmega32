/*
 * LM35_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: salma
 */

#include "LM35_Interface.h"
#include <util/delay.h>
#include "LM35_Config.h"
void LM35_voidInit()
{
	DIO_voidSetPinDir(LM35Group,LM35Pin,Input);
}

void LM35_voidRead(u16 *temp)
{
	ADC_voidReadResultPolling(LM35Pin,temp);
	*temp=((u32)(*temp)*ADCRefmV)/DACRes; //convert ot equevilant mV
	*temp= (*temp)/10.00;
}
