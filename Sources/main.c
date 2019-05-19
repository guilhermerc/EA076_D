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

#include <CPU.h>
#include <display.h>
#include <kboard.h>
#include <PE_Types.h>

/* User includes (#include below this line is not maintained by Processor Expert) */
volatile bool external_interrupt = FALSE;
volatile KBOARD_KEY_TYPE last_key_pressed = NULL;
extern volatile bool timeout_reached;

/*! List of TODO's that as soon as I have time I'll integrate
 *
 *	TODO: Check if the event ring buffer indexes are properly changed
 *  TODO: Use the average calculation integrated in the ADC component (PE)
 *  TODO: Change ANTICLOCKWISE to COUNTERCLOCKWISE
 *  TODO: Change what have to be changed due to the correct size of display = 14
 * 	TODO: The keyboard external interruptions should put an event in the event buffer
 * 	TODO: The timeout also should put an event in the event buffer
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
	 * Initializing the keyboard module
	 */
	display_init();
	kboard_init();

	// comm_init();
	// console_init();
	// display_init();
	// event_buff_init();
	// kboard_init();
	// motor_init();
	// rtc_init();
	// temp_init();

	/*
	 * Infinite loop that checks if the event ring buffer has events to
	 * be handled.
	for(;;)
	{
		if(!event_buff_is_empty())
			event_handler(event_buff_consume_event());
	}
	 *
	 */

	for(;;)
	{
		if(external_interrupt)
		{
			display_fsm(last_key_pressed);
			external_interrupt = FALSE;
		}

		if(timeout_reached)
		{
			display_update(OPTIONS_MENU_1);
			timeout_reached = FALSE;
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
