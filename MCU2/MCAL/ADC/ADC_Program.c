/*
 * ADC_Program.c
 *
 *  Created on: Oct 6, 2023
 *      Author: salma
 */
#include "ADC_Interface.h"
#include "../../Common/definition.h"
static u16 InterruptData ;  //static??

void ADC_voidInit()
{
	ADCInformation ADCInformationSet ;
	ADCInformationSet.AutoTriggerState=ADC_AutoTriggerState;
	ADCInformationSet.DivisionFactor=ADC_DivisionFactor;
	ADCInformationSet.TriggerSource=ADC_TriggerSource;
#if ADC_Mode==Polling
	ADC_voidInitPolling(ADCInformationSet);
#elif
	ADC_voidInitInterrupt(ADCInformationSet);
#endif
}
void ADC_voidInitPolling(ADCInformation ADCInfo)
{
	/*Voltage Reference Selections*/
#if ReferenceSelect==ADCOff
	clear_bit(ADC_MUX,ADMUX_REFS1);
	clear_bit(ADC_MUX,ADMUX_REFS0);
#elif ReferenceSelect==BothExternal
	clear_bit(ADC_MUX,ADMUX_REFS1);
	set_bit(ADC_MUX,ADMUX_REFS0);

#elif ReferenceSelect==InternalVcc
	set_bit(ADC_MUX,ADMUX_REFS1);
	set_bit(ADC_MUX,ADMUX_REFS0);
#else
	#error "Invalid Option"
#endif


	/*data adjustment*/
#if DataAdjustmant==Right
	clear_bit(ADC_MUX,ADMUX_ADLAR);
#elif DataAdjustmant==Left
	set_bit(ADC_MUX,ADMUX_ADLAR);
#endif


	/*Enable ADC*/
	set_bit(ADC_SRA,ADCSRA_ADEN);


	/*autotrigger*/
	if (ADCInfo.AutoTriggerState==ON)
	{
		set_bit(ADC_SRA,ADCSRA_ADATE);
		ADCInfo.TriggerSource&=0xE0; //11100000
		ADC_SFIOR&=0x1F; //00011111
		ADC_SFIOR|=ADCInfo.TriggerSource;
	}
	else if(ADCInfo.AutoTriggerState==OFF)
	{
		clear_bit(ADC_SRA,ADCSRA_ADATE);
	}


	/*disable interrupt*/
	clear_bit(ADC_SRA,ADCSRA_ADIE);


    /*prescaler*/
	ADCInfo.DivisionFactor&=0x07; //00000111
	ADC_SRA&=0xF8;  //11111000
	ADC_SRA|=ADCInfo.DivisionFactor;

}


void ADC_voidReadResultPolling(u8 channel, u16 *Result)
{
	channel&=0x1F;
	ADC_MUX&=0xE0;
	ADC_MUX|=channel; //choose the channel
	set_bit(ADC_SRA,ADCSRA_ADSC);  //start conversion
	while(get_bit(ADC_SRA,ADCSRA_ADIF)!=ON);
	*Result=ADC_DATA;
	set_bit(ADC_SRA,ADCSRA_ADIF);
}


void ADC_voidInitInterrupt(ADCInformation ADCInfo)
{
	ADC_MUX=0xFF; //initially to disable the channels until needed
	/*Voltage Reference Selections*/
#if ReferenceSelect==Off
	clear_bit(ADC_MUX,ADMUX_REFS1);
	clear_bit(ADC_MUX,ADMUX_REFS0);
#elif ReferenceSelect==BothExternal
	clear_bit(ADC_MUX,ADMUX_REFS1);
	set_bit(ADC_MUX,ADMUX_REFS0);

#elif ReferenceSelect==InternalVcc
	set_bit(ADC_MUX,ADMUX_REFS1);
	set_bit(ADC_MUX,ADMUX_REFS0);
#else
	#error "Invalid Option"
#endif


	/*data adjustment*/
#if DataAdjustmant==Right
	clear_bit(ADC_MUX,ADMUX_ADLAR);
#elif DataAdjustmant==Left
	set_bit(ADC_MUX,ADMUX_ADLAR);
#endif


	/*Enable ADC*/
	set_bit(ADC_SRA,ADCSRA_ADEN);


	/*autotrigger*/
	if (ADCInfo.AutoTriggerState==ON)
	{
		set_bit(ADC_SRA,ADCSRA_ADATE);
		ADCInfo.TriggerSource&=0xE0; //11100000
		ADC_SFIOR&=0x1F; //00011111
		ADC_SFIOR|=ADCInfo.TriggerSource;
	}
	else if(ADCInfo.AutoTriggerState==OFF)
	{
		clear_bit(ADC_SRA,ADCSRA_ADATE);
	}


	/*enable interrupt*/
	set_bit(ADC_SRA,ADCSRA_ADIE);


    /*prescaler*/
	ADCInfo.DivisionFactor&=0x07; //00000111
	ADC_SRA&=0xF8;  //11111000
	ADC_SRA|=ADCInfo.DivisionFactor;
}


void ADC_voidReadResultInterrupt(u8 channel)
{
	channel&=0x1F;
		ADC_MUX&=0xE0;
		ADC_MUX|=channel; //choose the channel
		set_bit(ADC_SRA,ADCSRA_ADSC);  //start conversion
}

void __vector_16()
{
	InterruptData=ADC_DATA;
}
