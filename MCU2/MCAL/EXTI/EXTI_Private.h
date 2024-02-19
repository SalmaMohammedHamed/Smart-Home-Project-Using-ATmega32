/*
 * Interrupt_Private.h
 *
 *  Created on: Sep 30, 2023
 *      Author: salma
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_
#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/definition.h"

#define EXTI_MCUCR  *((volatile u8*)0x55)
#define EXTI_MCUCSR *((volatile u8*)0x54)
#define EXTI_GICR   *((volatile u8*)0x5B)
#define EXTI_GIFR   *((volatile u8*)0x5A)

//MCUCR bits
#define EXTI_ISC11  3
#define EXTI_ISC10  2
#define EXTI_ISC01  1
#define EXTI_ISC00  0

//MCUCSR bits
#define EXTI_ISC2    6


//GICR bits & GIFR bits
#define EXTI_INT1 7
#define EXTI_INT0 6
#define EXTI_INT2 5


#define LowLevel          1
#define AnyCahnge         2
#define Falling           3
#define Rising            4


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
