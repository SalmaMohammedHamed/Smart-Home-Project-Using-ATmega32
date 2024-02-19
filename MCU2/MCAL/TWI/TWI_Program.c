/*
 * T0_Program.c
 *
 *  Created on: dec 2, 2023
 *      Author:salma
 */


#include "TWI_Interface.h"




/*Init*/
void TWI_voidMasterInit(void)
{
	//Bit Rate
	//Prescaller
	u8 Prescaller=TWI_Prescaller;
	Prescaller&=0x03;  //0000 0011
	TWI_TWSR&=0xFC;        //1111 1100
	//TWBR value
	TWI_TWBR=TWI_TWBR_value;
	//Enable ACK TWEA
	set_bit(TWI_TWCR,TWI_TWCR_TWEA);
	//Interrupt State
#if InterruptState==enable
	set_bit(TWI_TWCR,TWI_TWCR_TWIE);
#elif InterruptState==disable
	clear_bit(TWI_TWCR,TWI_TWCR_TWIE);
#endif
	//My Address
	TWI_TWAR=MyAdress;
	//Enable TWI
	set_bit(TWI_TWCR,TWI_TWCR_TWEN);

}
void TWI_voidSlaveInit()
{
	//Enable ACK TWEA
	set_bit(TWI_TWCR,TWI_TWCR_TWEA);
	//Interrupt State
#if InterruptState==enable
	set_bit(TWI_TWCR,TWI_TWCR_TWIE);
#elif InterruptState==disable
	clear_bit(TWI_TWCR,TWI_TWCR_TWIE);
#endif
	//My Address
	TWI_TWAR=MyAdress;
	//Enable TWI
	set_bit(TWI_TWCR,TWI_TWCR_TWEN);

}
/*************************************/
/*Start Condtion */
void TWI_voidStartCondition()
{
	//Clear_Flag (TWCR)
	set_bit(TWI_TWCR,TWI_TWCR_TWINT);
	//Set Start Condition
	set_bit(TWI_TWCR,TWI_TWCR_TWSTA);
	//Wait Flag on () when the Current Job Finish
	while (!get_bit(TWI_TWCR,TWI_TWCR_TWINT));
	//Check on the ACK (TWSR) -> TWI_StartCondition

}
void TWI_voidRestartCondition()
{
	//Clear_Flag (TWCR)
	//Set Start Condition Job
	//Wait Flag on () when the Current Job Finish
	//Check on the ACK (TWSR)-> TWI_ReStartCondition
}
/*************************************/
/*Stop Condtion */
void TWI_voidStopCondition()
{
	//Clear_Flag
	// Enable Stop Condition
}
/*************************************/
/*Slave Address */
void TWI_voidSendSlAWithWrite(u8 DestinationAddress)
{	 	//Sent the Destiantion
	//TWDR-> Sent Any thing (DestinationAddress and Write Date and Read Data)
		//TWDR = DestinationAddress + 0 ->Write
	//Clear_Falg
	//Wait Flag on () when the Current Job Finish (Sent the SLA/W )
	//Check on the ACK (TWSR) -> TWI_SLAWACK

}
void TWI_voidSendSlAWithRead(u8 DestinationAddress)
{
	//Sent the Destiantion +Read
	//TWDR-> Sent Any thing (DestinationAddress and Write Date and Read Data)
		//TWDR = DestinationAddress + 1 ->Read
	//Clear_Falg
	//Wait Flag on () when the Current Job Finish (Sent the SLA/A )
	//Check on the ACK (TWSR) -> TWI_SLARACK
}
/*************************************/
/*Data Byte */
void TWI_voidWriteDataByte(u8 Data)
{
	//Write Data Byte in TWDR
	//Clr Flag
	//wait Flag on () when the Current Job Finish (Write Byte)
	//Check on the ACK (TWSR) -> TWI_Tx_DataACK

}// Take this Value
void TWI_voidReadDataByte(u8 *Data)
{
	//Clr Flag
	//wait Flag on () when the Current Job Finish (Read Byte)
	//Check on the ACK (TWSR) -> TWI_Rx_DataACK
	//Read Data From TWDR And Store it in side Pointer

}

