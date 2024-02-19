/*
 * GasSensor_Program.c
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#include "GasSensor_Interface.h"
#include "../../Common/Special_Functions.h"
#include "GasSensor_Private.h"

f32 LPGCurve[2] ={2.5279 , 1.8771};
f32 CHCurve[2]  ={2.5474 , 2.2636};
f32 HCurve[2]   ={4.2302 , 3.0935};
f32 ALCOHOLCurve[2] ={4.5008 , 4.8216};
f32 COCurve[2]     ={7.358 ,  6.4758};

void GasSensor_voidAnalogInit()
{
	DIO_voidSetPinDir(GasSensorGroup,GasSensorPin,Input);
}


void GasSensor_f32ReadAnalog(u8* Result , u16 Gas_id)
{

	u16 read  = 0 ;
    f32 sensor_volt = 0 ;
    f32 sensorValue = 0 ;
    f32 ratio;
	 for(int x = 0 ; x < 10 ; x++)
	 {
#if GasSensorMode==Polling
		 ADC_voidReadResultPolling(GasSensorPin,&read);
#elif GasSensorMode==Interrupt
    //
#endif
		 sensorValue = sensorValue + (f32)read ;
		 	        }

	 sensorValue = sensorValue/10.0;
     sensor_volt = (sensorValue/1024);
    switch(Gas_id)
    {
    case LPG_Gas : ratio = GetGasPercentage(sensor_volt , LPG_Gas);break;
    case CH_Gas : ratio =  GetGasPercentage(sensor_volt , CH_Gas);break;
    case H_Gas :ratio =  GetGasPercentage(sensor_volt , H_Gas);break;
    case ALCOHOL_Gas :ratio =  GetGasPercentage(sensor_volt , ALCOHOL_Gas);break;
    case CO_Gas :ratio =  GetGasPercentage(sensor_volt , CO_Gas);break;
    case Freash_Air :ratio = (1-sensor_volt)*100 ;break;
    case SMOKE    : ratio = sensor_volt *100; break;
    default:break;
    }

    int_to_string((u16)ratio,Result,10);



}

f32 GetGasPercentage(f32 ratio, u16 Gas_id)
{

	u8 Str = "0";
	f32 Result = 0 ;
    switch(Gas_id)
    {
    case LPG_Gas : Result = (LPGCurve[0]*LOG(1-ratio) + LPGCurve[1]) ;break;
    case CH_Gas : Result =  (CHCurve[0]*LOG(1-ratio) + CHCurve[1]);break;
    case H_Gas :Result =  (HCurve[0]*LOG(1-ratio) + HCurve[1]);break;
    case ALCOHOL_Gas :Result = (ALCOHOLCurve[0]*LOG(1-ratio) + ALCOHOLCurve[1]);break;
    case CO_Gas :Result = (COCurve[0]*LOG((1-ratio)) + COCurve[1]);break;
    default:break;
    }

  return Result;
}



void GasSensor_voidDigitalInit()
{
	DIO_voidSetPinDir(GasSensorGroup,GasSensorPin,Input);
	//DIO_voidControlPullupPort(GasSensorGroup,GasSensorPin);
	DIO_voidSetPinValue(GasSensorGroup,GasSensorPin,HIGH);
}

u8 GasSensor_u8DigitalState()
{
	return DIO_u8ReadPinValue(GasSensorGroup,GasSensorPin);
}
