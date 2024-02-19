/*
 * T2_Private.h
 *
 *  Created on: Dec 14, 2023
 *      Author: salma
 */

#ifndef MCAL_TIMERS_TIMER2_T2_PRIVATE_H_
#define MCAL_TIMERS_TIMER2_T2_PRIVATE_H_

#define T2_TCCR2         *((volatile u8*)0x45)
#define T2_TCNT2         *((volatile u8*)0x44)
#define T2_OCR2          *((volatile u8*)0x43)
#define T2_TIMSK         *((volatile u8*)0x59)
#define T2_TIFR          *((volatile u8*)0x58)

#define T2_TCCR2_FOC2   7
#define T2_TCCR2_WGM20  6
#define T2_TCCR2_COM21  5
#define T2_TCCR2_COM20  4
#define T2_TCCR2_WGM21  3
#define T2_TCCR2_CS22   2
#define T2_TCCR2_CS21   1
#define T2_TCCR2_CS20   0

#define T2_TIMSK_OCIE2  7
#define T2_TIMSK_TOIE2  6


#define T2_TIFR_OCF2   7
#define T2_TIFR_TOV2   6

#define CTC_OC2_Disconnect 1
#define CTC_OC2_Tog        2
#define CTC_OC2_CLr        3
#define CTC_OC2_Set        4

#define PWM_OC2_Disconnect     1
#define PWM_OC2_nonInverting   2
#define PWM_OC2_Inverting      3

#define prescalerNo 1
#define prescaler8  2
#define prescaler64 3
#define prescaler256 4
#define prescaler1024 5

#define FastPWM 1
#define PhaseCorrectPWM 2



#endif /* MCAL_TIMERS_TIMER2_T2_PRIVATE_H_ */
