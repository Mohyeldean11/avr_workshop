/*
 * EXTI_2022.c
 *
 * Created: 3/20/2022 1:40:46 AM
 * Author : mohye
 */ 

#include <avr/io.h>
#include "LBIT_Math.h"
#include "DATA_TYPES.h"
#include "MDIO_INTERFACE.h"
#include "EXTI_INTERFACE.h"
void led_toggle_1(void)
{
	MDIO_TOGGLEPIN_VALUE(PORTC,PIN2);
}
void led_toggle_2(void)
{
	MDIO_TOGGLEPIN_VALUE(PORTA,PIN0);
}

int main(void)
{
		MDIO_SETPIN_STATUS(PORTC,PIN2,OUTPUT);
		MDIO_SETPIN_STATUS(PORTA,PIN0,OUTPUT);
		MDIO_SETPIN_STATUS(PORTD,PIN2,INPUT_PULLUP);
		MDIO_SETPIN_STATUS(PORTD,PIN3,INPUT_PULLUP);
		
		exti_init(EXTI_PIN0,exti_falling_edge,led_toggle_1);
		
		exti_init(EXTI_PIN1,exti_toggle,led_toggle_2);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

