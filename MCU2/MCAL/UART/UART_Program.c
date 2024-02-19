/*
 * UART_Program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: salma
 */

#include "UART_Interface.h"
static void(*GlobalIUARTF)(void)=NULL;
#include <util/delay.h>
void UART_voidInit(u32 BoudRate)
{
	/*Set boud rate*/
	clear_bit(UART_UBRRH,UBRRH_URSEL);
	UART_UBRRH=0;
	UART_UBRRL=BoudRate;
	set_bit(UART_UCSRB,UCSRB_RXEN);
	/*Interrupts*/
#if TXIEState==disable
	clear_bit(UART_UCSRB,UCSRB_TXCIE);
#elif TXIEState==enable
	set_bit(UART_UCSRB,UCSRB_TXCIE);
#endif

#if RXIEState==disable
	clear_bit(UART_UCSRB,UCSRB_RXCIE);
#elif RXIEState==enable
	set_bit(UART_UCSRB,UCSRB_RXCIE);
#endif

#if UDIEState==disable
	clear_bit(UART_UCSRB,UCSRB_UDRIE);
#elif UDIEState==enable
	set_bit(UART_UCSRB,UCSRB_UDRIE);
#endif

	/*Async*/
	set_bit(UART_UCSRC,UCSRC_URSEL);
	clear_bit(UART_UCSRC,UCSRC_UMSEL);

	/*parity*/
#if ParityEnable==enable
#if Parity==odd
	set_bit(UART_UCSRC,UCSRC_UPM0);
	set_bit(UART_UCSRC,UCSRC_UPM1);
#elif Parity==even
	set_bit(UART_UCSRC,UCSRC_UPM0);
	clear_bit(UART_UCSRC,UCSRC_UPM1);
#endif
#elif ParityEnable==disable
	clear_bit(UART_UCSRC,UCSRC_UPM0);
	clear_bit(UART_UCSRC,UCSRC_UPM1);
#endif

	/*Stop bits*/
#if NoStopBits==1
	clear_bit(UART_UCSRC,UCSRC_USBS);
#elif NoStopBits==2
	set_bit(UART_UCSRC,UCSRC_USBS);
#else
#error "Invalid Option"
#endif

	/*Data size*/
#if DataSize==5
	clear_bit(UART_UCSRC,UCSRC_UCSZ0);
	clear_bit(UART_UCSRC,UCSRC_UCSZ1);
	clear_bit(UART_UCSRB,UCSRB_UCSZ2);
#elif DataSize==6
	set_bit(UART_UCSRC,UCSRC_UCSZ0);
	clear_bit(UART_UCSRC,UCSRC_UCSZ1);
	clear_bit(UART_UCSRB,UCSRB_UCSZ2);
#elif DataSize==7
	clear_bit(UART_UCSRC,UCSRC_UCSZ0);
	set_bit(UART_UCSRC,UCSRC_UCSZ1);
	clear_bit(UART_UCSRB,UCSRB_UCSZ2);
#elif DataSize==8
	set_bit(UART_UCSRC,UCSRC_UCSZ0);
	set_bit(UART_UCSRC,UCSRC_UCSZ1);
	clear_bit(UART_UCSRB,UCSRB_UCSZ2);
#elif DataSize==9
	set_bit(UART_UCSRC,UCSRC_UCSZ0);
	set_bit(UART_UCSRC,UCSRC_UCSZ1);
	set_bit(UART_UCSRB,UCSRB_UCSZ2);
#else
#error "Invalid Option"
#endif
}

void UART_voidSendData(u8 Data)
{
	while (get_bit(UART_UCSRA,UCSRA_UDRE)==Full);
	set_bit(UART_UCSRA,UCSRA_UDRE);
	UART_UDR=Data;
	set_bit(UART_UCSRB,UCSRB_TXEN);

}

u8 UART_u8RecieveData()
{
	set_bit(UART_UCSRA,UCSRA_RXC);
	u8 RecievedData;
	while (get_bit(UART_UCSRA,UCSRA_UDRE)==Full);
	set_bit(UART_UCSRA,UCSRA_UDRE);
	set_bit(UART_UCSRB,UCSRB_RXEN);
	while (get_bit(UART_UCSRA,UCSRA_RXC)==Low);
	RecievedData=UART_UDR;
	return RecievedData;
}
u8 UART_u8RecieveDataInt()
{
	return UART_UDR;
}
void UART_voidCallBack(void (*UARTPF)(void))
{

	if(UARTPF!=NULL)
	{
		GlobalIUARTF=UARTPF;
	}
}

void __vector_13(void)   __attribute__((signal));
void __vector_13(void)
{

	if (GlobalIUARTF!=NULL)
	{
		GlobalIUARTF();
	}

}
