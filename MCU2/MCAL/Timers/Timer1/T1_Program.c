/*
 * T0_Program.c
 *
 *  Created on: Nov 25, 2023
 *      Author:Salma
 */
#include "T1_interface.h"
#include "../../../Common/definition.h"



/****************************Pointers to ISR functions************************************/
static void(*GlobalICUPf)(void)=NULL;
static void(*GlobalOVPf)(void)=NULL;
static void(*GlobalOCAPf)(void)=NULL;
static void(*GlobalOCBPf)(void)=NULL;
/***************************************************************************************/



/*******************************Normal Mode Functions*******************************************/
void T1_voidNormalModeInit(u8 Prescaller,u8 PreloadValue,u8 InterruptState)
{
	//select mode
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
	clear_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
	clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	//Prescaller
	Prescaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=Prescaller;
	T1_TCNT1=PreloadValue;
	if(InterruptState ==enable)
	{
		set_bit(T1_TIMSK,T1_TIMSK_TOIE1);
	}
	else if(InterruptState ==disable)
	{
		clear_bit(T1_TIMSK,T1_TIMSK_TOIE1);
	}

}


void T1_voidCallBackFuncNormalMode(void (*Normalpf)(void))
{
	if(Normalpf!=NULL)
	{
		GlobalOVPf=Normalpf;
	}
}


void __vector_9(void)   __attribute__((signal));
void __vector_9(void)
{

	if (GlobalOVPf!=NULL)
	{
		GlobalOVPf();
	}

}
/***************************************************************************/





/********************************CTC Functions****************************************************/
void T1_voidCTCModeInit(u8 Prescaller,u16 CompareValue,u8 Interruptstate,u8 OC1AState)
{
	//select mode
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
	set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
	set_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	T1_ICR1=CompareValue;
	if (Interruptstate==enable)
	{
		set_bit(T1_TIMSK,T1_TIMSK_OCIE1A);
	}
	else if (Interruptstate==disable)
	{
		clear_bit(T1_TIMSK,T1_TIMSK_OCIE1A);
	}
	if(OC1AState==CTC_OC1A_Disconnect)
	{//disconnect  pin OC0
		clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
		clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
	}
	else if (OC1AState==CTC_OC1A_Tog)
	{	//Tog Pin OC0
		set_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
		clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
	}
	else if (OC1AState==CTC_OC1A_CLr)
	{
		//clr Pin OC0
		clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
		set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
	}
	else if (OC1AState==CTC_OC1A_Set)
	{
		//set Pin OC0
		set_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
		set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
	}
	Prescaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=Prescaller;
}


void T1_voidCallBackFuncOCA(void (*CTCApf)(void))
{
	if(CTCApf!=NULL)
	{
		GlobalOCAPf=CTCApf;
	}
}


void __vector_7(void)   __attribute__((signal));
void __vector_7(void)
{

	if (GlobalOCAPf!=NULL)
	{
		GlobalOCAPf();
	}
}


void T1_voidCallBackFuncOCB(void (*CTCBpf)(void))
{
	if(CTCBpf!=NULL)
	{
		GlobalOCBPf=CTCBpf;
	}
}


void __vector_8(void)   __attribute__((signal));
void __vector_8(void)
{

	if (GlobalOCBPf!=NULL)
	{
		GlobalOCBPf();
	}
}
/************************************************************************************/




/*******************************Fast PWM*********************************/
void T1_voidFastPWMFixedTop(u8 Type,u8 PreScaller ,u8 PWMMode , u8 DutyCycle)
{
	//prescaller
	PreScaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=PreScaller;
	//select mode
	if (PWMMode==NonInverting)
	{
		clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
		set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
	}
	else if (PWMMode==Inverting)
	{
		set_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
		set_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
	}
	//select Type & set duty cycle
	if (Type==FastPWM_8Bit)
	{
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
		clear_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
		clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
		if (PWMMode==Inverting)
		{
			T1_OCR1A = (FastPWM_8BitTopValue*(100-DutyCycle))/100;
		}
		if (PWMMode==NonInverting)
		{
			T1_OCR1A = (FastPWM_8BitTopValue*DutyCycle)/100;
		}
	}
	else if (Type==FastPWM_9Bit)
	{
		clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
		clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
		if (PWMMode==Inverting)
		{
			T1_OCR1A = (FastPWM_9BitTopValue*(100-DutyCycle))/100;
		}
		if (PWMMode==NonInverting)
		{
			T1_OCR1A = (FastPWM_9BitTopValue*DutyCycle)/100;
		}
	}
	else if (Type==FastPWM_10Bit)
	{
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
		clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
		if (PWMMode==Inverting)
		{
			T1_OCR1A = (FastPWM_10BitTopValue*(100-DutyCycle))/100;
		}
		if (PWMMode==NonInverting)
		{
			T1_OCR1A = (FastPWM_10BitTopValue*DutyCycle)/100;
		}
	}

}


void T1_voidFastPWMSetTop(u8 Type,u8 PreScaller ,u8 PWMMode ,u16 TopValue, u8 DutyCycle)
{
	//prescaller
		PreScaller&=0x07;
		T1_TCCR1B&=0xF8;
		T1_TCCR1B|=PreScaller;
		//select mode
		if (PWMMode==NonInverting)
		{
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (PWMMode==Inverting)
		{
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}

		//select Type & set duty cycle & Set top value
		if (Type==FastPWM_ICR1)
		{
			clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
			set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
			set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
			set_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
			T1_ICR1=TopValue;
			if (PWMMode==Inverting)
			{
				T1_OCR1A = (TopValue*(100-DutyCycle))/100;
			}
			else if (PWMMode==NonInverting)
			{
				T1_OCR1A = (TopValue*DutyCycle)/100;
			}
		}
		else if (Type==FastPWM_OCR1A)
		{
			set_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
			set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
			set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
			set_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
			T1_OCR1A=TopValue;
			if (PWMMode==Inverting)
			{
				T1_OCR1B = (TopValue*(100-DutyCycle))/100;
			}
			else if (PWMMode==NonInverting)
			{
				T1_OCR1B = (TopValue*DutyCycle)/100;
			}
		}
}
/**************************************************************************/





/****************************Servo Functions*************************/
void T1_voidFastPWMServoInit()
{
	//COM1A1/COM1B1 COM1A0/COM1B0  1 0 Clear OC1A/OC1B on compare match, set  OC1A/OC1B at TOP
	clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
	set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);

	/*WGM13 WGM12	WGM11	WGM10	Timer/Counter Mode of Operation TOP Update of OCR1x	TOV1 Flag Set 	on
      1      1       1        0        Fast PWM                      ICR1 TOP TOP*/
	set_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
	set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);

	//PreScaller
	u8 PreScaller=prescaler8;
	PreScaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=PreScaller;


	T1_ICR1=Servo_value;


}

void T1_voidFastPWMServoSetAngle(u16 angle)
{
	T1_OCR1A=angle;
	}
/******************************************************************/





/***********************ICU functions*******************************/
void T1_voidICUInit(void)
{
	u8 Prescaller=prescaler8;
	//NormalMode
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
	clear_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
	clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	//Prescaller
	Prescaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=Prescaller;
	//Set ICU Bit to Rising
	set_bit(T1_TCCR1B,T1_TCCR1B_ICES1);
	//Enable ICU Interrupt
	set_bit(T1_TIMSK,T1_TIMSK_TICIE1);
	}


void T1_voidCallBackFuncICUMode(void (*ICUpf)(void))
{
	if(ICUpf!=NULL)
	{
		GlobalICUPf=ICUpf;
	}
}


void __vector_6(void)   __attribute__((signal));
void __vector_6(void)
{

	if (GlobalICUPf!=NULL)
	{
		GlobalICUPf();
	}

}
/*********************************************************************/

