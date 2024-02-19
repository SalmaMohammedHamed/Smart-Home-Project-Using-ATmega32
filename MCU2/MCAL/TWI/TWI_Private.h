/*
 * T0_Program.c
 *
 *  Created on: dec 2, 2023
 *      Author:salma
 */

#ifndef MCAL_COMMUNICATION_TWI_TWI_PRIVATE_H_
#define MCAL_COMMUNICATION_TWI_TWI_PRIVATE_H_
#include "../../Common/STD_Types.h"
//#define TWI_
#define TWI_TWBR      *((volatile u8*)0x20)
#define TWI_TWCR      *((volatile u8*)0x56)
#define TWI_TWSR      *((volatile u8*)0x21)
#define TWI_TWDR      *((volatile u8*)0x23)
#define TWI_TWAR      *((volatile u8*)0x22)


#define TWI_TWCR_TWINT   7
#define TWI_TWCR_TWEA    6
#define TWI_TWCR_TWSTA   5
#define TWI_TWCR_TWSTO   4
#define TWI_TWCR_TWWC    3
#define TWI_TWCR_TWEN    2
#define TWI_TWCR_TWIE    0

#define TWI_TWSR_TWS7    7
#define TWI_TWSR_TWS6    6
#define TWI_TWSR_TWS5    5
#define TWI_TWSR_TWS4    4
#define TWI_TWSR_TWS3    3
#define TWI_TWSR_TWPS1   1
#define TWI_TWSR_TWPS0   0


#define TWI_TWAR_TWGCE   0

/*Master TX*/
#define TWI_TXStartCondition       0x08
#define TWI_TXReStartCondition     0x10
#define TWI_TXSLAWACK              0x18
#define TWI_TXSLAWNotACK           0x20
#define TWI_TXDataACK              0x28
#define TWI_TXDataNotACK           0x30
/*Master Rx*/
#define TWI_RXStartCondition       0x08
#define TWI_RXReStartCondition     0x10
#define TWI_RXSLARACK              0x40
#define TWI_RXSLAWNotACK           0x48
#define TWI_RXDataACK              0x50
#define TWI_RXDataNotACK           0x58
















#endif /* MCAL_COMMUNICATION_TWI_TWI_PRIVATE_H_ */
