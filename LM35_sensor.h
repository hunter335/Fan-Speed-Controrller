/*-------------------------------------------------------------------------------------------------
File Name : LM35_sensor.h
Author : Mostafa Elsayad
Date Created :
Description : header File for the AVR LM35_sensor Driver
--------------------------------------------------------------------------------------------------*/
#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/***********************************************DEFINITIONS***********************************************/
#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/***********************************************FUNCTIONS PROTOTYPES***********************************************/

/*-------------------------------------------------------------------------------------------------------
Function Name : LM35_GetTemperature
Description : Function responsible for calculate the temperature from the ADC digital value.
Args :
[in]
void
return type:
uint8 : the temperature
--------------------------------------------------------------------------------------------------------*/
uint8 LM35_getTemperature(void);
#endif /* LM35_SENSOR_H_ */
