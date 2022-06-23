/*
 * MDIOMO7A.c
 *
 * Created: 4/23/2021 8:23:42 AM
 * Author : mohye
 */ 

#include "DATA_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_INTERFACE.h"
#define F_CPU 16000000UL
#include "util/delay.h"



int main(void)
{
    /* Replace with your application code */
	MDIO_SETPIN_STATUS(PORTB,PIN0|PIN1,OUTPUT);
	MDIO_SETPIN_STATUS(PORTC,PIN7,INPUT_PULLUP);
	
    while (1) 
    {
		if (MDIO_GETPIN_VALUE(PORTC,PIN7))
		{
			MDIO_SETPIN_VALUE(PORTB,PIN0,HIGH);
			_delay_ms(100);
			MDIO_TOGGLEPIN_VALUE(PORTB,PIN0);
			_delay_ms(100);
		}
		else
		{

			MDIO_SETPIN_VALUE(PORTB,PIN1,HIGH);
			_delay_ms(100);
			MDIO_TOGGLEPIN_VALUE(PORTB,PIN1);
			_delay_ms(100);
			
		}		
    }
	return 0;
}

