/*
 * LM35_Config.h
 *
 *  Created on: Oct 22, 2023
 *      Author: salma
 */

#ifndef HAL_LM35_LM35_CONFIG_H_
#define HAL_LM35_LM35_CONFIG_H_
#include "LM35_Private.h"
#include "../../Common/definition.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#define LM35Group DIO_GroupA  //make sure it is a port with adc
#define LM35Pin  DIO_Pin5




#endif /* HAL_LM35_LM35_CONFIG_H_ */
