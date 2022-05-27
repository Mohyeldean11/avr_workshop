/************************************************************************/
/* Name: EXTI_PRIVATE.h                                                 */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains private information EXTI                   */
/************************************************************************/


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define SREG			(*(volatile u8_t*)(0x5F))
		
#define EXTI_MCUCR		(*(volatile u8_t*)(0x55))

#define EXTI_MCUCSR		(*(volatile u8_t*)(0x54))

#define EXTI_GICR		(*(volatile u8_t*)(0x5B))

#define EXTI_GIFR		(*(volatile u8_t*)(0x5A))



#endif /* EXTI_PRIVATE_H_ */