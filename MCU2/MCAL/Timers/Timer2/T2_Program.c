/*
 * T2_Program.c
 *
 *  Created on: Dec 14, 2023
 *      Author: salma
 */

#include "T2_interace.h"
#include "../../../Common/definition.h"

/****************************Pointers to ISR functions************************************/
static void (*GlobalOVPF)(void)=NULL;//-> Global Pointer to Function Normal mode
static void (*GlobalCTCPF)(void)=NULL;//-> Global Pointer to Function CTC mode
/**********************************************************************************/



/**********************Normal Mode functions**********************************/
void T2_voidNormalModeInit(u8 Prescaller,u8 PreloadValue,u8 InterruptState)
{
	//select mode
	clear_bit(T2_TCCR2,T2_TCCR2_WGM20);
	clear_bit(T2_TCCR2,T2_TCCR2_WGM21);
	//Prescaller
	Prescaller&=0x07;
	T2_TCCR2&=0xF8;
	T2_TCCR2|=Prescaller;
	T2_TCNT2=PreloadValue;
	//Interrupt State
	if(InterruptState ==enable)
	{
		set_bit(T2_TIMSK,T2_TIMSK_TOIE2);
	}
	else if(InterruptState ==disable)
	{
		clear_bit(T2_TIMSK,T2_TIMSK_TOIE2);
	}

}


void T2_voidCallBackFuncNormalMode(void (*OVpf)(void))
{
	if (OVpf!=NULL)
	{
		GlobalOVPF=OVpf;
	}
}

void __vector_5(void)   __attribute__((signal));
void __vector_5(void)
{
	if(GlobalOVPF!=NULL)
	{
		GlobalOVPF();
	}
}
/*************************************************************************************/



/**************************************CTC*****************************************/
void T2_voidCTCModeInit(u8 OC2State ,u8 Prescaller,u8 CompareValue , u8 InterruptState)
{
	//select CTC Mode
	clear_bit(T2_TCCR2,T2_TCCR2_WGM20);
	set_bit(T2_TCCR2,T2_TCCR2_WGM21);

	//OC2 State
	if(OC2State==CTC_OC2_Disconnect)
	{//disconnect  pin OC0
		clear_bit(T2_TCCR2,T2_TCCR2_COM20);
		clear_bit(T2_TCCR2,T2_TCCR2_COM21);
	}
	else if (OC2State==CTC_OC2_Tog)
	{	//Tog Pin OC0
		set_bit(T2_TCCR2,T2_TCCR2_COM20);
		clear_bit(T2_TCCR2,T2_TCCR2_COM21);
	}
	else if (OC2State==CTC_OC2_CLr)
	{
		//clr Pin OC0
		clear_bit(T2_TCCR2,T2_TCCR2_COM20);
		set_bit(T2_TCCR2,T2_TCCR2_COM21);
	}
	else if (OC2State==CTC_OC2_Set)
	{
		//set Pin OC0
		set_bit(T2_TCCR2,T2_TCCR2_COM20);
		set_bit(T2_TCCR2,T2_TCCR2_COM21);
	}

	//Prescaller
	Prescaller&=0x07;
	T2_TCCR2&=0xF8;
	T2_TCCR2|=Prescaller;
	//Output compare
	T2_OCR2 = CompareValue;

	if(InterruptState ==enable)
	{
		set_bit(T2_TIMSK,T2_TIMSK_TOIE2);
	}
	else if(InterruptState ==disable)
	{
		clear_bit(T2_TIMSK,T2_TIMSK_TOIE2);
	}
}

void T2_voidCallBackFuncCTCMode(void (*CTCpf)(void))
{
	if (CTCpf!=NULL)
	{
		GlobalCTCPF=CTCpf;
	}
}

void __vector_4(void)   __attribute__((signal));
void __vector_4(void)
{
	if(GlobalCTCPF!=NULL)
	{
		GlobalCTCPF();
	}
}
/*************************************************************************************/

/**************************************PWM**************************************/
void T2_voidPWMModeInit(u8 PWMType, u8 OC2State ,u8 Prescaller, u8 DutyCycle)
{
	if (PWMType==FastPWM)
		{
			//fast PWM
			set_bit(T2_TCCR2,T2_TCCR2_WGM20);
			set_bit(T2_TCCR2,T2_TCCR2_WGM21);
			if (OC2State==PWM_OC2_Disconnect)
			{
				//disconnect  pin OC0
				clear_bit(T2_TCCR2,T2_TCCR2_COM20);
				clear_bit(T2_TCCR2,T2_TCCR2_COM21);
			}
			else if (OC2State==PWM_OC2_nonInverting)
			{
				//non-inverting mode
				clear_bit(T2_TCCR2,T2_TCCR2_COM20);
				set_bit(T2_TCCR2,T2_TCCR2_COM21);
				T2_OCR2=(255*DutyCycle)/100;
			}
			else if (OC2State==PWM_OC2_Inverting)
			{
				//inverting mode
				set_bit(T2_TCCR2,T2_TCCR2_COM20);
				set_bit(T2_TCCR2,T2_TCCR2_COM21);
				T2_OCR2=255*((1-DutyCycle)/100);
			}

			//Prescaller
			Prescaller&=0x07;
			T2_TCCR2&=0xF8;
			T2_TCCR2|=Prescaller;
		}
		else if (PWMType==PhaseCorrectPWM)
		{
			if (OC2State==PWM_OC2_Disconnect)
				{
					//disconnect  pin OC0
					clear_bit(T2_TCCR2,T2_TCCR2_COM20);
					clear_bit(T2_TCCR2,T2_TCCR2_COM21);
				}
			else if (OC2State==PWM_OC2_nonInverting)
				{
				//non-inverting mode
				clear_bit(T2_TCCR2,T2_TCCR2_COM20);
				set_bit(T2_TCCR2,T2_TCCR2_COM21);
				T2_OCR2=(255*DutyCycle)/100;
				}
			else if (OC2State==PWM_OC2_Inverting)
			{
				//inverting mode
				set_bit(T2_TCCR2,T2_TCCR2_COM20);
				set_bit(T2_TCCR2,T2_TCCR2_COM21);
				T2_OCR2=255*((1-DutyCycle)/100);
			}

			//Prescaller
			Prescaller&=0x07;
			T2_TCCR2&=0xF8;
			T2_TCCR2|=Prescaller;
		}

}
