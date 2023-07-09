/*---------------------------------------------------------------------------------------------------
File Name : DC_motor.h
Author : Mostafa Elsayad
Date Created :
Description : Header File for the AVR DC_motor Driver
--------------------------------------------------------------------------------------------------*/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
/***********************************************DEFINITIONS***********************************************/
#define DC_MOTOR_PORT_ID            PORTB_ID

#define DC_MOTOR_PIN_IN1            PIN0_ID
#define DC_MOTOR_PIN_IN2            PIN1_ID
#define DC_MOTOR_PIN_IN3
#define DC_MOTOR_PIN_IN4

#define DC_MOTOR_PIN_EN1            PIN3_ID
#define DC_MOTOR_PIN_EN2

/***********************************************TYPES DEClERATIONS***********************************************/
/*-------------------------------------------------------------------------------------------------------
 Enum Name : GPIO_PortDirectionType
 Enum Description : This Enum is responsible for assign status of motort variables
--------------------------------------------------------------------------------------------------------*/
typedef enum{
	STOP,CLOCKWISE,ANTI_CLOCKWISE
}DC_motorStatus;

/***********************************************FUNCTIONS PROTOTYPES***********************************************/
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
void DcMotor_Init(void);
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
void DcMotor_Rotate( DC_motorStatus state,uint8 speed);
#endif /* DC_MOTOR_H_ */
