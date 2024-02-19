/*
 * GasSensor_Config.h
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#ifndef HAL_GASSENSOR_GASSENSOR_CONFIG_H_
#define HAL_GASSENSOR_GASSENSOR_CONFIG_H_
#include "../../Common/definition.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "GasSensor_Private.h"

#define GasSensorGroup DIO_GroupA
#define GasSensorPin   DIO_Pin7
#define GasSensorMode  Polling

#define GasSensor_ADC_AutoTriggerState OFF
#define GasSensor_ADC_TriggerSource    OFF
#define GasSensor_ADC_DivisionFactor   Eight


#endif /* HAL_GASSENSOR_GASSENSOR_CONFIG_H_ */
