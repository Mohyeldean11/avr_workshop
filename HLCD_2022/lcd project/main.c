/*
 * lcd project.c
 *
 * Created: 4/23/2021 9:43:48 AM
 * Author : mohye
 */ 
#include "DATA_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	hlcd_init();
	
	hlcd_writeString((u8_t *)("tmam=98"));
    /* Replace with your application code */
	hlcd_writeChar(' ');
	while(1)
	{
		
	}
	return 0;
}

