/************************************************************************/
/* Name: HLCD_program.c                                                 */
/* Author: MOHIE ELDEAN                                                 */
/* Version: V1.0                                                        */
/* Usage: This file contains logical implementations of LCD Module      */
/************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "DATA_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLCD_private.h"
#include "HLCD_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

/************************************************************************/
/*                          Functions' definitions                      */
/************************************************************************/

static void hlcd_sendCMD(u8_t au8_cmd)
{
	/*Writing over LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_RW, LOW);
	
	/*Sending command over LCD*/	
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_RS, LOW);
	
	/*Transferring the high nibble bits*/
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB7, GET_BIT(au8_cmd, 7));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB6, GET_BIT(au8_cmd, 6));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB5, GET_BIT(au8_cmd, 5));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB4, GET_BIT(au8_cmd, 4));
	
	/*Trigger writing over the LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, LOW);
	_delay_us(50);
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, HIGH);

	/*Transferring the low nibble bits*/	
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB7, GET_BIT(au8_cmd, 3));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB6, GET_BIT(au8_cmd, 2));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB5, GET_BIT(au8_cmd, 1));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB4, GET_BIT(au8_cmd, 0));

	/*Trigger writing over the LCD*/	
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, LOW);
	_delay_us(50);
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, HIGH);	
	
	/*Return from this function*/
	return;
}

static void hlcd_sendData(u8_t au8_data)
{
	/*Writing over LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_RW, LOW);
	
	/*Sending display data over LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_RS, HIGH);
	
	/*Transferring the high nibble bits*/
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB7, GET_BIT(au8_data, 7));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB6, GET_BIT(au8_data, 6));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB5, GET_BIT(au8_data, 5));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB4, GET_BIT(au8_data, 4));
	
	/*Trigger writing over the LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, LOW);
	_delay_us(50);
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, HIGH);

	/*Transferring the low nibble bits*/
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB7, GET_BIT(au8_data, 3));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB6, GET_BIT(au8_data, 2));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB5, GET_BIT(au8_data, 1));
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB4, GET_BIT(au8_data, 0));

	/*Trigger writing over the LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, LOW);
	_delay_us(50);
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, HIGH);

	/*Return from this function*/
	return;
}

void hlcd_init(void)
{
	/*LCD data pins initialization as output*/
	MDIO_SETPIN_STATUS(HLCD_DATA_PORT, (HLCD_DB4 | HLCD_DB5 | HLCD_DB6 | HLCD_DB7), OUTPUT);	
	
	/*LCD control pins initialization as output*/
	MDIO_SETPIN_STATUS(HLCD_CONTROL_PORT, (HLCD_RS | HLCD_RW | HLCD_EN), OUTPUT);
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, HIGH);
	
	/*Wait until Vdd rises to 4.5v*/
	_delay_ms(50);
	
	/*Writing over LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_RW, LOW);
	
	/*Sending command over LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_RS, LOW);
	
	/*Transferring the function set instruction header (4-bits)*/
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB7, LOW);
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB6, LOW);
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB5, HIGH);
	MDIO_SETPIN_VALUE(HLCD_DATA_PORT, HLCD_DB4, LOW);
	
	/*Trigger writing over the LCD*/
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, LOW);
	_delay_us(50);
	MDIO_SETPIN_VALUE(HLCD_CONTROL_PORT, HLCD_EN, HIGH);
	
	/*Sending the function set instruction*/
	hlcd_sendCMD(0x2C);
	
	/*Delay for 1 millisecond*/
	_delay_ms(1);

	/*Sending the display ON/OFF control instruction*/
	hlcd_sendCMD(0x0F);
	
	/*Delay for 1 millisecond*/
	_delay_ms(1);
	
	/*Sending the clearing display instruction*/
	hlcd_sendCMD(0x01);
	
	/*Delay for 2 millisecond*/
	_delay_ms(2);
	
	/*Sending the entry mode set instruction*/
	hlcd_sendCMD(0x06);
	
	/*Delay for 1 millisecond*/
	_delay_ms(1);

	/*Return from this function*/
	return;
}

void hlcd_writeChar(u8_t au8_charData)
{
	/*Sending the character data over LCD*/
	hlcd_sendData(au8_charData);
	
	/*Return from this function*/
	return;
}

void hlcd_writeString(u8_t* pu8_stringData)
{
	/*Looping over string characters*/
	while(*pu8_stringData != '\0')
	{
		/*Sending the character data*/
		hlcd_sendData(*pu8_stringData);
		
		/*Increment the pointer current address*/
		pu8_stringData++;
	}
	
	/*Return from this function*/
	return;
}

void hlcd_clearLCD(void)
{
	/*Sending the clearing display instruction*/
	hlcd_sendCMD(0x01);
		
	/*Delay for 2 millisecond*/
	_delay_ms(2);

	/*Return from this function*/
	return;
}

void hlcd_gotorowcol(u8_t au8_row,u8_t au8_col)
{
	hlcd_sendCMD(au8_row | au8_col);
	return;
}