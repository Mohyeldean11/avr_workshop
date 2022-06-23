/*
 * PWM.c
 *
 * Created: 3/15/2022 5:59:12 PM
 * Author : mohye
 */ 

#include <avr/io.h>
#include "DATA_TYPES.h"
#include "LBIT_Math.h"
#include "MDIO_INTERFACE.h"
#include "PWM_INTERFACE.h"
#define F_CPU	8000000UL
#include "util/delay.h"

int main(void)
{
	PWM_INIT(FAST_PWM,clk_64);
	PWM_dynamics(incrementation,120);
	
	
    /* Replace with your application code */
    while (1) 
    {
	
    }
}

