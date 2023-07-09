/*-------------------------------------------------------------------------------------------------
File Name : adc.h
Author : Mostafa Elsayad
Date Created :
Description : header File for the AVR ADC Driver
--------------------------------------------------------------------------------------------------*/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/***********************************************DEFINITIONS***********************************************/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/***********************************************TYPES DECLERATION***********************************************/

/*-------------------------------------------------------------------------------------------------------
 Enum Name : ADC_ReferenceVolatge
 Enum Description : This Enum is responsible for assign reference voltage to values
--------------------------------------------------------------------------------------------------------*/
typedef enum{
	AREF,AVCC,RESERVED,INTERNAL_AREF
}ADC_ReferenceVolatge;

/*-------------------------------------------------------------------------------------------------------
 Enum Name :  ADC_Prescaler
 Enum Description : This Enum is responsible for assign Prescaler to values
--------------------------------------------------------------------------------------------------------*/
typedef enum {
	DIV_FACTOR_BY_2,DIV_FACTOR_BY_4,DIV_FACTOR_BY_8,DIV_FACTOR_BY_16,DIV_FACTOR_BY_32,DIV_FACTOR_BY_64,DIV_FACTOR_BY_128
}ADC_Prescaler;

/*-------------------------------------------------------------------------------------------------------
 Struct Name : ADC_ConfigType
 Enum Description : This struct is responsible for maintaining information about ADC_ConfigType
--------------------------------------------------------------------------------------------------------*/
typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/***********************************************TYPES DECLERATION***********************************************/

/*-------------------------------------------------------------------------------------------------------
Function Name : ADC_init
Description :Function responsible for initialize the ADC driver.
Args :
[in]
const ADC_ConfigType * Config_Ptr
[out]
void
--------------------------------------------------------------------------------------------------------*/
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*-------------------------------------------------------------------------------------------------------
Function Name : ADC_readChannel
Description :Function responsible for read analog data from a certain ADC channel and convert it to digital using the ADC driver.
Args :
[in]
uint8 channel_num : number of the channel will be read
[out]
uint16 :
--------------------------------------------------------------------------------------------------------*/
uint16 ADC_readChannel (uint8 channel_num);
#endif /* ADC_H_ */
