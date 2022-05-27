/*
 * ADC_program.c
 *
 * Created: 4/4/2022 2:25:11 AM
 *  Author: mohye
 */ 
#include "LBIT_Math.h"
#include "DATA_TYPES.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "EXTI_PRIVATE.h"
#include "avr/interrupt.h"
/************************************************************************/
/* GLOBAL POINTERS                                                      */
/************************************************************************/
	void (* gp_ADC_isr)(void);

void ADC_INIT(u8_t ADJUST_MODE,u8_t PRESCALER)
{
	ADMUX=0;												//reseting the admux register
	
	ADCSRA=0;											   //reseting the adcsra register
	
	SET_BIT(ADCSRA,7);										//enabling the ADC

	ADMUX|=(1<<6);											//making the adc works with the VCC value as a refrence voltage
	if(ADJUST_MODE==LEFT_ADJUST)
	{
		ADMUX|=(1<<5);										//making the reading as a left adjustment
	}
	else if (ADJUST_MODE==RIGHT_ADJUST)
	{
		ADMUX|=(0<<5);										//making the reading as a right adjustment
	}
	
	ADCSRA|=(PRESCALER);									//choosing the prescaler 
}

void ADC_SINGLE_CONVERSION(u8_t ADC_PIN,u16_t* READ_VALUE)
{
	u8_t adjust_mode;										//declaring a variable to carry the mode of the resolution;
	
	adjust_mode=(GET_BIT(ADMUX,5));							//checking the mode value
	
	ADMUX|=(ADC_PIN);										//assigning the pin for the ADC
	
	if(GET_BIT(ADCSRA,4)==0)								//checking the flag of the ADC to know if its still converting or not
	{
		SET_BIT(ADCSRA,6);									//starting the conversion of the ADC
	}
	while(GET_BIT(ADCSRA,6)==1);							//polling on bit 6 to know when the conversion will finish
	
	if(adjust_mode==LEFT_ADJUST)
	{
		*READ_VALUE=(u16_t)(ADCH);
	}
	else if (adjust_mode==RIGHT_ADJUST)
	{
		*READ_VALUE=(u16_t)(ADCL);
		*READ_VALUE=(u16_t)(ADCH<<8);
	}
}


void ADC_AUTOTRIGGER_CONVERSION(u8_t ADC_PIN,u16_t* READ_VALUE,u8_t AUTOTRIGGER_SOURCE)
{
	u8_t adjust_mode;										//declaring a variable to carry the mode of the resolution;
		
	adjust_mode=(GET_BIT(ADMUX,5));							//checking the mode value
		
	ADMUX|=(ADC_PIN);										//assigning the pin for the ADC
	
	switch(AUTOTRIGGER_SOURCE)								//choosing the auto triggering source
	{
		case FREE_RUNNING :									//in the free runinning mode
		{
			SFIOR|=(0b00000000);							
			SET_BIT(ADCSRA,6);								//intializing the free mode
			
			break;
		}
		case ANALOG_COMPARATOR:								//choosing the analogue comparator source
		{
			SFIOR|=(0b00100000);	
			break;	
		}
		case EXT_INT_REQ1:									//choosing the external interrupt1 source
		{
			SFIOR|=(0b01000000);
			break;
		}
		case TIMER0_COMP_MATCH:								//choosing the timer0 match source
		{
			SFIOR|=(0b01100000);
			break;
		}
		case TIMER0_OVERFLOW:								//choosing the timer0 overflow
		{
			SFIOR|=(0b10000000);
			break;
		}
		case TIMER1_COMP_MATCH:								//choosing the timer1 match source
		{
			SFIOR|=(0b10100000);
			break;
		}
		case TIMER1_OVERFLOW:								//choosing the timer1 overflow
		{
			SFIOR|=(0b11000000);
			break;
		}
		case TIMER1_CAPTURE:								//choosing the timer1 capture
		{
			SFIOR|=(0b11100000);
			break;
		}
	}
	
	if(adjust_mode==LEFT_ADJUST)
	{
		*READ_VALUE=(u16_t)(ADCH);
	}
	else if (adjust_mode==RIGHT_ADJUST)
	{
		*READ_VALUE=(u16_t)(ADCL);
		*READ_VALUE=(u16_t)(ADCH<<8);
	}
}

void ADC_INTERRUPT_CONVERSION(u8_t ADC_PIN,u16_t* READ_VALUE)
{
		u8_t adjust_mode;										//declaring a variable to carry the mode of the resolution;
		
		adjust_mode=(GET_BIT(ADMUX,5));							//checking the mode value
		
		ADMUX|=(ADC_PIN);										//assigning the pin for the ADC
		
		SET_BIT(SREG,7);										//enabling the global interrupt
		
		SET_BIT(ADCSRA,3);										//enabling the interrupt for the ADC
		
		if(GET_BIT(ADCSRA,4)==0)								//checking the flag of the ADC to know if its still converting or not
		{
			SET_BIT(ADCSRA,6);									//starting the conversion of the ADC
		}
		
		while(GET_BIT(ADCSRA,6)==1);							//polling on bit 6 to know when the conversion will finish
		
		if(adjust_mode==LEFT_ADJUST)			
		{
			*READ_VALUE=(u16_t)(ADCH);							//reading the value from the adch registers
		}
		else if (adjust_mode==RIGHT_ADJUST)
		{
			*READ_VALUE=(u16_t)(ADCL);							//reading the value from the adcl registers
			
			*READ_VALUE=(u16_t)(ADCH<<8);						//reading the value from the adch registers
		}
	
}




ISR(ADC_vect)
{
	gp_ADC_isr();
}


