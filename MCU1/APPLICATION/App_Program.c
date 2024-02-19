/*
 * App_Program.c
 *
 *  Created on: Sep 25, 2023
 *      Author: salma
 */

#include "../Common/STD_Types.h"
#include "../Common/definition.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/Timers/Timer0/T0_Interface.h"
#include "../MCAL/Timers/Timer2/T2_interace.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../HAL/Keypad/Keypad_Interface.h"
#include "../HAL/Lcd/Lcd_Interface.h"
#include "../HAL/ServoMotor/ServoMotor_Interface.h"
#include "../HAL/Buzzer/Buzzer_Interface.h"
#include "../HAL/Switch/Switch_Interface.h"
#include "../HAL/Led/Led_Interface.h"
#include "App_Program.h"
#include "App_Config.h"
#include "App.Private.h"
#include <util/delay.h>
u8 password_arr[password_len]; //array to store the correct password
u8 scan_password[password_len]; //array to store the scanned password
u8 NoPeople=0;//number of of people inside the house initially=0
u8 DoorPos=DoorClosed;//Door position initially is closed
void init ()
{
	UART_voidInit(UARTBoudeRate); //UART initialization
	_delay_ms(50); //delay it give UART enough time to be initialized
	UART_voidSendData(NoPeople); //send 0 at the begin ing
	KEYPAD_voidInit(); //Keypad initialization
	ServoMotor_voidInit(); //Servo Motor initialization
	BUZZER_voidInit();//Buzzer initialization
	SWITCH_voidInit(DIO_GroupD,OpenBUttonPin); //Initialize button at int0 pin
	SWITCH_voidInit(DIO_GroupD,ControlInButton);//Initialize button at int1 pin
	SWITCH_voidInit(DIO_GroupB,CLoseOutButton);//Initialize button at int2 pin
	EXTI0_CallBack(DoorControlFromInside); //set this function as a call back for the int0
	//to control the door from inside the home "highest priority"
	EXTI1_CallBack(user_interface);//set this function as a call back for the int1
	//to show user interface
	EXTI2_CallBack(CloseDoor); //set this function as a call back for the int2
	//to close the door from outside the house
	EXTI_voidInitINT0(Falling);//int0 initialization
	EXTI_voidInitINT1(Falling);//int1 initialization
	EXTI_voidInitINT2(Falling);//int2 initialization
	LCD_voidInit();//LCD initialization
	GIE_voidEnable(); //enable the global interrupt
}

void pass_arr()
{
	u32 password_temp=password;
	s8 counter=0;
	for (counter = password_len - 1; counter >= 0; counter--) {
		password_arr[counter] = password_temp % 10;
		password_temp /= 10;
	}
}

void read_password ()
{
	s8 counter=0;
	u8 res;
	LCD_voidSetPos(sec_line_pos,0);
	while(1)
	{
		res=KEYPAD_u8GetValue1();
		if (res!=Unpressed)
		{
			scan_password[counter]=res;
			LCD_voidSendData('#');//put # on the screen while entering the password
			_delay_ms(Keypad_delay);
			counter++;
		}
		if(counter>=password_len)
		{
			break;
		}
	}
}

u8 check_password ()
{
	s8 counter=0;
	for (counter=0;counter<password_len;counter++)
	{
		if(scan_password[counter]!=password_arr[counter])
		{
			return wrong;
		}
	}
	return correct;
}
void user_interface ()
{
	pass_arr();   //put the password in an array
	s8 counter=0;
	LCD_voidSetPos(first_line_pos,0);
	u8 EnterPass[]="Enter password";
	LCD_voidSendString(EnterPass);
	LCD_voidSetPos(sec_line_pos,0);
	counter=0;
	do
	{
		read_password();
		if (check_password()==correct)
		{
			CorrectPassword();
			break;
		}
		else
		{
			LCD_voidClear();
			LCD_voidSetPos(first_line_pos,3);
			u8 TryAgian[]="Try again!";
			LCD_voidSendString(TryAgian);
		}
		counter++;
	}while(counter<no_trials);
	if (counter>=no_trials)
	{
		WrongPassword();
	}

}

void CorrectPassword()
{
	LCD_voidClear();
	LCD_voidSetPos(first_line_pos,5);
	u8 Hello[]="HELLO";
	LCD_voidSendString(Hello);
	OpenDoorFromOutside();
	LCD_voidClear();//clear hello word after opening the door

}

void WrongPassword()
{
	LCD_voidClear();
	LCD_voidSetPos(first_line_pos,4);
	u8 w[]="WRONG";
	LCD_voidSendString(w); //print wrong
	//custom character array
	u8 customChar[] = {
		0b11011,
		0b11011,
		0b00000,
		0b10001,
		0b11111,
		0b01110,
		0b01110,
		0b00000
			};
	LCD_voidSpecialCharacter(0,customChar,first_line_pos,10); //print the custom character
	BUZZER_voidOn();///turn the buzzer on
	T0_voidCallBackFuncNormalMode(BuzzerOnTime);//set call back function timer0 to close the buzzer after certain time
	T0_voidNormalModeInit(prescaler8,0,enable);//start timer0 to close the buzzer after certain time

}

void CloseDoor()
{
	ServoMotor_voidAntiClockWiseSlow(90,0); //servo motor function to close the door from angle 90 to 0
	DoorPos=DoorClosed;//change the door position variable
}

void OpenDoorFromOutside()
{
	ServoMotor_voidClockWiseSlow(0,90);//servo motor function to open the door from angle 0 to 90
	DoorPos=DoorOpen;//change the door position variable
	NoPeople++;//increase the number of people variable
	UART_voidSendData(NoPeople);//send the number of people variable after the change
	T0_voidCallBackFuncNormalMode(DoorOpenTime);//set call back function timer0 to close the door after certain time
	T0_voidNormalModeInit(prescaler8,0,enable);//start timer0 to close the door after certain time
}

void OpenDoorFromInSide()
{
	ServoMotor_voidClockWiseSlow(0,90);//servo motor function to open the door from angle 0 to 90
	DoorPos=DoorOpen;//change the door position variable
	NoPeople--;//decrease the number of people variable
	UART_voidSendData(NoPeople);//send the number of people variable after the change
	T0_voidCallBackFuncNormalMode(DoorOpenTime);//set call back function timer0 to close the door after certain time
	T0_voidNormalModeInit(prescaler8,0,enable);//start timer0 to close the door after certain time
}

void DoorControlFromInside()
{
	if (NoPeople)
	{
		if (DoorPos==DoorOpen)
		{
			CloseDoor();//close the door from inside if it was open
		}
		else if (DoorPos==DoorClosed)
		{
			OpenDoorFromInSide();//open the door from inside if it was closed
		}
	}

}

void DoorOpenTime()
{
	static u32 counter=0;
	/*the door will close after about 5 seconds
	 if it wasn't already closed manually*/
	if (counter==DoorOPenT||counter==(DoorOPenT+10)||counter==(DoorOPenT+20))/*in case that any higher
		interrupt permitted the function from happening try to do it again in 10 clk cycles*/
	{
		if (DoorPos==DoorOpen)
		{
			CloseDoor();
		}
		T0_voidStop();//stop timer 0
		counter=0;
	}
	counter++;
}


void BuzzerOnTime()
{
	/*the warning buzzer will work and the word "wrong"
	 will appear on the screen for about 3 seconds*/
	static u32 counter=0;
	if (counter==BuzzerOnT||counter==(BuzzerOnT+10)||counter==(BuzzerOnT+20))/*in case that any higher
		interrupt permitted the function from happening try to do it again in 10 clk cycles*/
	{
		BUZZER_voidOff();
		LCD_voidClear();
		T0_voidStop();//stop timer 0
		counter=0;
	}
	counter++;
}



