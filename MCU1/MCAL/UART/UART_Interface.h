/*
 * UART_Interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: salma
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#include "UART_Private.h"
#include "UART_Config.h"
#include "../../Common/Bit_Math.h"


void UART_voidInit(u32 BoudRate);
void UART_voidSendData(u8 Data);
u8 UART_u8RecieveData();
/*ISR*/
void __vector_13()   __attribute__((signal));
void __vector_14()   __attribute__((signal));
void __vector_15()   __attribute__((signal));



#endif /* MCAL_UART_UART_INTERFACE_H_ */
