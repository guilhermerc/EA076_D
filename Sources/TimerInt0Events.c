/* ###################################################################
**     Filename    : TimerInt0Events.c
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-04-14, 22:07, # CodeGen: 97
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         TI1_OnInterrupt - void TI1_OnInterrupt(void);
**
** ###################################################################*/
/*!
** @file TimerInt0Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup TimerInt0Events_module TimerInt0Events module documentation
**  @{
*/         
/* MODULE TimerInt0Events */

#include <ADC0.h>
#include <PE_Types.h>
#include <temp.h>
#include "TimerInt0Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*! \brief A handler that requests a new ADC measurement at each 2 ms
**
** 	Follows the description generated by ProcessorExpert.
** ===================================================================
**     Event       :  TI1_OnInterrupt (module TimerInt0Events)
**
**     Component   :  TimerInt0 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
	ADC0_Measure(FALSE);
}

/* END TimerInt0Events */

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
