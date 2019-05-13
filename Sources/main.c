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
	display_write_line(1, "Last key press");
	kboard_init();


	/*! TODO: I tried so hard to make this display thing works but it
	 * doesn't work.
	 * 1. I tried to reconfigure the PE components again.
	 * 2. I tried to delete and create new PE components.
	 * 3. I checked the connections and everything seems OK.
	 * 4. I checked that both SPIMaster_LDD and WAIT components are
	 * initialized.
	 *
	 * The funny thing is: If I write on the display on main loop, it
	 * works just fine. The problem only happens when I call the
	 * display functions inside the interruptions' handlers.
	 * As far as I was able to debug, the program keeps stuck in
	 * NOKIA5110_CONTROLLER.c#262. I didn't have time to investigate
	 * any further.
	 */

	for(;;)
	{
		if(external_interrupt)
		{
			switch(last_key_pressed)
			{
			case KEY_0:
			{
				display_write_line(2, "0");
				break;
			}
			case KEY_1:
			{
				display_write_line(2, "1");
				break;
			}
			case KEY_2:
			{
				display_write_line(2, "2");
				break;
			}
			case KEY_3:
			{
				display_write_line(2, "3");
				break;
			}
			case KEY_4:
			{
				display_write_line(2, "4");
				break;
			}
			case KEY_5:
			{
				display_write_line(2, "5");
				break;
			}
			case KEY_6:
			{
				display_write_line(2, "6");
				break;
			}
			case KEY_7:
			{
				display_write_line(2, "7");
				break;
			}
			case KEY_8:
			{
				display_write_line(2, "8");
				break;
			}
			case KEY_9:
			{
				display_write_line(2, "9");
				break;
			}
			case KEY_ASTERISK:
			{
				display_write_line(2, "*");
				break;
			}
			case KEY_HASHTAG:
			{
				display_write_line(2, "#");
				break;
			}
			}
			external_interrupt = FALSE;
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
