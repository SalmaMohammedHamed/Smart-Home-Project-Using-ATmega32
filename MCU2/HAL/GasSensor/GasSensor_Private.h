/*
 * GasSensor_Private.h
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#ifndef HAL_GASSENSOR_GASSENSOR_PRIVATE_H_
#define HAL_GASSENSOR_GASSENSOR_PRIVATE_H_

#include "../../Common/STD_Types.h"



f32 GetGasPercentage(f32 ratio, u16 Gas_id);
#define LPG_Gas        0
#define CH_Gas         1
#define H_Gas          2
#define ALCOHOL_Gas    3
#define CO_Gas         4
#define Freash_Air     5
#define SMOKE          6
#define Polling 1
#define Interrupt 2
#endif /* HAL_GASSENSOR_GASSENSOR_PRIVATE_H_ */
