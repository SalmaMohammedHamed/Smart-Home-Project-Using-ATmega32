/*
 * Application.c
 *
 *  Created on: Jan 30, 2024
 *      Author: salma
 */
#include "../MCAL/Timers/Timer2/T2_interace.h"
#include "../MCAL/Timers/Timer0/T0_Interface.h"
#include "../MCAL/Timers/Timer1/T1_interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../Common/Bit_Math.h"
#include "../Common/STD_Types.h"
#include "../Common/definition.h"
#include "../HAL/Relay/Relay.h"
#include "../HAL/Buzzer/Buzzer_Interface.h"
#include "../HAL/GasSensor/GasSensor_Interface.h"
#include "../HAL/LDR/LDR_Interface.h"
#include "../HAL/LM35/LM35_Interface.h"
#include "../HAL/Lcd/Lcd_Interface.h"
#include "../OS/OS.h"
#include "Application.h"
#include <util/delay.h>
#include "../HAL/Led/Led_Interface.h"
u8 NoPeople=0;
void Init()
{
	GasSensor_voidDigitalInit(); //gas sensor initialization
	LDR_voidInit();//LDR initialization
	LM35_voidInit();//LM35 initialization
	ADC_voidInit();//ADC initialization
	LCD_voidInit();//LCD initialization
	UART_voidInit(UARTBoudeRate);//UART initialization
	UART_voidCallBack(RecieveNoPeople);//set the ISR of UART
	BUZZER_voidInit();//Buzzer initialization
	DIO_voidSetPinDir(FireExtigusherGruop,FireExtigusherPin,output);//fire extinguisher initialization
	/*set the OS layer functions*/
	OSFunc0(FireFighterSystem);
	OSFunc1(LightSystem);
	OSFunc2(AirConditioner);
	T1_voidCallBackFuncNormalMode(OSCallBack);
	T1_voidNormalModeInit(prescaler8,0,enable);//start timer one to control OS layer
	GIE_voidEnable();//global interrupt enable

}

void AirConditioner()
{

	if (NoPeople)
	{
		u16 temp;
		LM35_voidRead(&temp);
		LCD_voidSetPos(5,0);
		LCD_voidSendNumber(temp);
		if (temp<=Temp1)
		{
			T0_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,0);
		}
		else if (temp>Temp1 && temp<=Temp2)
		{
			T0_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,25);
		}
		else if (temp>Temp2 && temp<=Temp3)
		{
			T0_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,50);
		}
		else if (temp>Temp3 && temp<=Temp4)
		{
			T0_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,75);
		}
		else if (temp>Temp4 && temp<=Temp5)
		{
			T0_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,85);
		}
		else if (temp>Temp5)
		{
			DIO_voidSetPinDir(AirConditionerGroup,AirConditionerPin,output);
			DIO_voidSetPinValue(AirConditionerGroup,AirConditionerPin,High);
		}
	}
	else if(NoPeople==0)
	{
		T0_voidStop();
		DIO_voidSetPinDir(AirConditionerGroup,AirConditionerPin,output);
		DIO_voidSetPinValue(AirConditionerGroup,AirConditionerPin,Low);
	}

}


void LightSystem()
{

	if (NoPeople)
	{
		u16 Light;
		LDR_voidRead(&Light);
		LCD_voidSetPos(0,0);
		LCD_voidSendNumber(Light);
		if (Light>=LightLevel1)
			{
				T2_voidStop();
				DIO_voidSetPinDir(LightGroup,LightPin,output);
				DIO_voidSetPinValue(LightGroup,LightPin,Low);
			}
			else if (Light<LightLevel1 && Light>=LightLevel2)
			{
				T2_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,25);
			}
			else if (Light<LightLevel2 && Light>=LightLevel3)
			{
				T2_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,50);
			}
			else if (Light<LightLevel3 && Light>=LightLevel4)
			{
				T2_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,75);
			}
			else if (Light<LightLevel3)
			{
				T2_voidStop();
				DIO_voidSetPinDir(LightGroup,LightPin,output);
				DIO_voidSetPinValue(LightGroup,LightPin,High);
			}
	}
	else if (NoPeople==0)
	{
		T2_voidStop();
		DIO_voidSetPinDir(LightGroup,LightPin,output);
		DIO_voidSetPinValue(LightGroup,LightPin,Low);
	}


}

void FireFighterSystem()
{

		if (GasSensor_u8DigitalState())
		{
			LED_voidOn(FireExtigusherGruop,FireExtigusherPin);
			BUZZER_voidOn();
		}
		else
		{
			LED_voidOff(FireExtigusherGruop,FireExtigusherPin);
			BUZZER_voidOff();
		}
}

void RecieveNoPeople()
{

	NoPeople=UART_u8RecieveDataInt();
	LCD_voidSetPos(1,0);
	LCD_voidSendNumber(NoPeople);

}
