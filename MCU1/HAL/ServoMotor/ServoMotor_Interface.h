/*
 * ServoMotor_Interface.h
 *
 *  Created on: Dec 10, 2023
 *      Author: salma
 */

#ifndef HAL_SERVOMOTOR_SERVOMOTOR_INTERFACE_H_
#define HAL_SERVOMOTOR_SERVOMOTOR_INTERFACE_H_
#include "../../MCAL/Timers/Timer1/T1_interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "ServoMotor_Config.h"
#include "../../Common/STD_Types.h"
#include "../../Common/definition.h"
void ServoMotor_voidInit();
void ServoMotor_voidSetAngle(u8 angle);
void ServoMotor_voidClockWiseSlow(u8 StartAngle,u8 StopAngle);
void ServoMotor_voidAntiClockWiseSlow(u8 StartAngle,u8 StopAngle);



#endif /* HAL_SERVOMOTOR_SERVOMOTOR_INTERFACE_H_ */
