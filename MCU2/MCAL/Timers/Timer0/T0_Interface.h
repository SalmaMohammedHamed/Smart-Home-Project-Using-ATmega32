/*
 * T0_Interface.h
 *
 *  Created on: Nov 30, 2023
 *      Author: salma
 */

#ifndef MCAL_TIMERS_TIMER0_T0_INTERFACE_H_
#define MCAL_TIMERS_TIMER0_T0_INTERFACE_H_
#include "T0_Private.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_Types.h"
#include "../../../Common/definition.h"


/**********************Normal Mode functions**********************************/
void T0_voidNormalModeInit(u8 Prescaller,u8 PreloadValue,u8 InterruptState);
void T0_voidCallBackFuncNormalMode(void (*OVpf)(void));

/**********************************CTC****************************/
void T0_voidCTCModeInit(u8 OC0State ,u8 Prescaller,u8 CompareValue , u8 InterruptState);
void T0_voidCallBackFuncCTCMode(void (*CTCpf)(void));

/*******************************PWM**********************************/
void T0_voidPWMModeInit(u8 PWMType, u8 OC0State ,u8 Prescaller, u8 DutyCycle);

#endif /* MCAL_TIMERS_TIMER0_T0_INTERFACE_H_ */
