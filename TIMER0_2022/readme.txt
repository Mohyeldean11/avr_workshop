									/************************************************************************/
									/* Name: TIMER_PROGRAM.c                                                */
									/* Author: MOHIEE ELDEAN                                                */
									/* Version: V1.0                                                        */
									/* Usage: This file contains logical implementations of TIMER Module    */
									/************************************************************************/

									/************************************************************************/
									/*				INSTRUCTIONS                            */
									/************************************************************************/



INCASE FOR PWM MODE OR COMPARE MATCH MODE:

1-USE THE TIMER0 COMPMATCH_SETUP FUNCTION OR THE PWM_SETUP TO INITIALIZE THE VALUES WHETHER THE DUTY CYCLES OR THE COMPARE VALUE

2-USE THE CALLBACK_FUNC TO ASSIGN THE FUNCTION THAT YOU WANTED TO BE CALLED WHEN THE INTERRUPT IS GENERATED IN CASE OF THE COMPARE MATCH MODE

3-FINALLY USE THE TIMER0 INITIALIZING TO CHOOSE THE MODE AND THE PRESCALER AND TO ACTIVATE THE INTERRUPT FLAG ATLAST
								
								

OTHER FUNCTIONS:

-YOU CAN SHUT DOWN THE TIMER BY USING THE TIMER0_SHUTDOWN FUNCTION "THE NAME SPEAKS ABOUT ITSELF XD"
-IF YOU WANT TO READ THE VALUE THAT THE TIMER REACHED YOU CAN USE THE TIMER0_READVALUE.
