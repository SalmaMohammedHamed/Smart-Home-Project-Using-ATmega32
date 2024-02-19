 /******************************************************************************
 *
 * Module: SPI
 *
 * File Name: spi.h
 *
 * Description: Header file for the SPI AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef SPI_H_
#define SPI_H_


#include "../../Common/Bit_Math.h"
#include "../../Common/STD_Types.h"
#include "SPI_Private.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*
 * Default SPI data value used in case we need to receive a byte from the other device,
 * without need to send a data to it
 */
#define SPI_DEFAULT_DATA_VALUE 0xFF

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the SPI device as Master.
 */
void SPI_initMaster(void); 

/*
 * Description :
 * Initialize the SPI device as Slave.
 */
void SPI_initSlave(void);

/*
 * Description :
 * Send the required data through SPI to the other SPI device.
 * In the same time data will be received from the other device.
 */
u8 SPI_sendReceiveByte(u8 data);

/*
 * Description :
 * Send the required string through SPI to the other SPI device.
 */
void SPI_sendString(const u8 *str);

/*
 * Description :
 * Receive the required string until the '#' symbol through SPI from the other SPI device.
 */
void SPI_receiveString(u8 *str);

void SPI_voidCallBack(void (*SPII)(void));
u8 SPI_u8RecieveInt();

#endif
