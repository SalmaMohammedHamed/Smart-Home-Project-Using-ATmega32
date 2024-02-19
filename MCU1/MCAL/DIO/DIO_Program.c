/*
 * DIO_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: salma
 */


#include "DIO_Praivte.h"
#include "DIO_Interface.h"


void DIO_voidSetPinDir(u8 Group_Type, u8 Pin_No, u8 DirStatus)
{
	//
	if((Group_Type>=DIO_GroupA && Group_Type<=DIO_GroupD)
			&& (Pin_No>=DIO_Pin0 && Pin_No<=DIO_Pin7) )
	{
		if(DirStatus==Input)
		{
			switch(Group_Type)
			{
			case DIO_GroupA: DIO_DDRA&=~(1<<Pin_No);break;
			case DIO_GroupB: DIO_DDRB&=~(1<<Pin_No);break;
			case DIO_GroupC: DIO_DDRC&=~(1<<Pin_No);break;
			case DIO_GroupD: DIO_DDRD&=~(1<<Pin_No);break;
			}
		}
		else if (DirStatus==Output)
		{
			switch(Group_Type)
			{
			case DIO_GroupA: DIO_DDRA|=(1<<Pin_No);break;
			case DIO_GroupB: DIO_DDRB|=(1<<Pin_No);break;
			case DIO_GroupC: DIO_DDRC|=(1<<Pin_No);break;
			case DIO_GroupD: DIO_DDRD|=(1<<Pin_No);break;
			}
		}
	}


}



void DIO_voidSetPinValue(u8 Group_Type, u8 Pin_No, u8 Value)
{
	if((Group_Type>=DIO_GroupA && Group_Type<=DIO_GroupD)
			&& (Pin_No>=DIO_Pin0 && Pin_No<=DIO_Pin7) )
	{
		if(Value==Low)
		{
			switch(Group_Type)
			{
			case DIO_GroupA: DIO_PORTA&=~(1<<Pin_No);break;
			case DIO_GroupB: DIO_PORTB&=~(1<<Pin_No);break;
			case DIO_GroupC: DIO_PORTC&=~(1<<Pin_No);break;
			case DIO_GroupD: DIO_PORTD&=~(1<<Pin_No);break;
			}
		}
		else if (Value==High)
		{
			switch(Group_Type)
			{
			case DIO_GroupA: DIO_PORTA|=(1<<Pin_No);break;
			case DIO_GroupB: DIO_PORTB|=(1<<Pin_No);break;
			case DIO_GroupC: DIO_PORTC|=(1<<Pin_No);break;
			case DIO_GroupD: DIO_PORTD|=(1<<Pin_No);break;
			}
		}
	}
}
u8 DIO_u8ReadPinValue(u8 Group_Type, u8 Pin_No)
{

	if((Group_Type>=DIO_GroupA && Group_Type<=DIO_GroupD)
			&& (Pin_No>=DIO_Pin0 && Pin_No<=DIO_Pin7) )
	{
		switch(Group_Type)
		{
		case DIO_GroupA: return((DIO_PINA>>Pin_No)&1);break;
		case DIO_GroupB: return((DIO_PINB>>Pin_No)&1);break;
		case DIO_GroupC: return((DIO_PINC>>Pin_No)&1);break;
		case DIO_GroupD: return((DIO_PIND>>Pin_No)&1);break;
		}
	}
	return -1;
}


void DIO_voidSetPortDir(u8 Group_Type , u8 DirStatus)
{
	if((Group_Type>=DIO_GroupA && Group_Type<=DIO_GroupD))
	{
		switch(Group_Type)
		{
		case DIO_GroupA:DIO_DDRA=DirStatus;break;
		case DIO_GroupB:DIO_DDRB=DirStatus;break;
		case DIO_GroupC:DIO_DDRC=DirStatus;break;
		case DIO_GroupD:DIO_DDRD=DirStatus;break;
		}
	}

}



void DIO_voidSetPortValue(u8 Group_Type , u8 Value)
{
	if((Group_Type>=DIO_GroupA && Group_Type<=DIO_GroupD))
	{
		switch(Group_Type)
		{
		case DIO_GroupA:DIO_PORTA=Value;break;
		case DIO_GroupB:DIO_PORTB=Value;break;
		case DIO_GroupC:DIO_PORTC=Value;break;
		case DIO_GroupD:DIO_PORTD=Value;break;
		}
	}

}


u8 DIO_U8ReadPortValue(u8 Group_Type)
{
	if((Group_Type>=DIO_GroupA && Group_Type<=DIO_GroupD))
	{
	switch(Group_Type)
		{
		case DIO_GroupA:return (DIO_PINA);break;
		case DIO_GroupB:return (DIO_PINB);break;
		case DIO_GroupC:return (DIO_PINC);break;
		case DIO_GroupD:return (DIO_PIND);break;
		}
	}
	return -1;

}

void DIO_voidControlPullupPin(u8 Group_Type,u8 Pin_No , u8 PullUp_Status)
{
	DIO_voidSetPinDir(Group_Type,Pin_No,Input);
	DIO_voidSetPinValue(Group_Type,Pin_No,PullUp_Status);
}











