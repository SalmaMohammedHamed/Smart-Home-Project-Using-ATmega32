/*
 * LDR_Config.h
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#ifndef HAL_LDR_LDR_CONFIG_H_
#define HAL_LDR_LDR_CONFIG_H_

#include "../../Common/definition.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LDR_Private.h"

#define LDRGroup DIO_GroupA  //make sure it is a port with adc
#define LDRPin   DIO_Pin6
#define LDRMode  Polling

#define LDR_ADC_AutoTriggerState OFF
#define LDR_ADC_TriggerSource    OFF
#define LDR_ADC_DivisionFactor   Eight

#endif /* HAL_LDR_LDR_CONFIG_H_ */
