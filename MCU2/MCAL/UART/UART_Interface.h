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
u8 UART_u8RecieveDataInt();
void UART_voidCallBack(void (*UARTPF)(void));



#endif /* MCAL_UART_UART_INTERFACE_H_ */
