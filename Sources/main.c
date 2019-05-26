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
 **
 ** @author Guilherme R C <guilherme.riciolic@gmail.com>
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

#include <AT24C164.h>
#include <console.h>
#include <CPU.h>
#include <PE_Types.h>
#include <WAIT1.h>

/* User includes (#include below this line is not maintained by Processor Expert) */

/*! List of TODO's that as soon as I have time I'll integrate
 *
 *	TODO: Check if the event ring buffer indexes are properly changed
 *  TODO: Change what have to be changed due to the correct size of display = 14
 *	TODO: Protect the boundaries of motor_change_speed function
 *	TODO: Remove volatiles and try to understand why better
*/

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
	 * Initializing the modules
	 */
	/*
	event_buff_init();

	motor_init();
	temp_init();

	display_init();
	kboard_init();

	comm_init();

	rtc_init();
	*/

	console_init();

	char string[] = "Testing testing";
	char memory[16];

	/*! TODO: Try this */
	AT24C164_SelectDevice(0x00);

	AT24C164_WriteBlock(0x00, string, 16);

	WAIT1_Waitms(20);

	AT24C164_ReadBlock(0x00, memory, 16);

	console_write(NULL, memory);

	/*! TODO: Also try to change the ICR to 0x11 = 010 001
	 */

	/*!
	 * Infinite loop that checks if the event ring buffer has events to
	 * be handled.
	 */
	for(;;)
	{
		/*
		if(!event_buff_is_empty())
			event_handler(event_buff_consume_event());
		*/
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
