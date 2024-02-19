/*
 * T0_Private.h
 *
 *  Created on: Nov 30, 2023
 *      Author: salma
 */

#ifndef MCAL_TIMERS_TIMER0_T0_PRIVATE_H_
#define MCAL_TIMERS_TIMER0_T0_PRIVATE_H_

#define T0_TCCR0         *((volatile u8*)0x53)
#define T0_TCNT0         *((volatile u8*)0x52)
#define T0_OCR0          *((volatile u8*)0x5C)
#define T0_TIMSK         *((volatile u8*)0x59)
#define T0_TIFR          *((volatile u8*)0x58)

#define T0_TCCR0_FOC0   7
#define T0_TCCR0_WGM00  6
#define T0_TCCR0_COM01  5
#define T0_TCCR0_COM00  4
#define T0_TCCR0_WGM01  3
#define T0_TCCR0_CS02   2
#define T0_TCCR0_CS01   1
#define T0_TCCR0_CS00   0

#define T0_TIMSK_OCIE0  1
#define T0_TIMSK_TOIE0  0


#define T0_TIFR_OCF0   1
#define T0_TIFR_TOV0   0

#define CTC_OC0_Disconnect 1
#define CTC_OC0_Tog        2
#define CTC_OC0_CLr        3
#define CTC_OC0_Set        4

#define PWM_OC0_Disconnect     1
#define PWM_OC0_nonInverting   2
#define PWM_OC0_Inverting      3

#define prescalerNo 1
#define prescaler8  2
#define prescaler64 3
#define prescaler256 4
#define prescaler1024 5

#define FastPWM 1
#define PhaseCorrectPWM 2



#endif /* MCAL_TIMERS_TIMER0_T0_PRIVATE_H_ */
