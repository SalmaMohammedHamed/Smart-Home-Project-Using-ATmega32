/*
 * T2_interace.h
 *
 *  Created on: Dec 14, 2023
 *      Author: salma
 */

#ifndef MCAL_TIMERS_TIMER2_T2_INTERACE_H_
#define MCAL_TIMERS_TIMER2_T2_INTERACE_H_
#include "T2_Private.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_Types.h"
#include "../../../Common/definition.h"

/**********************Normal Mode functions**********************************/
void T2_voidNormalModeInit(u8 Prescaller,u8 PreloadValue,u8 InterruptState);
void T2_voidCallBackFuncNormalMode(void (*OVpf)(void));

/**********************************CTC****************************/
void T2_voidCTCModeInit(u8 OC2State ,u8 Prescaller,u8 CompareValue , u8 InterruptState);
void T2_voidCallBackFuncCTCMode(void (*CTCpf)(void));

/*******************************PWM**********************************/
void T2_voidPWMModeInit(u8 PWMType, u8 OC2State ,u8 Prescaller, u8 DutyCycle);


#endif /* MCAL_TIMERS_TIMER2_T2_INTERACE_H_ */
