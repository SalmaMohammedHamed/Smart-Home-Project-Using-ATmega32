/*
 * Lcd_Private.h
 *
 *  Created on: Sep 15, 2023
 *      Author: hisha
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Function Set
RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
=== === === === === === === === === ===
 0   0   0   0   1   DL  N   F   *   *
*/

#define  LCD_Set4Bit1Line5x8         0x20     // the Data Will Send by 4 bit and the Number of line is 1 and the Font is 5x8
#define  LCD_Set4Bit1Line5x11        0x24     // the Data Will Send by 4 bit and the Number of line is 1 and the Font is 5x11
#define  LCD_Set4Bit2Line5x8	     0x28     // the Data Will Send by 4 bit and the Number of line is 2 and the Font is 5x8
#define  LCD_Set4Bit2Line5x11        0x2C     // the Data Will Send by 4 bit and the Number of line is 2 and the Font is 5x11
#define  LCD_Reset		             0x30     // the Data Will Send by 8 bit and the Number of line is 1 and the Font is 5x8
#define  LCD_Set8Bit1Line5x11    	 0x34     // the Data Will Send by 8 bit and the Number of line is 1 and the Font is 5x11
#define  LCD_Set8Bit2Line5x8     	 0x38     // the Data Will Send by 8 bit and the Number of line is 2 and the Font is 5x8
#define  LCD_Set8Bit2Line5x11    	 0x3C     // the Data Will Send by 8 bit and the Number of line is 2 and the Font is 5x11
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Display on/OFF and cursor*/
#define LCD_8BitDisplayOFF        0x08  // D = 0    C = 0    B = 0    The Display is Off so Will Cursor is off  And Blinking is OFF
#define LCD_8BitDisplayON         0x0C  // D = 1    C = 0    B = 0    The Display is On But the Cursor is OFF so the Blinking is OFF
#define LCD_8BitCursorON     	  0x0E
#define LCD_8BitCursorBlinkON     0x0F
#define LCD_8BitCursorOFF     	  0x0C

#define LCD_4BitDisplayOFF        0x80  // D = 0    C = 0    B = 0    The Display is Off so Will Cursor is off  And Blinking is OFF
#define LCD_4BitDisplayON         0xC0  // D = 1    C = 0    B = 0    The Display is On But the Cursor is OFF so the Blinking is OFF
#define LCD_4BitCursorON     	 0xE0
#define LCD_4BitCursorBlinkON     0xF0

/*------------------------------------------------------------------------------------------*/
/*Clear Display*/
#define LCD_8BitClearDisplay     0x01
#define LCD_4BitClearDisplay     0x10

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Entry Mode Set*/
#define LCD_8BitEntryMode1       0x06 //  S = 0 (no screen shifting) & I/D = 1 (Increment cursor position)   /*Increment cursor (shift cursor to right)*/
#define LCD_8BitEntryMode2       0x07 //  S = 1 (screen shifting) & I/D = 1 (Increment cursor position)   /*Increment cursor (shift cursor to right)*/
#define LCD_8BitEntryMode3       0x05 //  S = 1 (screen shifting) & I/D = 0 (Decrement cursor position)   /*Decrement cursor (shift cursor to lift)*/
#define LCD_8BitEntryMode4       0x04 //  S = 0 (no screen shifting) & I/D = 0 (Decrement cursor position)   /*Decrement cursor (shift cursor to lifts)*/

#define LCD_4BitEntryMode1      0x60 //  S = 0 (no screen shifting) & I/D = 1 (Increment cursor position)   /*Increment cursor (shift cursor to right)*/
#define LCD_4BitEntryMode2       0x70 //  S = 1 (screen shifting) & I/D = 1 (Increment cursor position)   /*Increment cursor (shift cursor to right)*/
#define LCD_4BitEntryMode3       0x50 //  S = 1 (screen shifting) & I/D = 0 (Decrement cursor position)   /*Decrement cursor (shift cursor to lift)*/
#define LCD_4BitEntryMode4       0x40 //  S = 0 (no screen shifting) & I/D = 0 (Decrement cursor position)   /*Decrement cursor (shift cursor to lifts)*/

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*Return Home*/
#define LCD_ReturnHome       0x02
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*Set CG RAM Address*/
#define  LCD_SetAddressCGRAM      0x40
/*---------------------------------------------------------------------------------------------------*/

/*Set DDRAM Address*/
#define  LCD_SetAddressDDRAM      0x80
/*---------------------------------------------------------------------------------------------------*/

/*lines*/

#define first_line_pos 0
#define first_line_add 0x00
#define sec_line_pos 1
#define sec_line_add 0x40

/*4bit*/
#define first_command_to_set 0x20
#define first_command        0x00


#endif /* HAL_LCD_LCD_PRIVATE_H_ */
