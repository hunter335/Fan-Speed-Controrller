/*-------------------------------------------------------------------------------------------------
File Name : LM35_sensor.c
Author : Mostafa Elsayad
Date Created :
Description : source File for the AVR LM35_sensor Driver
--------------------------------------------------------------------------------------------------*/

#include "LM35_sensor.h"
#include "adc.h"

/***********************************************FUNCTIONS DEFINITIONS***********************************************/

/*-------------------------------------------------------------------------------------------------------
Function Name : LM35_GetTemperature
Description : Function responsible for calculate the temperature from the ADC digital value.
Args :
[in]
void
return type:
uint8 : the temperature
--------------------------------------------------------------------------------------------------------*/
uint8 LM35_getTemperature(void){
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}
