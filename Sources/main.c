/* ###################################################################
 **     Filename    : main.c
 **     Project     : EA076_D
 **     Processor   : MKL25Z128VLK4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2019-03-18, 16:31, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         This module contains user's application code.
 **         This module contains the main loop, in which
 **         communication-related flags are monitored.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

#include <CPU.h>
#include <dc_motor.h>
#include <PE_Types.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* User includes (#include below this line is not maintained by Processor Expert) */
#define OPERATION_CHAR_INDEX	0
#define ARGUMENT_STRING_START_INDEX	2

#define MESSAGE_IN_SIZE	512
char message_in[MESSAGE_IN_SIZE];
bool message_received = FALSE;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */

	/*!
	 * Initializing the communication (actually a minimalist version
	 * of it) and dc motor modules.
	 */
	message_received = FALSE;
	dc_motor_init();

	/*!
	 * Infinite loop that checks if a message was received from the
	 * Terminal. If it was, then the msg is parsed and handled.
	 *
	 * NOTE: This code is only used to test the dc_motor library.
	 */
	for(;;)
	{
		static int16_t pwm = 0;
		/*!
		 * Checks if a message was received. The flag
		 * 'message_received' is set when a sequence of "\r\n" arrives
		 * at UART0 RX (check UART0Events.c to more on that).
		 */
		if(message_received == TRUE)
		{
			/*!
			 *	"P": PWM setting
			 */
			if(message_in[OPERATION_CHAR_INDEX] == 'P')
			{
				message_in[strlen(message_in) - 1] = '\0';
				pwm = atoi(message_in + ARGUMENT_STRING_START_INDEX);

				/*!
				 * This function is responsible for ensuring that the
				 * PWM passed as argument is valid
				 */
				dc_motor_set_pwm(pwm);
			}
			/*!
			 * "D": Direction setting
			 */
			else if(message_in[OPERATION_CHAR_INDEX]  == 'D')
			{
				if(strcmp((message_in + ARGUMENT_STRING_START_INDEX),
						"CLOCKWISE\n") == 0)
				{
					dc_motor_set_dir(CLOCKWISE);
				}
				else if(strcmp((message_in + ARGUMENT_STRING_START_INDEX),
						"ANTICLOCKWISE\n") == 0)
				{
					dc_motor_set_dir(ANTICLOCKWISE);
				}
			}
			/*!
			 * "S": Stops the motor
			 */
			else if(message_in[OPERATION_CHAR_INDEX] == 'S')
			{
				dc_motor_set_pwm(MINIMUM_PWM);
			}
			/*!
			 * "C": Continues to spin the motor with the last PWM
			 * setted
			 */
			else if(message_in[OPERATION_CHAR_INDEX] == 'C')
			{
				dc_motor_set_pwm(pwm);
			}
		message_received = FALSE;
		}
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
