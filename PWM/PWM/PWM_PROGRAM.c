
/************************************************************************/
/* Name: MDIO_PROGRAM.c                                                 */
/* Author: MOHIEE ELDEAN                                                */
/* Version: V1.0                                                        */
/* Usage: This file contains logical implementations of PWM Module      */
/************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/
#include "DATA_TYPES.h"
#include "LBIT_Math.h"
#include "MDIO_PRIVATE.h"
#include "MDIO_INTERFACE.h"
#include "PWM_PRIVATE.h"
#include "PWM_INTERFACE.h"
#define F_CPU	8000000UL
#include "util/delay.h"

void PWM_INIT(u8_t pwm_mode,u8_t prescale_mode)
{
	MDIO_SETPIN_STATUS(PORTB,PIN3,OUTPUT);
	switch(pwm_mode)
	{
		case FAST_PWM :							//case if its a fast pwm
		{
			/*setting bit 6 and 3 to be f_pwm*/
			SET_BIT(TCCR0,6);
			SET_BIT(TCCR0,3);	
			TCCR0 |=(1<<5) | (0<<4)	;				//setting the non inverting value in the pwm
			
			break;						
		}
		case PHASECORRECT_PWM :				  //case if its a phase correct pwm
		{
			/*setting bit 6 and 3 to be pc_pwm*/
			CLEAR_BIT(TCCR0,6);
			SET_BIT(TCCR0,3);
			TCCR0 |=(1<<5) | (1<<4)	;				//setting compare match to the oc0

			break;
		}
	}
	TCCR0|=prescale_mode;					//setting the prescaling value
	
}

void PWM_SINGLE_SETUP(u8_t DutyCycle)
{
	OCR0=DutyCycle;							//setting a duty cycle for a single on the ocr0 pin
}

void PWM_dynamics(u8_t signal_mode,u8_t DutyCycle)
{
	switch(signal_mode)
	{
		case incrementation :
		{
			for(u8_t i=0 ; i<=DutyCycle ; i++)
			{
				OCR0=i;
				_delay_ms(1000);
			}
			break;
		}
		case decrementation :
		{
			for(u8_t i=DutyCycle ; i>=0 ; i--)
			{
				OCR0=i;
				_delay_ms(1000);
			}
			break;
		}
	}
}