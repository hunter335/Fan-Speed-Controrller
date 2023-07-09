/*---------------------------------------------------------------------------------------------------
File Name : main
Author : Mostafa Elsayad
Date Created :
Description : the main file of Fan controller project
--------------------------------------------------------------------------------------------------*/
#include <avr/io.h>
#include "pwm.h"
#include "dc_motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "adc.h"
#include "lm35_sensor.h"

/***********************************************TYPES DECLARATION***********************************************/


/*-------------------------------------------------------------------------------------------------------
 Enum Name : FAN_STATE
 Enum Description : This Enum is responsible for assign state of the fan to values
--------------------------------------------------------------------------------------------------------*/
typedef enum {
	OFF,ON
}FAN_STATE;

int main(void){
	sint8 temp; /*temprature*/
	FAN_STATE state;
	/* ADC driver configure to operate using the internal reference voltage 2.56 voltage and prescaler F_CPU/8. */
	ADC_ConfigType ADC_Config = {INTERNAL_AREF,DIV_FACTOR_BY_8};
	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Config); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC Motor driver */
	LCD_displayStringRowColumn(0, 4,"Fan is ");
	LCD_displayStringRowColumn(1,4,"Temp=     C ");
	while(1){
		if ( state == ON){

			LCD_displayStringRowColumn(0, 11, "ON");
		}
		else if ( state== OFF){
			LCD_displayStringRowColumn(0, 11, "OFF");
		}
			temp = LM35_getTemperature();
				if(temp < 30){
					state = OFF;
					DcMotor_Rotate(STOP, 0);
				}
		else{
			 state = ON;
			 LCD_displayCharacter(' ');  /* To prevent error like "ONF" to be written */
			if( temp >= 30 && temp < 60 ){
				DcMotor_Rotate(CLOCKWISE,25);
			}
			else if( temp >=60 ){
				DcMotor_Rotate(CLOCKWISE,50);
			}
			else if( temp >= 90){
				DcMotor_Rotate(CLOCKWISE,75);
			}
			else if( temp >= 120){
				DcMotor_Rotate(CLOCKWISE,100);
				}
			}
				LCD_moveCursor(1,11);
				if(temp >= 100){
					LCD_integerToString(temp);
				}
				else
				{
					LCD_integerToString(temp);
					/* In case the digital value is two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
	}
}
