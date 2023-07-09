/*---------------------------------------------------------------------------------------------------
File Name : pwm.h
Author : Mostafa Elsayad
Date Created :
Description : source File for the AVR pwm Driver
--------------------------------------------------------------------------------------------------*/
#include <avr/io.h>
#include "pwm.h"
#include "dc_motor.h"
#include "gpio.h"
#include "common_macros.h"


/***********************************************FUNCTIONS DEFINITIONS***********************************************/
/*-------------------------------------------------------------------------------------------------------
Function Name : PWM_Timer0_Start
Description : The function responsible for trigger the Timer0 with the PWM Mode.
 Setup the PWM mode with Non-Inverting.
 Setup the prescaler with F_CPU/8.
 Setup the compare value based on the required input duty cycle
 Setup the direction for OC0 as output pin through the GPIO driver.
 The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
Args :
[in]
uint8 duty_cycle :The required duty cycle percentage of the generated PWM signal. Its value should be from 0 → 100
[out]
void
--------------------------------------------------------------------------------------------------------*/
void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0=0;               /* Set Timer Initial value */
	OCR0 = duty_cycle;     /* Set Compare Value */
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);    /* set PB3 as Output pin */
	/* Configure timer control register
		 * FOC0=0
		 * WGM01=1 & WGM00=1
		 * COM00=0 & COM01=1
		 * clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		 */
		TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}
