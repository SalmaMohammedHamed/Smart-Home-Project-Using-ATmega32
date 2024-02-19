/*
 * Lcd_config.h
 *
 *  Created on: Sep 15, 2023
 *      Author: hisha
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#include "../../MCAL/DIO/DIO_Interface.h"
#define Lcd_ControlGroup        DIO_GroupA
#define Lcd_RsPin				DIO_Pin0
#define Lcd_RwPin				DIO_Pin1
#define Lcd_EPin				DIO_Pin2
#define Lcd_DCGroup             DIO_GroupC
#define LcdMode                 8
#if(LcdMode==4)
#define Lcd_D4 DIO_Pin4
#define Lcd_D5 DIO_Pin5
#define Lcd_D6 DIO_Pin6
#define Lcd_D7 DIO_Pin7
#endif


#endif /* HAL_LCD_LCD_CONFIG_H_ */
