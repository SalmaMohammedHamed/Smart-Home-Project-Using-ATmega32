/*
 * T1_Private.h
 *
 *  Created on: Nov 26, 2023
 *      Author: salma
 */

#ifndef MCAL_TIMER_TIMER1_T1_PRIVATE_H_
#define MCAL_TIMER_TIMER1_T1_PRIVATE_H_
#include "../../../Common/Bit_Math.h"
#define T1_TCCR1A        *((volatile u8*)0x4F)
#define T1_TCCR1B        *((volatile u8*)0x4E)
#define T1_TCNT1L        *((volatile u8*)0x4C)
#define T1_TCNT1H        *((volatile u8*)0x4D)
#define T1_TCNT1         *((volatile u16*)0x4C)

#define T1_OCR1AL        *((volatile u8*)0x4A)
#define T1_OCR1AH        *((volatile u8*)0x4B)

#define T1_OCR1A         *((volatile u16*)0x4A)
#define T1_OCR1B         *((volatile u16*)0x48)

#define T1_ICR1L         *((volatile u8*)0x46)
#define T1_ICR1H         *((volatile u8*)0x47)

#define T1_ICR1          *((volatile u16*)0x46)
#define T1_TIMSK         *((volatile u8*)0x59)
#define T1_TIFR          *((volatile u8*)0x59)




#define T1_TCCR1A_COM1A1    7
#define T1_TCCR1A_COM1A0    6
#define T1_TCCR1A_COM1B1    5
#define T1_TCCR1A_COM1B0    4
#define T1_TCCR1A_FOC1A     3
#define T1_TCCR1A_FOC1B     2
#define T1_TCCR1A_WGM11     1
#define T1_TCCR1A_WGM10     0

#define T1_TCCR1B_ICNC1     7
#define T1_TCCR1B_ICES1     6
#define T1_TCCR1B_WGM13     4
#define T1_TCCR1B_WGM12     3
#define T1_TCCR1B_CS12      2
#define T1_TCCR1B_CS11      1
#define T1_TCCR1B_CS10      0


#define T1_TIMSK_TICIE1     5
#define T1_TIMSK_OCIE1A     4
#define T1_TIMSK_OCIE1B     3
#define T1_TIMSK_TOIE1      2


#define T1_TIFR_ICF1        5
#define T1_TIFR_OCF1A       4
#define T1_TIFR_OCF1B       3
#define T1_TIFR_TOV1        2


#define CTC_OC1A_Disconnect 1
#define CTC_OC1A_Tog        2
#define CTC_OC1A_CLr        3
#define CTC_OC1A_Set        4

#define CTC_OC1B_Disconnect 1
#define CTC_OC1B_Tog        2
#define CTC_OC1B_CLr        3
#define CTC_OC1B_Set        4

#define CTC_UnitA          1
#define CTC_UnitB          2
#define CTC_BothUnits      3

#define PWM_UnitA          1
#define PWM_UnitB          2
#define PWM_BothUnits      3

#define PWM_OC1A_Disconnect 1
#define PWM_OC1A_Tog        2
#define PWM_OC1A_CLr        3
#define PWM_OC1A_Set        4

#define PWM_OC1B_Disconnect 1
#define PWM_OC1B_Tog        2
#define PWM_OC1B_CLr        3
#define PWM_OC1B_Set        4

typedef enum
{
	FastPWM_8Bit  ,
	FastPWM_9Bit  ,
	FastPWM_10Bit ,
	FastPWM_ICR1  ,
	FastPWM_OCR1A
}FastPWMStat;

#define FastPWM_8BitTopValue 0x00FF
#define FastPWM_9BitTopValue 0x01FF
#define FastPWM_10BitTopValue 0x03FF

#define Servo_value  19999

#define prescalerNo 1
#define prescaler8  2
#define prescaler64 3
#define prescaler256 4
#define prescaler1024 5

#define Inverting 1
#define NonInverting 2

#endif /* MCAL_TIMER_TIMER1_T1_PRIVATE_H_ */
