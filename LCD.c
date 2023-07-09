/*-------------------------------------------------------------------------------------------------
File Name : LCD.c
Author : Mostafa Elsayad
Date Created :
Description : source File for the AVR LCD Driver
--------------------------------------------------------------------------------------------------*/

#include "LCD.h"
#include "common_macros.h"
#include "gpio.h"
#include <util/delay.h>

/***********************************************FUNCTIONS DEFINITIONS***********************************************/

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_init
Description :Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_init(void){
	/* Configure the direction for RS, RW and E pins as output pins */
		GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_RW_PORT_ID,LCD_RW_PIN_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);

		/* Configure the data port as output port */
		GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);

		LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */

		LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */

		LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_sendCommand
Description : Send the required command to the screen
Args :
[in]
uint8 command : command will be send to screen .
[out]
void
--------------------------------------------------------------------------------------------------------*/

void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW); /* Instruction Mode RS=0 */
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	GPIO_writePort(LCD_DATA_PORT_ID,command); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}
/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_displayCharacter
Description : Send the required character to the screen
Args :
[in]
uint8 data :  character will be display on screen
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_displayCharacter (uint8 data){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH); /* Data Mode RS=1 */
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	GPIO_writePort(LCD_DATA_PORT_ID,data); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_displayString
Description : Send the required String to the screen
Args :
[in]
const char *Str :  String will be display on screen
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_displayString (const char *Str){
	uint8 i = 0;
	while(Str[i] != '\0') /*loop to display string */
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}

}

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_moveCursor
Description : Move the cursor to a specified row and column index on the screen
Args :
[in]
uint8 row : row number the cursor will be move to it
uint8 col : column  number the cursor will be move to it
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_moveCursor (uint8 row , uint8 col ){
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x10;
				break;
		case 3:
			lcd_memory_address=col+0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_displayStringRowColumn
Description : Display the required string in a specified row and column index on the screen
Args :
[in]
uint8 row : row number
uint8 col : column  number
const char *Str :  String will be display on screen
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_displayStringRowColumn(uint8 row , uint8 col , const char *Str){
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}
/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_clearScreen
Description : send the clear screen
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_clearScreen(void){
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_integerToString
Description : Display the required decimal value on the screen
Args :
[in]
int data : decimal value will be send to screen
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_integerToString(int data){
	   char buff[16]; /* String to hold the ascii result */
	   itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	   LCD_displayString(buff); /* Display the string */
}
