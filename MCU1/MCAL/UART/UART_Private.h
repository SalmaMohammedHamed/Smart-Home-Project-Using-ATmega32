/*
 * UART_Private.h
 *
 *  Created on: Oct 29, 2023
 *      Author: salma
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#include "../../Common/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
/*registers*/
#define UART_UDR        *((volatile u8*)0x2C)
#define UART_UCSRA      *((volatile u8*)0x2B)
#define UART_UCSRB      *((volatile u8*)0x2A)
#define UART_UCSRC      *((volatile u8*)0x40)
#define UART_UBRRH      *((volatile u8*)0x40)
#define UART_UBRRL      *((volatile u8*)0x29)

/*bits*/
#define UCSRA_RXC  7
#define UCSRA_TXC  6
#define UCSRA_UDRE 5
#define UCSRA_FE   4
#define UCSRA_DOR  3
#define UCSRA_PE   2
#define UCSRA_U2X  1
#define UCSRA_MPCM 0
#define Embty      1
#define Full       0

#define UCSRB_RXCIE  7
#define UCSRB_TXCIE  6
#define UCSRB_UDRIE  5
#define UCSRB_RXEN   4
#define UCSRB_TXEN   3
#define UCSRB_UCSZ2  2
#define UCSRB_RXB8   1
#define UCSRB_TXB8   0

#define UCSRC_URSEL  7
#define UCSRC_UMSEL  6
#define UCSRC_UPM1   5
#define UCSRC_UPM0   4
#define UCSRC_USBS   3
#define UCSRC_UCSZ1  2
#define UCSRC_UCSZ0  1

#define UBRRH_URSEL  7


#define odd  1
#define even 2

#define UARTGroup DIO_GroupD
#define RX        DIO_Pin0
#define TX        DIO_Pin1


#endif /* MCAL_UART_UART_PRIVATE_H_ */
