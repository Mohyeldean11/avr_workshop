/************************************************************************/
/* Name: EXTI_PROGRAM.c                                                 */
/* Author: MOHIEE ELDEAN                                                */
/* Version: V1.0                                                        */
/* Usage: This file contains logical implementations of EXTI Module     */
/************************************************************************/

/************************************************************************/
/*                              INCLUDES                                */
/************************************************************************/

#include "avr/interrupt.h"
#include "DATA_TYPES.h"
#include "LBIT_Math.h"
#include "EXTI_PRIVATE.h"
#include "EXTI_INTERFACE.h"

/************************************************************************/
/*						IMPORTANT VARIABLES                             */
/************************************************************************/

/*global pointer carries the adress of functionality used in int0 isr*/
void (*gp_int0_isr)(void);

/*global pointer carries the adress of functionality used in int1 isr*/
void (*gp_int1_isr)(void);

/*global pointer carries the adress of functionality used in int2 isr*/
void (*gp_int2_isr)(void);

/************************************************************************/
/*							FUNCTIONS DEFINITIONS                       */
/************************************************************************/

void exti_init(u8_t exti_pin, u8_t mode, void (*function_ptr)(void))
{
	SET_BIT(SREG, 7); // ENABLING THE GLOBAL INTERRUPT

	switch (exti_pin)
	{
	case EXTI_PIN0:
	{
		gp_int0_isr = function_ptr; // ASSIGNING THE FUNCTION IN THE VECTOR TABLE TO THE FUNCTION POINTER

		SET_BIT(EXTI_GICR, 6); // SETTING THE SPECIFIC INTERRUPT FLAG  FOR PIN 0

		switch (mode)
		{
		case exti_low_level:
		{
			CLEAR_BIT(EXTI_MCUCR, 0); // SETTING ISC01 AND ISC00 TO HAVE LOW LEVEL MODE
			CLEAR_BIT(EXTI_MCUCR, 1);
			break;
		}

		case exti_toggle:
		{
			SET_BIT(EXTI_MCUCR, 0); // SETTING ISC01 AND ISC00 TO HAVE TOGGLE MODE
			CLEAR_BIT(EXTI_MCUCR, 1);
			break;
		}

		case exti_falling_edge:
		{
			CLEAR_BIT(EXTI_MCUCR, 0); // SETTING ISC01 AND ISC00 TO HAVE falling edge MODE
			SET_BIT(EXTI_MCUCR, 1);
			break;
		}

		case exti_rising_edge:
		{
			SET_BIT(EXTI_MCUCR, 0); // SETTING ISC01 AND ISC00 TO HAVE rising edge MODE
			SET_BIT(EXTI_MCUCR, 1);
			break;
		}
		}
		break; // breaking from the INTERRUPT PIN 0
	}

	case EXTI_PIN1:
	{
		gp_int1_isr = function_ptr; // ASSIGNING THE FUNCTION IN THE VECTOR TABLE TO THE FUNCTION POINTER

		SET_BIT(EXTI_GICR, 7); // SETTING THE SPECIFIC INTERRUPT FLAG  FOR PIN 1

		switch (mode)
		{
		case exti_low_level:
		{
			CLEAR_BIT(EXTI_MCUCR, 2); // SETTING ISC11 AND ISC10 TO 0 TO HAVE LOW LEVEL MODE
			CLEAR_BIT(EXTI_MCUCR, 3);
			break;
		}

		case exti_toggle:
		{
			SET_BIT(EXTI_MCUCR, 2); // SETTING ISC11 AND ISC10 TO HAVE TOGGLE MODE
			CLEAR_BIT(EXTI_MCUCR, 3);
			break;
		}

		case exti_falling_edge:
		{
			CLEAR_BIT(EXTI_MCUCR, 2); // SETTING ISC11 AND ISC10  TO HAVE falling edge MODE
			SET_BIT(EXTI_MCUCR, 3);
			break;
		}

		case exti_rising_edge:
		{
			SET_BIT(EXTI_MCUCR, 2); // SETTING ISC11 AND ISC10 TO HAVE rising edge MODE
			SET_BIT(EXTI_MCUCR, 3);
			break;
		}
		}
		break; // breaking from the INTERRUPT PIN 1
	}

	case EXTI_PIN2:
	{
		gp_int2_isr = function_ptr; // ASSIGNING THE FUNCTION IN THE VECTOR TABLE TO THE FUNCTION POINTER

		SET_BIT(EXTI_GICR, 5); // SETTING THE SPECIFIC INTERRUPT FLAG  FOR PIN 2

		switch (mode)
		{
		case exti_falling_edge:
		{
			CLEAR_BIT(EXTI_MCUCSR, 6); // SETTING  ISC2 TO HAVE A FALLING EDGE MODE
			break;
		}

		case exti_rising_edge:
		{
			SET_BIT(EXTI_MCUCSR, 6); // SETTING  ISC2 TO HAVE A RISING EDGE MODE
			break;
		}
		}
		break; // breaking from the INTERRUPT PIN 2
	}
	}
}

void exti_read_value(u8_t exti_pin, u8_t *final_status)
{
	u8_t interrupt_status;

	switch (exti_pin)
	{
	case EXTI_PIN0:
	{
		interrupt_status = GET_BIT(EXTI_GIFR, 6); // CHECKING THE VALUE OF THE FLAG OF GIFR FOR PIN 0
		final_status = &interrupt_status;		  // PASSING THE VALUE TO THE POINTER
		break;
	}

	case EXTI_PIN1:
	{
		interrupt_status = GET_BIT(EXTI_GIFR, 7); // CHECKING THE VALUE OF THE FLAG OF GIFR FOR PIN 1
		final_status = &interrupt_status;		  // PASSING THE VALUE TO THE POINTER
		break;
	}

	case EXTI_PIN2:
	{
		interrupt_status = GET_BIT(EXTI_GIFR, 5); // CHECKING THE VALUE OF THE FLAG OF GIFR FOR PIN 0
		final_status = &interrupt_status;		  // PASSING THE VALUE TO THE POINTER
		break;
	}
	}
}

void exti_disable(u8_t exti_pin)
{
	switch (exti_pin)
	{
	case EXTI_PIN0:
	{
		CLEAR_BIT(EXTI_GICR, 6); // DISABLING THE INTERRUPT SIGNAL 0 BY SETTING GICR TO 0
		break;
	}

	case EXTI_PIN1:
	{
		CLEAR_BIT(EXTI_GICR, 7); // DISABLING THE INTERRUPT SIGNAL 1 BY SETTING GICR TO 0
		break;
	}

	case EXTI_PIN2:
	{
		CLEAR_BIT(EXTI_GICR, 5); // DISABLING THE INTERRUPT SIGNAL 2 BY SETTING GICR TO 0
		break;
	}
	}
}

/************************************************************************/
/*					ISRS                                                */
/************************************************************************/

/*INT0 VECTOR ISR*/
ISR(INT0_vect)
{
	/*CALLING THE APPLICATION FUNCTION*/
	gp_int0_isr();
}

/*INT1 VECTOR ISR*/
ISR(INT1_vect)
{
	/*CALLING THE APPLICATION FUNCTION*/
	gp_int1_isr();
}

/*INT2 VECTOR ISR*/
ISR(INT2_vect)
{
	/*CALLING THE APPLICATION FUNCTION*/
	gp_int1_isr();
}