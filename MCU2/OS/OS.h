/*
 * OS.h
 *
 *  Created on: Jan 30, 2024
 *      Author: salma
 */

#ifndef OS_OS_H_
#define OS_OS_H_
#include "../Common/Bit_Math.h"
#include "../Common/STD_Types.h"
#include "../Common/definition.h"
#include "OSConfig.h"
void OSFunc0(void (*Func0Ptr)(void));
void OSFunc1(void (*Func1Ptr)(void));
void OSFunc2(void (*Func2Ptr)(void));
void OSCallBack();

#endif /* OS_OS_H_ */
