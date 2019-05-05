/* ###################################################################
 **     Filename    : TimerInt1Events.c
 **     Project     : EA076_PE
 **     Processor   : MKL25Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2019-05-05, 02:00, # CodeGen: 142
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Contents    :
 **         TI1_OnInterrupt0 - void TI1_OnInterrupt0(void);
 **
 ** ###################################################################*/
/*!
 ** @file TimerInt1Events.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup TimerInt1Events_module TimerInt1Events module documentation
 **  @{
 */
/* MODULE TimerInt1Events */

#include <display.h>
#include <PE_Types.h>
#include <stamp.h>
#include <UTIL1.h>
#include "TimerInt1Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
typedef enum
{
	CLEANING,
	GETTING_CURR_TIME,
	ASSEMBLING_STRING,
	WRITING_STRING
} DISPLAY_STATE_ENUM;

#define DISPLAY_STATE_ENUM_RANGE	2

typedef enum
{
	FIRST_LINE_INDEX,
	SECOND_LINE_INDEX,
	THIRD_LINE_INDEX
} ITERATION_ENUM;

#define ITERATION_MAX	4

/*
 ** ===================================================================
 **     Event       :  TI1_OnInterrupt0 (module TimerInt1Events)
 **
 **     Component   :  TimerInt1 [TimerInt]
 **     Description :
 **         When a timer interrupt occurs this event is called (only
 **         when the component is enabled - <Enable> and the events are
 **         enabled - <EnableEvent>). This event is enabled only if a
 **         <interrupt service/event> is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void TI1_OnInterrupt0(void)
{
	static char line_string[DISPLAY_LINE_STRING_SIZE];
	static DISPLAY_STATE_ENUM state = CLEANING;
	static ITERATION_ENUM iteration = FIRST_LINE_INDEX;
	static LDD_RTC_TTime time;

	/*! TODO: Check if the current implementation makes sense, I'm sleepy */

	switch(state)
	{
	case CLEANING:
	{
		display_write_line(iteration++, "                ");
		break;
	}
	case GETTING_CURR_TIME:
	{
		stamp_get_time(&time);
		break;
	}
	case ASSEMBLING_STRING:
	{
		switch(iteration)
		{
		case FIRST_LINE_INDEX:
		{
			UTIL1_strcpy(line_string, DISPLAY_LINE_STRING_SIZE,
					"Date: ");
			UTIL1_strcatNum32uFormatted(line_string,
					DISPLAY_LINE_STRING_SIZE, time.Day, '0', 2);
			UTIL1_strcat(line_string, DISPLAY_LINE_STRING_SIZE, "/");
			UTIL1_strcatNum32uFormatted(line_string,
					DISPLAY_LINE_STRING_SIZE, time.Month, '0', 2);
			UTIL1_strcat(line_string, DISPLAY_LINE_STRING_SIZE, "/");
			UTIL1_strcatNum32uFormatted(line_string,
					DISPLAY_LINE_STRING_SIZE, time.Year, '0', 4);
			break;
		}
		case SECOND_LINE_INDEX:
		{
			UTIL1_strcpy(line_string, DISPLAY_LINE_STRING_SIZE,
					"Time: ");
			UTIL1_strcatNum32uFormatted(line_string,
					DISPLAY_LINE_STRING_SIZE, time.Hour, '0', 2);
			UTIL1_strcat(line_string, DISPLAY_LINE_STRING_SIZE, ":");
			UTIL1_strcatNum32uFormatted(line_string,
					DISPLAY_LINE_STRING_SIZE, time.Minute, '0', 2);
			UTIL1_strcat(line_string, DISPLAY_LINE_STRING_SIZE, ":");
			UTIL1_strcatNum32uFormatted(line_string,
					DISPLAY_LINE_STRING_SIZE, time.Second, '0', 2);
			break;
		}
		case THIRD_LINE_INDEX:
		{
			/*! TODO: Implement this state */
			break;
		}
		break;
		}
		state = WRITING_STRING;
	}
	case WRITING_STRING:
	{
		display_write_line(iteration, line_string);
		line_string[0] = '\0';

		if(iteration++ < ITERATION_MAX)
			state = ASSEMBLING_STRING;
		else
		{
			iteration = 0;
			state = CLEANING;
		}

		break;
	}
	}
}

/* END TimerInt1Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
