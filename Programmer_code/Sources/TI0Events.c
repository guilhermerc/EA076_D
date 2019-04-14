/* ###################################################################
**     Filename    : TI0Events.c
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-04-13, 12:59, # CodeGen: 68
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         TI1_OnInterrupt - void TI1_OnInterrupt(void);
**
** ###################################################################*/
/*!
** @file TI0Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup TI0Events_module TI0Events module documentation
**  @{
*/         
/* MODULE TI0Events */

#include <ADC0.h>
#include <ADC0Events.h>
#include <ESP01_comm.h>
#include <Events.h>
#include <LM61_temp.h>
#include <PE_Types.h>
#include <string.h>
#include <TI0Events.h>
#include <UART0Events.h>
#include "Cpu.h"
#include "Events.h"
#include "UART0Events.h"
#include "UART2Events.h"
#include "ADC0Events.h"
#include "TI0Events.h"


#ifdef __cplusplus
extern "C" {
#endif

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module TI0Events)
**
**     Component   :  TI0 [TimerInt]
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
	if(temp_info.measurement_state == REQUESTING)
		ADC0_Measure(FALSE);
}

/* END TI0Events */

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
