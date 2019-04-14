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
#include "Cpu.h"
#include "UART2Events.h"
#include "UART0.h"
#include "ASerialLdd1.h"
#include "UART2.h"
#include "ASerialLdd2.h"
#include "ADC0.h"
#include "AdcLdd1.h"
#include "TI0.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "MCUC1.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include <Cpu.h>
#include <ESP01_comm.h>
#include <LM61_temp.h>
#include <PE_Types.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ADC0Events.h"
#include "Events.h"
#include "TI0Events.h"
#include "UART0Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

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
	 * Starts the communication
	 */
	comm_init();
	temp_init();


	/*!
	 * Infinite loop that checks
	 * 	if a message was received and;
	 * 	if the last message was completely sent and;
	 * 	if the last log entry was completely sent.
	 *
	 * If all of the above tests are TRUE, then it calls the
	 * function that parses the received message. Thereafter,
	 * it calls the function that responds to the received
	 * message.
	 */
	for(;;)
	{
		if((comm_status() == AVAILABLE))
				/*
				((comm_info.message_received == TRUE) ||
						(temp_info.measurement_state == HAS_RAW_MEASUREMENT)))
				*/
		{
			if(comm_info.message_received == TRUE)
			{
				comm_parse();
				comm_response();

				comm_info.message_received = FALSE;
			}
			else if(temp_info.measurement_state == HAS_RAW_MEASUREMENT)
			{
				if(comm_info.state == WAITING_FOR_CMD)
				{
					int16_t test = -128;
					// Conversion from raw to readable message
					sprintf(message_in, "%d", test);
					strcat(message_in, TERMINATING_CHARS);

					comm_parse();
					comm_response();

					temp_info.measurement_state = REQUESTING;
				}
			}
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
