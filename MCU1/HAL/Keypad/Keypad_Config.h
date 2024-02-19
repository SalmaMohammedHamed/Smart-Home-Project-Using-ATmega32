/*
 * Keypad_Config.h
 *
 *  Created on: Sep 9, 2023
 *      Author: salma
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_
#include "../../MCAL/DIO/DIO_Interface.h"
#define KeypadGroup DIO_GroupA
#define Row      4
#define Column   4
#define Pressed  0
#define Unpressed 255
#define KEYPAD_ARR1 \
    { \
        {1, 2, 3, 4}, \
        {5, 6, 7, 8}, \
        {9, 10, 11, 12}, \
        {13, 14, 15, 16} \
    }
#define KEYPAD_ARR2 \
    { \
        {'1','2','3','/'}, \
        {'4','5','6','*'}, \
        {'7','8','9','-'}, \
        {'R','0','C','+'} \
    }


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
