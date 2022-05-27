/*
 * ADC_interface.h
 *
 * Created: 4/4/2022 2:25:26 AM
 *  Author: mohye
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/************************************************************************/
/*					INTERFACING MACROS                                  */
/************************************************************************/


/*ADJUST_MODE*/
#define LEFT_ADJUST					(1)
#define RIGHT_ADJUST				(2)

/*ADC_PINS*/
#define ADC0						(0)
#define ADC1						(1)
#define ADC2						(2)
#define ADC3						(3)
#define ADC4						(4)
#define ADC5						(5)
#define ADC6						(6)
#define ADC7						(7)


/*PRESCALER*/
#define prescaler_2					(1)
#define prescaler_4					(2)
#define prescaler_8					(3)
#define prescaler_16				(4)
#define prescaler_32				(5)
#define prescaler_64				(6)
#define prescaler_128				(7)

/*AUTOTRIGGER SOURCES*/
#define FREE_RUNNING				(1)
#define ANALOG_COMPARATOR			(2)
#define EXT_INT_REQ1				(3)
#define TIMER0_COMP_MATCH			(4)
#define TIMER0_OVERFLOW				(5)
#define TIMER1_COMP_MATCH			(6)
#define TIMER1_OVERFLOW				(7)
#define TIMER1_CAPTURE				(8)



/************************************************************************/
/*					FUNCTION PROTOTYPES								       */
/************************************************************************/
void ADC_INIT(u8_t ADJUST_MODE,u8_t PRESCALER);															//a function to initialize the ADC and choose the prescaler value



void ADC_SINGLE_CONVERSION(u8_t ADC_PIN,u16_t* READ_VALUE);												//a function to do a manual single conversion

void ADC_AUTOTRIGGER_CONVERSION(u8_t ADC_PIN,u16_t* READ_VALUE,u8_t AUTOTRIGGER_SOURCE);				//a function convert when auto triggered

void ADC_INTERRUPT_CONVERSION(u8_t ADC_PIN,u16_t* READ_VALUE);											//a function that trigger an external interrupt


#endif /* ADC_INTERFACE_H_ */