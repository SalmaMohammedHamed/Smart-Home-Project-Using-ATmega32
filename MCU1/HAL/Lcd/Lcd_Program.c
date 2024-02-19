/*
 * Lcd_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: hisha
 */
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Lcd_Interface.h"

void LCD_voidSendCommand(u8 command)
{
#if(LcdMode==8)
	//set the RS value as Low (command =>RS =  0 )
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RsPin,Low);
	//set the RW value as Low (Write  => RW = 0 )
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RwPin,Low);
	//set the E Value as High (High CLK)
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,High);
	//Send Command
		DIO_voidSetPortValue(Lcd_DCGroup,command);
	//Set the E value as Low (Low CLK)
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,Low);
#elif(LcdMode==4)
	//set the RS value as Low (command =>RS =  0 )
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RsPin,Low);
	//set the RW value as Low (Write  => RW = 0 )
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RwPin,Low);
	//set the E Value as High (High CLK)
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,High);
	//Send Command
		DIO_voidSetPinValue(Lcd_DCGroup,Lcd_D4,get_bit(command,4));
		DIO_voidSetPinValue(Lcd_DCGroup,Lcd_D5,get_bit(command,5));
		DIO_voidSetPinValue(Lcd_DCGroup,Lcd_D6,get_bit(command,6));
		DIO_voidSetPinValue(Lcd_DCGroup,Lcd_D7,get_bit(command,7));
	//Set the E value as Low (Low CLK)
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,Low);
#endif

}

void LCD_voidSendData(u8 data)
{
#if(LcdMode==8)
	//set the RS value as Low (Data =>RS =  1 )
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RsPin,High);
	//set the RW vlaue as Low (Write  => RW = 0 )
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RwPin,Low);
	//set the E Value as High (High CLK)
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,High);
	//Send Data
		DIO_voidSetPortValue(Lcd_DCGroup,data);
	//Set the E value as Low (Low CLK)
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,Low);
#elif(LcdMode==4)
	//set the RS value as Low (Data =>RS =  1 )
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RsPin,High);
	//set the RW vlaue as Low (Write  => RW = 0 )
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RwPin,Low);
	//set the E Value as High (High CLK)
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,High);
	//Send Data
		DIO_voidSetPortValue(Lcd_DCGroup,data);
	//Set the E value as Low (Low CLK)
		DIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,Low);

#endif

}


void LCD_voidInit()
{
#if(LcdMode==8)
	//set Direction
	DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_RsPin,Output);
	DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_RwPin,Output);
	DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_EPin,Output);
	DIO_voidSetPortDir(Lcd_DCGroup,0xff);
	//wait for 30ms
	_delay_ms(35);
	//sent the Function set
	LCD_voidSendCommand(LCD_Set8Bit2Line5x8);
	//wait for 39us
	_delay_ms(1);
	//sent the display
	LCD_voidSendCommand(LCD_8BitCursorBlinkON);
	//wait for 39us
	_delay_ms(1);
	//sent the Clear
	LCD_voidSendCommand(LCD_8BitClearDisplay);
	//wait for 1.53ms
	_delay_ms(2);
	//sent the EntryMode
	LCD_voidSendCommand(LCD_8BitEntryMode1);

#elif(LcdMode==4)
	//set Direction
		DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_RsPin,Output);
		DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_RwPin,Output);
		DIO_voidSetPinDir(Lcd_ControlGroup,Lcd_EPin,Output);
		DIO_voidSetPinDir(Lcd_DCGroup,Lcd_D4,Output);
		DIO_voidSetPinDir(Lcd_DCGroup,Lcd_D5,Output);
		DIO_voidSetPinDir(Lcd_DCGroup,Lcd_D6,Output);
		DIO_voidSetPinDir(Lcd_DCGroup,Lcd_D7,Output);
		//wait for 30ms
		_delay_ms(35);
		//sent the Function set
		LCD_voidSendCommand(first_command_to_set);
		LCD_voidSendCommand(first_command_to_set);
		LCD_voidSendCommand(LCD_Set4Bit2Line5x8);
		//wait for 39us
		_delay_ms(1);
		//sent the display
		LCD_voidSendCommand(first_command);
		LCD_voidSendCommand(LCD_4BitCursorBlinkON);
		//wait for 39us
		_delay_ms(1);
		//sent the Clear
		LCD_voidSendCommand(first_command);
		LCD_voidSendCommand(LCD_4BitClearDisplay);
		//wait for 1.53ms
		_delay_ms(2);
		//sent the EntryMode
		LCD_voidSendCommand(first_command);
		LCD_voidSendCommand(LCD_4BitEntryMode1);
#endif
}


void LCD_voidSendString(u8 String[])
{
	u8 i = 0 ;
	while(String[i]!='\0')
	{
		LCD_voidSendData(String[i]);
		i++;
	}
}


void LCD_voidSetPos(u8 x, u8 y)
{
	u8 adress;
	if (x==first_line_pos)
	{
		adress=y+first_line_add;
	}
	else if (x==sec_line_pos)
	{
		adress=y+sec_line_add;
	}
	LCD_voidSendCommand(adress|LCD_SetAddressDDRAM);
}

void LCD_voidSpecialCharacter (u8 block_no , u8 *special, u8 x, u8 y)
{
	u8 adress;
	u8 counter;
	adress = block_no*8;
	LCD_voidSendCommand(adress|LCD_SetAddressCGRAM);
	for (counter=0; counter<8;counter++)
	{
		LCD_voidSendData(special[counter]);
	}
	//go back to DDRAM
	LCD_voidSetPos(x,y);
	LCD_voidSendData(block_no);
}

void LCD_voidClear()
{
	LCD_voidSendCommand(LCD_8BitClearDisplay);
	//wait for 1.53ms
	_delay_ms(2);
}
void LCD_voidSendNumber(s32 num) {
    s8 counter;
    u8 length = 0;
    u8 StringStart = 0;
    u8 IsNegative = 0;
    u8 str[20];

    if (num < 0) {
        num = -num;
        IsNegative = 1;
        StringStart = 1;
        str[0] = '-';
        length++;
    }

    u32 temp_num = num;
    do {
        temp_num /= 10;
        length++;
    } while (temp_num > 0);

    for (counter = length - 1; counter >= StringStart; counter--) {
        str[counter] = num % 10 + '0';
        num /= 10;
    }
    str[length] = '\0';
    LCD_voidSendString(str);
}




