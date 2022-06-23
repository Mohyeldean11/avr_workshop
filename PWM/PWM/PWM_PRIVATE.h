
/************************************************************************/
/* Name: MDIO_PRIVATE.h                                                 */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains private information of PWM Module          */
/************************************************************************/




#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

#define TCCR0	(*(volatile u8_t*)(0x53))
#define	TCNT0	(*(volatile u8_t*)(0X52))
#define OCR0	(*(volatile u8_t*)(0x5C))	
#define TIMSK	(*(volatile u8_t*)(0X59))
#define	TIFR	(*(volatile u8_t*)(0X58))




#endif /* PWM_PRIVATE_H_ */