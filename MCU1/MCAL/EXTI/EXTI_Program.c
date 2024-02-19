/*
 * Interrupt_Program.c
 *
 *  Created on: Sep 30, 2023
 *      Author: salma
 */
#include "EXTI_Interface.h"
void (*EXTI0_ISR)();
void (*EXTI1_ISR)();
void (*EXTI2_ISR)();
void EXTI_voidInitINT0(u8 sense)
{
	if (sense==LowLevel)
	{
		clear_bit(EXTI_MCUCR,EXTI_ISC00);
		clear_bit(EXTI_MCUCR,EXTI_ISC01);
	}
	else if(sense==AnyCahnge)
	{
		set_bit(EXTI_MCUCR,EXTI_ISC00);
		clear_bit(EXTI_MCUCR,EXTI_ISC01);
	}
	else if(sense==Falling)
	{
		clear_bit(EXTI_MCUCR,EXTI_ISC00);
		set_bit(EXTI_MCUCR,EXTI_ISC01);
	}
	else if(sense==Rising)
	{
		set_bit(EXTI_MCUCR,EXTI_ISC00);
		set_bit(EXTI_MCUCR,EXTI_ISC01);
	}
	else
	{
		//error
	}
	set_bit(EXTI_GICR,EXTI_INT0);

}

void EXTI_voidInitINT1(u8 sense)
{
	if (sense==LowLevel)
	{
		clear_bit(EXTI_MCUCR,EXTI_ISC10);
		clear_bit(EXTI_MCUCR,EXTI_ISC11);
	}
	else if(sense==AnyCahnge)
	{
		set_bit(EXTI_MCUCR,EXTI_ISC10);
		clear_bit(EXTI_MCUCR,EXTI_ISC11);
	}
	else if(sense==Falling)
	{
		clear_bit(EXTI_MCUCR,EXTI_ISC10);
		set_bit(EXTI_MCUCR,EXTI_ISC11);
	}
	else if(sense==Rising)
	{
		set_bit(EXTI_MCUCR,EXTI_ISC10);
		set_bit(EXTI_MCUCR,EXTI_ISC11);
	}
	else
	{
		return;
	}
	set_bit(EXTI_GICR,EXTI_INT1);
}

void EXTI_voidInitINT2(u8 sense)
{
	if(sense==Rising)
	{
		set_bit(EXTI_MCUCSR,EXTI_ISC2);
	}
	else if (sense==Rising)
	{
		clear_bit(EXTI_MCUCSR,EXTI_ISC2);
	}
	else
	{

	}
	set_bit(EXTI_GICR,EXTI_INT2);
}

void EXTI0_CallBack (void (*ptr)(void))
{
    EXTI0_ISR = ptr;
}
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
	if(EXTI0_ISR!=NULL)
	{
		EXTI0_ISR();
	}
}

void EXTI1_CallBack (void (*ptr)(void))
{
    EXTI1_ISR = ptr;
}
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{
	if(EXTI1_ISR!=NULL)
	{
		EXTI1_ISR();
	}
}
void EXTI2_CallBack (void (*ptr)(void))
{
    EXTI2_ISR = ptr;
}
void __vector_3(void)   __attribute__((signal));
void __vector_3(void)
{
	if(EXTI2_ISR!=NULL)
	{
		EXTI2_ISR();
	}
}

