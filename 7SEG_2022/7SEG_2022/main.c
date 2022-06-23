
#include "DATA_TYPES.h"
#include "LBIT_Math.h"
#include "MDIO_INTERFACE.h"
#include "H7SEG_INTERFACE.h"
#define F_CPU		16000000
#include "util/delay.h"

void alarm(void);
int main(void)
{
	MDIO_SETPIN_STATUS(PORTA,PIN3,OUTPUT);
	int var=0;
	_7SEG_ENABLE(LEFT_SEGMENT,SEGMENT_POINT);
	_7SEG_ENABLE(RIGHT_SEGMENT,SEGMENT_POINT);
	_7SEG_SEND_DATA(RIGHT_SEGMENT,var);	
	while(var<10)
	{
	_7SEG_SEND_DATA(LEFT_SEGMENT,var);
	_delay_ms(1000);
	var++;
	}

    /* Replace with your application code */
    while (1) 
    {
		alarm();
    }
}
void alarm()
{
	_7SEG_ENABLE(LEFT_SEGMENT,SEGMENT_POINT);
	_7SEG_ENABLE(RIGHT_SEGMENT,SEGMENT_POINT);
	MDIO_SETPIN_VALUE(PORTA,PIN3,HIGH);		
	_delay_ms(100);
	_7SEG_DISABLE(LEFT_SEGMENT);
	_7SEG_DISABLE(RIGHT_SEGMENT);
	MDIO_SETPIN_VALUE(PORTA,PIN3,LOW);
	_delay_ms(100);
	
}
