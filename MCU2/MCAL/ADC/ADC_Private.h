/*
 * ADC_Private.h
 *
 *  Created on: Oct 6, 2023
 *      Author: salma
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_
#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/definition.h"


#define ADC_MUX  *((volatile u8*)0x27)
#define ADC_SRA *((volatile u8*)0x26)
#define ADC_DATA   *((volatile u16*)0x24)
#define ADC_SFIOR  *((volatile u8*)0x50)

//ADMUX bits
#define ADMUX_REFS1  7
#define ADMUX_REFS0  6
#define ADMUX_ADLAR  5


//ADCSRA bits
#define ADCSRA_ADEN   7
#define ADCSRA_ADSC   6
#define ADCSRA_ADATE  5
#define ADCSRA_ADIF   4
#define ADCSRA_ADIE   3
#define ADCSRA_ADPS2  2
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS0  0


//SFIOR bits
#define SFIOR_ADTS2  7
#define SFIOR_ADTS1  6
#define SFIOR_ADTS0  5

//refrence selection
#define ADCOff 1
#define BothExternal 2
#define InternalVcc  3

//data reg adjustment
#define Right  1
#define Left   2

#define ADCRefV 5
#define ADCRefmV 5000UL
#define DACRes  1024
//prescaler
/*enum prescaler
{
	Two=1,
	Four,
	Eight,
	Sixteen,
	ThirtyTwo,
	SixtyFour,
	Hundred28
};*/
#define Two       1
#define Four      2
#define Eight     3
#define Sixteen   4
#define ThirtyTwo 5
#define SixtyFour 6
#define Hundred28 7

//Trigger Sources
typedef enum
{
	FreeRunning,
	AnalogComparator=32,
	EXTI0=64,
	TimerCounter0CM=96,
	TimerCounter0OV=128,
	TimerCounter1CM=160,
	TimerCounter1OV=192,
	TimerCounter1CE=224
}TriggerSourceEnum;

//configration
typedef struct
{
	u8 AutoTriggerState;
	u8 TriggerSource;
	u8 DivisionFactor;
}ADCInformation;

#define Polling   1
#define Interrupt 2

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
