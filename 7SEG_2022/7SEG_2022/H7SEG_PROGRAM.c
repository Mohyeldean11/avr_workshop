/************************************************************************/
/* Name: MDIO_PROGRAM.c                                                 */
/* Author: MOHIEE ELDEAN                                                */
/* Version: V1.0                                                        */
/* Usage: This file contains logical implementations of 7SEG Module      */
/************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "DATA_TYPES.h"
#include "LBIT_Math.h"
#include "MDIO_PRIVATE.h"
#include "MDIO_INTERFACE.h"
#include "H7SEG_PRIVATE.h"
#include "H7SEG_INTERFACE.h"




void _7SEG_ENABLE(u8_t segment_number,u8_t segment_point)
{
	if (segment_number==LEFT_SEGMENT)
	{
		
		MDIO_SETPIN_STATUS(_7SEG_ENABLE_PORT,_7SEG_ENABLE1,OUTPUT);
		MDIO_SETPIN_VALUE(_7SEG_ENABLE_PORT,_7SEG_ENABLE1,HIGH);	
	}
	else if (segment_number==RIGHT_SEGMENT)
	{
		
		MDIO_SETPIN_STATUS(_7SEG_ENABLE_PORT,_7SEG_ENABLE2,OUTPUT);
		MDIO_SETPIN_VALUE(_7SEG_ENABLE_PORT,_7SEG_ENABLE2,HIGH);
	}	
	
	if (segment_point==SEGMENT_POINT)
	{
		MDIO_SETPIN_STATUS(_7SEG_ENABLE_PORT,_7SEG_DPOINT,OUTPUT);
		MDIO_SETPIN_VALUE(_7SEG_ENABLE_PORT,_7SEG_DPOINT,HIGH);
	}
	else if(segment_point==NO_SEGMENT_POINT)
	{
		MDIO_SETPIN_STATUS(_7SEG_ENABLE_PORT,_7SEG_DPOINT,OUTPUT);
		MDIO_SETPIN_VALUE(_7SEG_ENABLE_PORT,_7SEG_DPOINT,LOW);		
	}
}

void _7SEG_DISABLE(u8_t segment_number)
{
	if (segment_number==LEFT_SEGMENT)
	{
		MDIO_SETPIN_STATUS(_7SEG_ENABLE_PORT,_7SEG_ENABLE1,OUTPUT);
		MDIO_SETPIN_VALUE(_7SEG_ENABLE_PORT,_7SEG_ENABLE1,LOW);	
	}
	else if (segment_number==RIGHT_SEGMENT)
	{
		
		MDIO_SETPIN_STATUS(_7SEG_ENABLE_PORT,_7SEG_ENABLE2,OUTPUT);
		MDIO_SETPIN_VALUE(_7SEG_ENABLE_PORT,_7SEG_ENABLE2,LOW);
	}	
}

void _7SEG_SEND_DATA(u8_t segment_number,u8_t seg_data)
{
	if (segment_number==LEFT_SEGMENT)
	{
		MDIO_SETPIN_STATUS(_7SEG_DATA_PORT,PIN4|PIN5|PIN6|PIN7,OUTPUT);
	}
	else if (segment_number==RIGHT_SEGMENT)
	{
		MDIO_SETPIN_STATUS(_7SEG_DATA_PORT,PIN4|PIN5|PIN6|PIN7,OUTPUT);
	}
	switch(seg_data)
	{
		case seg_0 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4|PIN5|PIN6|PIN7,LOW);
			break;
		}
		case seg_1 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN5|PIN6|PIN7,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4,HIGH);
			break;
		}
		case seg_2 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4|PIN6|PIN7,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN5,HIGH);
			break;
		}
		case seg_3 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN6|PIN7,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4|PIN5,HIGH);
			break;
		}
		case seg_4 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4|PIN5|PIN7,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN6,HIGH);
			break;
		}
		case seg_5 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN5|PIN7,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN6|PIN4,HIGH);
			break;
		}
		case seg_6 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4|PIN7,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN5|PIN6,HIGH);
			break;
		}
		case seg_7 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN7,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4|PIN5|PIN6,HIGH);
			break;
		}
		case seg_8 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4|PIN5|PIN6,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN7,HIGH);
			break;
		}		
		case seg_9 :
		{
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN5|PIN6,LOW);
			MDIO_SETPIN_VALUE(_7SEG_DATA_PORT,PIN4|PIN7,HIGH);
			break;
		}
		default :
		{
			/*do nothing*/
			break;
		}
	}
}