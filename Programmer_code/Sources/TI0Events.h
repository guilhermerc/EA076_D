/* ###################################################################
**     Filename    : TI0Events.h
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
** @file TI0Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup TI0Events_module TI0Events module documentation
**  @{
*/         

#ifndef __TI0Events_H
#define __TI0Events_H
/* MODULE TI0Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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

#ifdef __cplusplus
extern "C" {
#endif 

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
void TI1_OnInterrupt(void);


/* END TI0Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __TI0Events_H*/
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
