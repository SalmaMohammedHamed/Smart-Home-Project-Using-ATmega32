/*
 * ADC_Interface.h
 *
 *  Created on: Oct 6, 2023
 *      Author: salma
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_s
#include "ADC_Private.h"
#include "ADC_Config.h"
void ADC_voidInit();
void ADC_voidInitPolling(ADCInformation ADCInfo); //polling
void ADC_voidReadResultPolling(u8 channel, u16 *Result);
void ADC_voidInitInterrupt(ADCInformation ADCInfo);  //interrupt
void ADC_voidReadResultInterrupt(u8 channel);
void __vector_16()   __attribute__((signal));


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
