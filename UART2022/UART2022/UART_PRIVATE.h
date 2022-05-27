/************************************************************************/
/* Name: UART_PRIVATE.h                                                 */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains private information of UART Module          */
/************************************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/************************************************************************/
/*                  REGISTERS                                           */
/************************************************************************/
#define	UBRRH	(*(volatile u8_t*)(0x40))
#define	UCSRC	(*(volatile u8_t*)(0x40))
#define UDR		(*(volatile	u8_t*)(0x2C))
#define UCSRA	(*(volatile u8_t*)(0x2B))
#define	UCSRB	(*(volatile u8_t*)(0x2A))
#define UBRRL	(*(volatile u8_t*)(0x29))




#endif /* UART_PRIVATE_H_ */