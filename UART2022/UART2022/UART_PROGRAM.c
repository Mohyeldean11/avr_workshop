/************************************************************************/
/* Name: UART_PROGRAM.c                                                 */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains the program  for UART Module			    */
/************************************************************************/

#include "LBIT_MATH.h"
#include "DATA_TYPES.h"
#include "MDIO_INTERFACE.h"
#include "MDIO_PRIVATE.h"
#include "UART_PRIVATE.h"
#include "UART_INTERFACE.h"



void UART_INIT(u16_t au16_baudrate)												//using this function to initialize the UARt
{
	UCSRA=0;
	UCSRB=(0x18);
	UCSRC=(0x86);
	UBRRL=(u8_t)(au16_baudrate);
	UBRRH=(u8_t)(au16_baudrate>>8);
	return;
}

void UART_SEND(u8_t sent_value)
{
	if(GET_BIT(UCSRA,5))
	{
	UDR=sent_value;
	while(GET_BIT(UCSRA,6)==0);
	SET_BIT(UCSRA,6);
	}
}

void UART_SEND_STREAM(u8_t* stream_value,u8_t data_size)
{
		while(data_size--)
		if(GET_BIT(UCSRA,5))
		{
			if(GET_BIT(UCSRA,5))
			{
			UDR=*stream_value++;
			while(GET_BIT(UCSRA,6)==0);
			SET_BIT(UCSRA,6);
			}
		}
}

void UART_RECEIVE(u8_t* receive_value)
{
	if(GET_BIT(UCSRA,7)==1)
	{
		*receive_value=UDR;
	}
}