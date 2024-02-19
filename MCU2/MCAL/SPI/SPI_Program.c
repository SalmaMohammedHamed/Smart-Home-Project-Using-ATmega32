 /******************************************************************************
 *
 * Module: SPI
 *
 * File Name: spi.c
 *
 * Description: Source file for the SPI AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "SPI_Interface.h"
#include "SPI_Config.h"
#include "../../Common/definition.h"
static void(*GlobalISPIF)(void)=NULL;
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the SPI device as Master.
 */
void SPI_initMaster(void) 
{
	/******** Configure SPI Master Pins *********
	 * SS(PB4)   --> Output
	 * MOSI(PB5) --> Output 
	 * MISO(PB6) --> Input
	 * SCK(PB7) --> Output
	 ********************************************/

	
    /************************** SPCR Description **************************
     * SPIE    = 0 Disable SPI Interrupt
     * SPE     = 1 Enable SPI Driver
     * DORD    = 0 Transmit the MSB first
     * MSTR    = 1 Enable Master
     * CPOL    = 0 SCK is low when idle
     * CPHA    = 0 Sample Data with the raising edge
     * SPR1:0  = 00 Choose SPI clock = Fosc/4
     ***********************************************************************/
	SPI_SPCR = (1<<SPCR_SPE) | (1<<SPCR_MSTR);
#if SPI_InterrptE==enable
	set_bit(SPI_SPCR,SPCR_SPIE);
#endif
	/* Clear the SPI2X bit in SPSR to Choose SPI clock = Fosc/4 */
	SPI_SPSR &= ~(1<<SPSR_SPI2X);
}

/*
 * Description :
 * Initialize the SPI device as Slave.
 */
void SPI_initSlave(void)
{ 
	/******** Configure SPI Slave Pins *********
	 * SS(PB4)   --> Input
	 * MOSI(PB5) --> Input
	 * MISO(PB6) --> Output
	 * SCK(PB7) --> Input
	 ********************************************/


	/************************** SPCR Description **************************
	 * SPIE    = 0 Disable SPI Interrupt
	 * SPE     = 1 Enable SPI Driver
	 * DORD    = 0 Transmit the MSB first
	 * MSTR    = 0 Disable Master
	 * CPOL    = 0 SCK is low when idle
	 * CPHA    = 0 Sample Data with the raising edge
	 * SPR1:0  = 00 Choose SPI clock = Fosc/4
	 ***********************************************************************/
	SPI_SPCR = (1<<SPCR_SPE);
#if SPI_InterrptE==enable
	set_bit(SPI_SPCR,SPCR_SPIE);
#endif

	/* Clear the SPI2X bit in SPSR to Choose SPI clock = Fosc/4 */
	SPI_SPSR &= ~(1<<SPSR_SPI2X);
}

/*
 * Description :
 * Send the required data through SPI to the other SPI device.
 * In the same time data will be received from the other device.
 */
u8 SPI_sendReceiveByte(u8 data)
{
	/* Initiate the communication and send data by SPI */
	SPI_SPDR = data;

	/* Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */
	while(!get_bit(SPI_SPSR,SPSR_SPIF)){}

	/*
	 * Note: SPIF flag is cleared by first reading SPSR (with SPIF set) which is done in the previous step.
	 * and then accessing SPDR like the below line.
	 */
	return SPI_SPDR;
}

/*
 * Description :
 * Send the required string through SPI to the other SPI device.
 */
void SPI_sendString(const u8 *str)
{
	u8 i = 0;
	u8 received_data = 0;

	/* Send the whole string */
	while(str[i] != '\0')
	{
		/*
		 * received_data contains the received data from the other device.
		 * It is a dummy data variable as we just need to send the string to other device.
		 */
		received_data = SPI_sendReceiveByte(str[i]);
		i++;
	}
}

/*
 * Description :
 * Receive the required string until the '#' symbol through SPI from the other SPI device.
 */
void SPI_receiveString(u8 *str)
{
	u8 i = 0;

	/* Receive the first byte */
	str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);

	/* Receive the whole string until the '#' */
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	str[i] = '\0';
}
u8 SPI_u8RecieveInt()
{
	return SPI_SPDR;
}
void SPI_voidCallBack(void (*SPII)(void))
{
	if(SPII!=NULL)
	{
		GlobalISPIF=SPII;
	}
}
void __vector_12(void)   __attribute__((signal));
void __vector_12(void)
{

	if (GlobalISPIF!=NULL)
	{
		GlobalISPIF();
	}

}
