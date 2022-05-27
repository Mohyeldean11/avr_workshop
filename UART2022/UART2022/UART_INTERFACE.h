/* Name: UART_INTERFACE.h                                                 */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains INTERFACING  information of UART Module          */
/************************************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/************************************************************************/
/*						 MACROS                                         */
/************************************************************************/


#define baudrate_2400		(416)
#define baudrate_4800		(207)
#define baudrate_9600		(103)
#define baudrate_115K		(8)
#define baudrate_250k		(3)


/************************************************************************/
/*                    FUNCTIONS PROTOTYPES                              */
/************************************************************************/

void UART_INIT(u16_t baudrate_value);										//this function takes the baudrate speed in order to initialize the UART 



void UART_SEND(u8_t sent_value);											//this function used to send byte 



void UART_RECEIVE(u8_t*	receive_value);										//this function used to receive byte



void UART_SEND_STREAM(u8_t* stream_value,u8_t data_size);				   //this function used to send stream of btyes,array






#endif /* UART_INTERFACE_H_ */