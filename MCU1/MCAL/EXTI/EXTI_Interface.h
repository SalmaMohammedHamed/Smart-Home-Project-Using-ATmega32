/*
 * Interrupt_Interface.h
 *
 *  Created on: Sep 30, 2023
 *      Author: salma
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_
#include "EXTI_Private.h"
void EXTI_voidInitINT0(u8 sense);
void EXTI_voidInitINT1(u8 sense);
void EXTI_voidInitINT2(u8 sense);
void EXTI0_CallBack (void (*ptr)(void));
void EXTI1_CallBack (void (*ptr)(void));
void EXTI2_CallBack (void (*ptr)(void));



#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
