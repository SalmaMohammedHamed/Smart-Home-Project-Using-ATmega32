/*
 * GIE_Program.c
 *
 *  Created on: Sep 30, 2023
 *      Author: salma
 */

#include "GIE_Interface.h"
#define GIE_SREG    *((volatile u8*)0x5F)
#define GIE_I       7


void GIE_voidEnable()
{
	set_bit(GIE_SREG,GIE_I);
}

void GIE_voidDisable()
{
	clear_bit(GIE_SREG,GIE_I);
}

