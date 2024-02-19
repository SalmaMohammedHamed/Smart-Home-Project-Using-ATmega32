/*
 * Special_Functions.h
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#ifndef COMMON_SPECIAL_FUNCTIONS_H_
#define COMMON_SPECIAL_FUNCTIONS_H_
#include "Std_Types.h"


void reverse(u8 str[], u16 length);
u8* int_to_string(u16 num, u8* str, u16 base);
f64 power(f64 base, u16 exponent);
f64 LOG(f64 x);

#endif /* COMMON_SPECIAL_FUNCTIONS_H_ */
