/*
 * T1_interface.h
 *
 *  Created on: Nov 26, 2023
 *      Author: salma
 */

#ifndef MCAL_TIMER_TIMER1_T1_INTERFACE_H_
#define MCAL_TIMER_TIMER1_T1_INTERFACE_H_
#include "T1_Private.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_Types.h"


/************Normal Mode Functions*************/
void T1_voidNormalModeInit(u8 Prescaller,u8 PreloadValue,u8 InterruptState);
void T1_voidCallBackFuncNormalMode(void (*Normalpf)(void));

/*******************CTC Mode functions**************************/
void T1_voidCTCModeInit(u8 Prescaller,u16 CompareValue,u8 Interruptstate,u8 OC1AState);
void T1_voidCallBackFuncOCA(void (*CTCApf)(void));
void T1_voidCallBackFuncOCB(void (*CTCBpf)(void));

/*************************PWM********************************/
void T1_voidFastPWMFixedTop(u8 Type,u8 PreScaller ,u8 PWMMode , u8 DutyCycle);
void T1_voidFastPWMSetTop(u8 Type,u8 PreScaller ,u8 PWMMode ,u16 TopValue, u8 DutyCycle);

/**********************servo*****************************/
void T1_voidFastPWMServoInit();
void T1_voidFastPWMServoSetAngle(u16 angle);

/**************ICU*************************/
void T1_voidCallBackFuncICUMode(void (*ICUpf)(void));
void T1_voidICUInit(void);
#endif /* MCAL_TIMER_TIMER1_T1_INTERFACE_H_ */
