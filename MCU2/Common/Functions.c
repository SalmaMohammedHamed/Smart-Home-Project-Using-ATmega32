/*
 * Special_Functios.c
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#include "Special_Functions.h"

void reverse(u8 str[], u16 length)
{
    u16 start = 0;
    u16 end = length - 1;
    while (start < end) {
        u8 temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

u8* int_to_string(u16 num, u8* str, u16 base)
{
    u16 i = 0;
    u16 isNegative = 0;

    // Handle 0 explicitly, otherwise empty string is printed
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // Handle negative numbers if the base is 10
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // Add negative sign for negative numbers
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Null-terminate the string

    // Reverse the string
    reverse(str, i);

return str ;
}


double power(f64 base, u16 exponent)
{
	f64 result = 1.0;

    if (exponent >= 0) {
        for (u16 i = 0; i < exponent; i++) {
            result *= base;
        }
    } else {
        for (u16 i = 0; i > exponent; i--) {
            result /= base;
        }
    }

    return result;
}


f64 LOG(f64 x) {
    if (x <= 0) {
        return -1.0; // Handle invalid input (log of non-positive number)
    }

    f64 result = 0.0;
    while (x >= 10.0) {
        x /= 10.0;
        result += 1.0;
    }

    f64 term = x - 1.0;
    f64 termPower = term;
    f64 denominator = 1.0;

    for (u16 i = 1; i < 50; i++) { // You can adjust the number of iterations for accuracy
        termPower *= term;
        denominator = i;
        if (i % 2 == 0) {
            result -= termPower / denominator;
        } else {
            result += termPower / denominator;
        }
    }

    return result;
}



