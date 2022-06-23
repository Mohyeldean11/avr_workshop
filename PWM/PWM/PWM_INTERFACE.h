/************************************************************************/
/* Name: MDIO_INTERFACE.h                                               */
/* Author: MOHY ELDEAN                                                  */
/* Version: V1.0                                                        */
/* Usage: This file contains INTERFACING MACROS  of PWM Module          */
/************************************************************************/


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

/************************************************************************/
/*								INTERFACING MACROS                      */
/************************************************************************/

/*pwm_modes*/
#define FAST_PWM							(0)
#define PHASECORRECT_PWM					(1)

/*DutyCycle values*/
#define pwm_max							   (255)


/*prescales*/
#define  clk_1								(1)
#define  clk_8								(2)
#define  clk_64								(3)
#define  clk_256							(4)
#define  clk_1024							(5)

/*signal mode*/

#define incrementation						(0)
#define decrementation						(1)

/************************************************************************/
/*								\\FUNCTION PROTOTYPES                   */
/************************************************************************/

void PWM_INIT(u8_t pwm_mode,u8_t prescale_mode);							//a function to initialize the PWM


void PWM_SINGLE_SETUP(u8_t DutyCycle);									   //a function to set the pwm value ONCE


void PWM_dynamics(u8_t signal_mode,u8_t DutyCycle);	         			  //a function to inc/dec the pwm signal





#endif /* PWM_INTERFACE_H_ */