/************************************************************************/
/* Name: HLCD_interface.h                                               */
/* Author: MOHIE ELDEAN                                                 */
/* Version: V1.0                                                        */
/* Usage: This file contains interfacing information of LCD Module      */
/************************************************************************/

/*Header file guard*/
#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_


/************************************************************************/
/*                           Interfacing macros                         */
/************************************************************************/
/*LCD ROWS*/
#define  HLCD_ROW0 (0x80)
#define  HLCD_ROW1 (0xC0)

/*LCD COLS*/
#define  HLCD_COL0	(0)
#define  HLCD_COL1	(1)
#define  HLCD_COL2	(2)
#define  HLCD_COL3	(3)
#define  HLCD_COL4	(4)
#define  HLCD_COL5	(5)
#define  HLCD_COL6	(6)
#define  HLCD_COL7	(7)
#define  HLCD_COL8	(8)
#define  HLCD_COL9	(9)
#define  HLCD_COL10	(10)
#define  HLCD_COL11	(11)
#define  HLCD_COL12	(12)
#define  HLCD_COL13	(13)
#define  HLCD_COL14	(14)
#define  HLCD_COL15	(15)



/************************************************************************/
/*                           Functions' prototypes                      */
/************************************************************************/

/*This function is used in initializing the LCD module*/
void hlcd_init(void);

/*This function is used in writing a character over LCD*/
void hlcd_writeChar(u8_t au8_charData);

/*This function is used in writing a string of characters over LCD*/
void hlcd_writeString(u8_t* pu8_stringData);

/*This function is used in clearing LCD*/
void hlcd_clearLCD(void);


void hlcd_gotorowcol(u8_t au8_row,u8_t au8_col);

#endif /* HLCD_INTERFACE_H_ */