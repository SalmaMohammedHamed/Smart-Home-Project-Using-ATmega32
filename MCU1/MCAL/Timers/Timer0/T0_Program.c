/*
 * T0_Program.c
 *
 *  Created on: Nov 25, 2023
 *      Author:Salma
 */
#include "T0_Interface.h"
#include "../../../Common/definition.h"
/****************************Pointers to ISR functions************************************/
static void (*GlobalOVPF)(void)=NULL;//-> Global Pointer to Function Normal mode
static void (*GlobalCTCPF)(void)=NULL;//-> Global Pointer to Function CTC mode
/**********************************************************************************/




/*************************************Normal Mode functions***************************/
void T0_voidNormalModeInit(u8 Prescaller,u8 PreloadValue,u8 InterruptState)
{
	//select mode
	clear_bit(T0_TCCR0,T0_TCCR0_WGM00);
	clear_bit(T0_TCCR0,T0_TCCR0_WGM01);
	//Prescaller
	Prescaller&=0x07;
	T0_TCCR0&=0xF8;
	T0_TCCR0|=Prescaller;
	T0_TCNT0=PreloadValue;
	if(InterruptState ==enable)
	{
		set_bit(T0_TIMSK,T0_TIMSK_TOIE0);
	}
	else if(InterruptState ==disable)
	{
		clear_bit(T0_TIMSK,T0_TIMSK_TOIE0);
	}

}


void T0_voidCallBackFuncNormalMode(void (*OVpf)(void))
{
	if (OVpf!=NULL)
	{
		GlobalOVPF=OVpf;
	}
}


void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	if(GlobalOVPF!=NULL)
	{
		GlobalOVPF();
	}
}
/*************************************************************************************/




/**************************************CTC*****************************************/
void T0_voidCTCModeInit(u8 OC0State ,u8 Prescaller,u8 CompareValue , u8 InterruptState)
{
	clear_bit(T0_TCCR0,T0_TCCR0_WGM00);
	set_bit(T0_TCCR0,T0_TCCR0_WGM01);
	if(OC0State==CTC_OC0_Disconnect)
	{//disconnect  pin OC0
		clear_bit(T0_TCCR0,T0_TCCR0_COM00);
		clear_bit(T0_TCCR0,T0_TCCR0_COM01);
	}
	else if (OC0State==CTC_OC0_Tog)
	{	//Tog Pin OC0
		set_bit(T0_TCCR0,T0_TCCR0_COM00);
		clear_bit(T0_TCCR0,T0_TCCR0_COM01);
	}
	else if (OC0State==CTC_OC0_CLr)
	{
		//clr Pin OC0
		clear_bit(T0_TCCR0,T0_TCCR0_COM00);
		set_bit(T0_TCCR0,T0_TCCR0_COM01);
	}
	else if (OC0State==CTC_OC0_Set)
	{
		//set Pin OC0
		set_bit(T0_TCCR0,T0_TCCR0_COM00);
		set_bit(T0_TCCR0,T0_TCCR0_COM01);
	}
	//Prescaller
	Prescaller&=0x07;
	T0_TCCR0&=0xF8;
	T0_TCCR0|=Prescaller;
	//Output compare
	T0_OCR0 = CompareValue;
	if(InterruptState ==enable)
	{
		set_bit(T0_TIMSK,T0_TIMSK_TOIE0);
	}
	else if(InterruptState ==disable)
	{
		clear_bit(T0_TIMSK,T0_TIMSK_TOIE0);
	}

}


void T0_voidCallBackFuncCTCMode(void (*CTCpf)(void))
{
	if (CTCpf!=NULL)
	{
		GlobalCTCPF=CTCpf;
	}
}



void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
	if(GlobalCTCPF!=NULL)
	{
		GlobalCTCPF();
	}
}
/*************************************************************************************/




/**************************************PWM**************************************/
void T0_voidPWMModeInit(u8 PWMType, u8 OC0State ,u8 Prescaller, u8 DutyCycle)
{
	if (PWMType==FastPWM)
	{
		//fast PWM
		set_bit(T0_TCCR0,T0_TCCR0_WGM00);
		set_bit(T0_TCCR0,T0_TCCR0_WGM01);
		if (OC0State==PWM_OC0_Disconnect)
		{
			//disconnect  pin OC0
			clear_bit(T0_TCCR0,T0_TCCR0_COM00);
			clear_bit(T0_TCCR0,T0_TCCR0_COM01);
		}
		else if (OC0State==PWM_OC0_nonInverting)
		{
			//non-inverting mode
			clear_bit(T0_TCCR0,T0_TCCR0_COM00);
			set_bit(T0_TCCR0,T0_TCCR0_COM01);
			T0_OCR0=(255*DutyCycle)/100;
		}
		else if (OC0State==PWM_OC0_Inverting)
		{
			//inverting mode
			set_bit(T0_TCCR0,T0_TCCR0_COM00);
			set_bit(T0_TCCR0,T0_TCCR0_COM01);
			T0_OCR0=255*((1-DutyCycle)/100);
		}

		//Prescaller
		Prescaller&=0x07;
		T0_TCCR0&=0xF8;
		T0_TCCR0|=Prescaller;
	}
	else if (PWMType==PhaseCorrectPWM)
	{
		if (OC0State==PWM_OC0_Disconnect)
			{
				//disconnect  pin OC0
				clear_bit(T0_TCCR0,T0_TCCR0_COM00);
				clear_bit(T0_TCCR0,T0_TCCR0_COM01);
			}
		else if (OC0State==PWM_OC0_nonInverting)
			{
			//non-inverting mode
			clear_bit(T0_TCCR0,T0_TCCR0_COM00);
			set_bit(T0_TCCR0,T0_TCCR0_COM01);
			T0_OCR0=(255*DutyCycle)/100;
			}
		else if (OC0State==PWM_OC0_Inverting)
		{
			//inverting mode
			set_bit(T0_TCCR0,T0_TCCR0_COM00);
			set_bit(T0_TCCR0,T0_TCCR0_COM01);
			T0_OCR0=255*((1-DutyCycle)/100);
		}

		//Prescaller
		Prescaller&=0x07;
		T0_TCCR0&=0xF8;
		T0_TCCR0|=Prescaller;
	}

}
/***********************************************************************/
void T0_voidStop()
{
	T0_TCCR0&=0xF8;
}
