/*
 * ServoMotor_Program.c
 *
 *  Created on: Dec 10, 2023
 *      Author: salma
 */
#include "ServoMotor_Interface.h"
#include <util/delay.h>
void ServoMotor_voidInit()
{
	DIO_voidSetPinDir(DIO_GroupD,DIO_Pin5,output);
	T1_voidFastPWMServoInit();
}
void ServoMotor_voidSetAngle(u8 angle)
{
	u16 position;
	position = 1000 + ((f32)((f32)angle/MaxAngle))*1000;
	T1_voidFastPWMServoSetAngle(position);
}

void ServoMotor_voidClockWiseSlow(u8 StartAngle,u8 StopAngle)
{
	u16 StartAnglePosition;
	u16 StopAnglePosition;

	StartAnglePosition=1200 + ((f32)((f32)StartAngle/MaxAngle))*1000;
	StopAnglePosition=1200+ ((f32)((f32)StopAngle/MaxAngle))*1000;
	for (u16 i =StartAnglePosition ; i<=StopAnglePosition;i+=5){
		T1_voidFastPWMServoSetAngle(i);
		_delay_ms(15);
	}
}


void ServoMotor_voidAntiClockWiseSlow(u8 StartAngle,u8 StopAngle)
{
	u16 StartAnglePosition;
	u16 StopAnglePosition;
	StartAnglePosition=600 + ((f32)((f32)StartAngle/MaxAngle))*1000;
	StopAnglePosition=600 + ((f32)((f32)StopAngle/MaxAngle))*1000;
	for (u16 i =StartAnglePosition ; i>=StopAnglePosition ;i-=5){
		T1_voidFastPWMServoSetAngle(i);
		_delay_ms(15);
	}
}

