/*
 * OS.c

 *
 *  Created on: Jan 30, 2024
 *      Author: salma
 */
#include "OS.h"
#include "../HAL/Lcd/Lcd_Interface.h"
static void (*funcArray[4])(void);

void OSFunc0(void (*Func0Ptr)(void))
{
	if (Func0Ptr!=NULL)
	{
		funcArray[0]=Func0Ptr;
	}
}


void OSFunc1(void (*Func1Ptr)(void))
{
	if (Func1Ptr!=NULL)
	{
		funcArray[1]=Func1Ptr;
	}
}


void OSFunc2(void (*Func2Ptr)(void))
{
	if (Func2Ptr!=NULL)
	{
		funcArray[2]=Func2Ptr;
	}
}


void OSCallBack()
{
	static u32 counter=0;
	if (counter%Func0Time==0)
	{
		if(funcArray[0]!=NULL)
		{
			funcArray[0]();
		}
	}
	if (counter%Func1Time==0)
	{
		if(funcArray[1]!=NULL)
		{
			funcArray[1]();
		}
	}
	if (counter%Func2Time==0)
	{
		if(funcArray[2]!=NULL)
		{
			funcArray[2]();
		}
	}

	counter++;
}
