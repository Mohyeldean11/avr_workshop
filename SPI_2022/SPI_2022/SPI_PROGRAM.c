/************************************************************************/
/* Name: SPI_PROGRAM.c                                                  */
/* Author: MOHIEE ELDEAN                                                */
/* Version: V1.0                                                        */
/* Usage: This file contains logical implementations of SPI Module      */
/************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "DATA_TYPES.h"
#include "LBIT_Math.h"
#include "SPI_PRIVATE.h"
#include "SPI_INTERFACE.h"
#include "MDIO_INTERFACE.h"
/************************************************************************/
/*						PROGRAM                                         */
/************************************************************************/

void SPI_INIT(u8_t spi_mode,u8_t data_order,u8_t frequency)
{
	if (spi_mode==MASTER)
	{
		SET_BIT(SPI_SPCR,SPCR_MSTR);							//SETTING THE MSTR BIT TO ACTIVATE THE MASTER MODE
		
		MDIO_SETPIN_STATUS(PORTB,PIN5,OUTPUT);					//SETTING THE MOSI PIN TO OUTPUT
			
		MDIO_SETPIN_STATUS(PORTB,PIN7,OUTPUT);					//SETTING THE CLOCK PIN TO OUTPUT
		
		CLEAR_BIT(SPI_SPCR,SPCR_CPOL);							//SETTING THE CLOCK POLARITY TO BE RISING AT LEADING
		
		SET_BIT(SPI_SPCR,SPCR_CPHA);							//SETTING THE CLOCK PHASE TO BE SETUP AT LEADING
		
		SPI_SPCR|=(frequency);									//SETTING THE FREQUENCY OF THE CLOCK
		
		
		if(data_order==LSB_FIRST)
		{
			SET_BIT(SPI_SPCR,SPCR_DORD);						//SETTING THE DATA ORDER TO  BE FROM THE LEAST SIGNIFICANT BIT
		}
		else if (data_order==MSB_FIRST)
		{
			CLEAR_BIT(SPI_SPCR,SPCR_DORD);						//SETTING THE DATA ORDER TO  BE FROM THE LEAST SIGNIFICANT BIT
		}
	}
	
	else if(spi_mode==SLAVE)
	{
		CLEAR_BIT(SPI_SPCR,SPCR_MSTR);							//CLEARING THE MSTR BIT TO ACTIVATE THE SLAVE MODE
		
		MDIO_SETPIN_STATUS(PORTB,PIN6,OUTPUT);					//SETTING THE MOSI PIN TO OUTPUT

	}


	SET_BIT(SPI_SPCR,SPCR_SPE);									//ENABLING THE SPI
}

void SPI_SEND(u8_t data)
{
	SPI_SPDR=data;												//PASSING THE DATA TO BE TRANSMITTED
		
	while(GET_BIT(SPI_SPSR,SPSR_SPIF)==0);						//WAITING FOR THE TRANSMISSION TO BE FINISHED
}

u8_t SPI_RECEIVE()
{
	u8_t data_received;											//CREATING A VARIABLE TO RECEIVE THE DATA 
	
	while(GET_BIT(SPI_SPSR,SPSR_SPIF)==1);						//WAITING FOR THE TRANSMISSION TO BE FINISHED	

	data_received=SPI_SPDR;										//GETTING THE DATA IN THE SPDR REGISTER THAT WAS RECEIVED
	
	return data_received;										//RETURNING THE DATA RECEIVED
}