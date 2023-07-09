/*---------------------------------------------------------------------------------------------------
File Name : DC_motor.c
Author : Mostafa Elsayad
Date Created :
Description : source File for the AVR DC_motor Driver
--------------------------------------------------------------------------------------------------*/

#include <avr/io.h>
#include "dc_motor.h"
#include "pwm.h"
#include "gpio.h"
#include "common_macros.h"


/***********************************************FUNCTIONS DEFINITIONS***********************************************/
/*-------------------------------------------------------------------------------------------------------
Function Name : DcMotor_Init
Description : The Function responsible for setup the direction for the two motor pins through the GPIO driver.
Stop at the DC-Motor at the beginning through the GPIO driver.
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void DcMotor_Init(void){
	/* Setup the direction for the two motor pins as output pins */
		GPIO_setupPinDirection(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN1,PIN_OUTPUT);
		GPIO_setupPinDirection(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN2 ,PIN_OUTPUT);

		/* Stop the DC-Motor at the beginning by make it LOGIC_LOW */
		GPIO_writePin(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN1,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN2 ,LOGIC_LOW);
}
/*-------------------------------------------------------------------------------------------------------
Function Name : DcMotor_Rotate
Description : The Function responsible for setup the direction for the two motor pins through the GPIO driver.
Stop at the DC-Motor at the beginning through the GPIO driver.
Args :
[in]
DC_motorStatus state : The required DC Motor state, it should be CW or A-CW or stop.
uint8 speed : decimal value for the required motor speed, it should be from 0 → 100
[out]
void
--------------------------------------------------------------------------------------------------------*/
void DcMotor_Rotate( DC_motorStatus state,uint8 speed){
	uint8 duty = ((float)speed/100)*255;
	PWM_Timer0_Start(duty);
	if (state == STOP)
		{
			// Stop the motor
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW);

		}
		else if (state == CLOCKWISE)
		{
			// Rotate the motor clock wise
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_HIGH);
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW);
		}
		else if (state == ANTI_CLOCKWISE)
		{
			// Rotate the motor anti-clock wise
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_HIGH);
		}

}
