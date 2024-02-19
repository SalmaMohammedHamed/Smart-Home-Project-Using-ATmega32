/*
 * Bit_Math.h
 *
 *  Created on: Sep 9, 2023
 *      Author: salma
 */

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_
#define set_bit(reg,bit)  reg|=(1<<bit)
#define clear_bit(reg,bit)  reg&=~(1<<bit)
#define toggle_bit(reg,bit)  reg^=(1<<bit)
#define get_bit(reg,bit)  ((reg>>bit)&1)


#endif /* COMMON_BIT_MATH_H_ */
