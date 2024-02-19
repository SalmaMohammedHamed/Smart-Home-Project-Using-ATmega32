/*
 * Application.h
 *
 *  Created on: Jan 30, 2024
 *      Author: salma
 */

#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_
#define UARTBoudeRate       9600
#define AirConditionerGroup DIO_GroupB
#define AirConditionerPin   DIO_Pin3
#define LightGroup          DIO_GroupD
#define LightPin            DIO_Pin7
#define FireExtigusherGruop DIO_GroupB
#define FireExtigusherPin   DIO_Pin2
/*Temperature levels*/
#define Temp1 25
#define Temp2 30
#define Temp3 35
#define Temp4 40
#define Temp5 45
/*Lighting levels*/
#define LightLevel1 2000
#define LightLevel2 1000
#define LightLevel3 500
#define LightLevel4 400

void Init();
void AirConditioner();
void LightSystem();
void FireFighterSystem();
void RecieveNoPeople();//ISR for the UART
void DecreaseNoPeople();


#endif /* APPLICATION_APPLICATION_H_ */
