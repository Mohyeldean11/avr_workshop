/************************************************************************/
/* Name: EXTI_INTERFACE.h                                              */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains interfacing macros for the EXTI Module     */
/************************************************************************/

/*header guard*/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/************************************************************************/
/*	                     INTERFACING MACROS                             */
/************************************************************************/
	 /*modes*/
#define exti_low_level				1
#define exti_toggle					2
#define exti_falling_edge			3	
#define exti_rising_edge			4	

	/*exti_pins*/
#define EXTI_PIN0					0
#define EXTI_PIN1					1
#define EXTI_PIN2					2


/************************************************************************/
/*                     FUNCTIONS PROTOTYPES                             */
/************************************************************************/

void exti_init(u8_t exti_pin,u8_t mode,void(*function_ptr)(void));									//a function to initialize the external signal

void exti_read_value(u8_t exti_pin,u8_t * read_value);												//a function to read the INTERRUPT FLAG REGISTERS

void exti_disable(u8_t exti_pin);																	//a function to disable the exti signal


#endif /* EXTI_INTERFACE_H_ */