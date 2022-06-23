/************************************************************************/
/* Name: MDIO_INTERFACE.h                                               */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains INTERFACING MACROS  of 8seg Module         */
/************************************************************************/

#ifndef H7SEG_INTERFACE_H_
#define H7SEG_INTERFACE_H_


/************************************************************************/
/*                 INTERFACING MACROS                                   */
/************************************************************************/
#define LEFT_SEGMENT							(1)
#define RIGHT_SEGMENT							(2)


#define	SEGMENT_POINT							(1)
#define NO_SEGMENT_POINT						(2)

#define seg_0									(0)
#define seg_1									(1)		
#define seg_2									(2)
#define seg_3									(3)
#define seg_4									(4)
#define seg_5									(5)
#define seg_6									(6)
#define seg_7									(7)
#define seg_8									(8)
#define seg_9									(9)

/************************************************************************/
/*					FUNCTION PROTOTYPES                                 */
/************************************************************************/
void _7SEG_ENABLE(u8_t segment_number,u8_t segment_point);										//A FUNCTION TO ENABLE THE CHOSEN SEGMENT AND ACTIVATE THE DECIMAL POINT

void _7SEG_DISABLE(u8_t segment_number);														//A FUNCTION TO DISABLE THE CHOSEN SEGMENT 

void _7SEG_SEND_DATA(u8_t segment_number,u8_t seg_data);											//A FUNCTION TO SEND DATA TO THE CHOSEN 7SEGMENT

									
#endif /* H7SEG_INTERFACE_H_ */