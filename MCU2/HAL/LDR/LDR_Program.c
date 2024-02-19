/*
 * LDR_Program.c
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#include "LDR_Interface.h"

void LDR_voidInit()
{
	DIO_voidSetPinDir(LDRGroup,LDRPin,Input);
}

void LDR_voidRead(u16 *Light)
{
#if LDRMode==Polling
	ADC_voidReadResultPolling(LDRPin,Light);
	*Light=((u32)(*Light)*ADCRefmV)/DACRes;  //convert ot equevilant mV
#elif LM35Mode==Interrupt
#endif
}
