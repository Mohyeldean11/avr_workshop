/************************************************************************/
/* Name: MDIO_INTERFACE.h                                               */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains INTERFACING MACROS  of DIO Module          */
/************************************************************************/


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*WE WILL MAKE THE DEFAULT CLOCK PHASE SETUP AS LEADING AND
RISING AS THE CLOCK POLARITY*/

/************************************************************************/
/*						INTERFACING MACROS                              */
/************************************************************************/

/*Data Orders*/
#define  LSB_FIRST		1
#define  MSB_FIRST		2


/*SPI_MODE*/

#define MASTER			1
#define SLAVE			2

/*FREQUENCY MODES*/
#define f_4				(0b00000000)
#define f_16			(0b00000001)
#define f_64			(0b00000010)
#define f_128			(0b00000011)


/************************************************************************/
/*						FUNCTION PROTOTYPES                             */
/************************************************************************/


void SPI_INIT(u8_t spi_mode,u8_t data_order,u8_t frequency);									//FUNCTION USED TO INITIALIZE THE SPI PROTOCOL

void SPI_SEND(u8_t data);																		//FUNCTION USED TO SEND DATA USING THE SPI PROTOCOL

u8_t SPI_RECEIVE();																	//FUNCTION USED TO RECEIVE DATA USING THE SPI PROTOCOL

#endif /* SPI_INTERFACE_H_ */