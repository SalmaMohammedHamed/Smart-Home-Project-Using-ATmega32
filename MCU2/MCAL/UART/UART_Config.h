/*
 * UART_Config.h
 *
 *  Created on: Oct 29, 2023
 *      Author: salma
 */

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_
#include "../../Common/definition.h"
#define TXIEState  disable
#define RXIEState  enable
#define UDIEState  disable

#define ParityEnable  enable
#define Parity        odd

#define NoStopBits    1

#define DataSize      8   /*5-9*/


#endif /* MCAL_UART_UART_CONFIG_H_ */
