/*-------------------------------------------------------------------------------------------------
File Name : adc.c
Author : Mostafa Elsayad
Date Created :
Description : source File for the AVR ADC Driver
--------------------------------------------------------------------------------------------------*/
#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "gpio.h"

/***********************************************FUNCTIONS DEFINITIONS***********************************************/

/*-------------------------------------------------------------------------------------------------------
Function Name : ADC_init
Description :Function responsible for initialize the ADC driver.
Args :
[in]
const ADC_ConfigType * Config_Ptr
[out]
void
--------------------------------------------------------------------------------------------------------*/
void ADC_init(const ADC_ConfigType * Config_Ptr){
	/* ADMUX Register Bits Description:
	 * REFS0 =1
	 * REFS1 =1
	 * ADLAR =0*/
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr -> ref_volt )<<REFS0);
	/*ADCSRA Register Bits Description:
	 * ADEN=1
	 * ADATE=0
	 * ADIF=0
	 * ADIE=0
	 * ADPS0=1,ADPS1=1*/
	 ADCSRA=(1<<ADEN);
	 ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr -> prescaler)&0x07);
}

/*-------------------------------------------------------------------------------------------------------
Function Name : ADC_readChannel
Description :Function responsible for read analog data from a certain ADC channel and convert it to digital using the ADC driver.
Args :
[in]
uint8 channel_num : number of the channel will be read
[out]
uint16 :
--------------------------------------------------------------------------------------------------------*/
uint16 ADC_readChannel (uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
