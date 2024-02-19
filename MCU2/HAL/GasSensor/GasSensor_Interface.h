/*
 * GasSensor_Interface.h
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#ifndef HAL_GASSENSOR_GASSENSOR_INTERFACE_H_
#define HAL_GASSENSOR_GASSENSOR_INTERFACE_H_
#include "GasSensor_Private.h"
#include "GasSensor_Config.h"
#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/definition.h"
#include "../../Common/Special_Functions.h"

void GasSensor_voidAnalogInit();
void GasSensor_voidDigitalInit();
void GasSensor_f32ReadAnalog(u8* Result , u16 Gas_id);
u8  GasSensor_u8DigitalState();


#endif /* HAL_GASSENSOR_GASSENSOR_INTERFACE_H_ */
