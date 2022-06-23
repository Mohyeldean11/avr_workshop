/************************************************************************/
/* Name: SPI_PRIVATE.h                                                  */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains private information of SPI Module          */
/************************************************************************/


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI_SPCR		(*(volatile u8_t*)(0x2D))
	#define SPCR_SPIE			7
	#define SPCR_SPE			6
	#define SPCR_DORD			5
	#define SPCR_MSTR			4
	#define SPCR_CPOL			3
	#define SPCR_CPHA			2
	#define SPCR_SPHR1			1
	#define SPCR_SPHR0			0


#define SPI_SPSR		(*(volatile u8_t*)(0x2E))
	#define SPSR_SPIF			7
	#define SPSR_WCOL			6
	#define SPSR_SPI2X			0
	
	
	
#define SPI_SPDR		(*(volatile u8_t*)(0x2F))






#endif /* SPI_PRIVATE_H_ */