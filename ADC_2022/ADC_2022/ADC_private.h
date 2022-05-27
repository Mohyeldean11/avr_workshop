/*
 * ADC_private.h
 *
 * Created: 4/4/2022 2:25:43 AM
 *  Author: mohye
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/************************************************************************/
/*								REGISTERS                               */
/************************************************************************/
#define SFIOR			(*(volatile u8_t*)(0x50))

#define ADMUX			(*(volatile u8_t*)(0x27))

#define ADCSRA			(*(volatile u8_t*)(0x26))

#define ADCH			(*(volatile u8_t*)(0x25))

#define ADCL			(*(volatile u8_t*)(0x24))



#endif /* ADC_PRIVATE_H_ */