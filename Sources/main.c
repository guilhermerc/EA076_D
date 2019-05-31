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
#include "CPU.h"
#include "Events.h"
#include "ADC0.h"
#include "AdcLdd1.h"
#include "RTC.h"
#include "UART0.h"
#include "ASerialLdd1.h"
#include "UART2.h"
#include "ASerialLdd2.h"
#include "L293D_1_2_EN.h"
#include "PwmLdd1.h"
#include "MCUC1.h"
#include "TU2.h"
#include "L293D_1A.h"
#include "BitIoLdd1.h"
#include "L293D_2A.h"
#include "BitIoLdd2.h"
#include "NOKIA5110_CONTROLLER.h"
#include "RESpin1.h"
#include "SCEpin1.h"
#include "D_Cpin1.h"
#include "WAIT1.h"
#include "SM1.h"
#include "NOKIA5110_LIGHT.h"
#include "BitIoLdd3.h"
#include "KBOARD_C1.h"
#include "ExtIntLdd1.h"
#include "KBOARD_C2.h"
#include "ExtIntLdd2.h"
#include "KBOARD_C3.h"
#include "ExtIntLdd3.h"
#include "KBOARD_R1.h"
#include "BitIoLdd4.h"
#include "KBOARD_R2.h"
#include "BitIoLdd5.h"
#include "KBOARD_R3.h"
#include "BitIoLdd6.h"
#include "KBOARD_R4.h"
#include "BitIoLdd7.h"
#include "AT24C164.h"
#include "GI2C1.h"
#include "CI2C1.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include <comm.h>
#include <console.h>
#include <CPU.h>
#include <display.h>
#include <event_buff.h>
#include <kboard.h>
#include <memory.h>
#include <motor.h>
#include <rtc.h>
#include <temp.h>

/* User includes (#include below this line is not maintained by Processor Expert) */

/*! List of TODO's that as soon as I have time I'll integrate
 *
 *  TODO: Change what have to be changed due to the correct size of
 *  display = 14.
 *	TODO: Protect the boundaries of motor_change_speed function.
 *	TODO: I should have logged the raw value of temperature since it
 *	uses only 2 bytes instead of 4 bytes used by the its string
 *	representation.
 *  TODO: I should handle the border of EEPROM memory and treat it as a
 *  "ring memory". I'm not even handling the case in which all of the
 *  pages were already written.
 *  */

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
	event_buff_init();

	motor_init();
	temp_init();

	rtc_init();

	display_init();
	kboard_init();

	memory_init();

	console_init();
	comm_init();

	/*!
	 * Infinite loop that checks if the event ring buffer has events to
	 * be handled.
	 */
	for(;;)
	{
		if(!event_buff_is_empty())
			event_handler(event_buff_consume_event());
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
