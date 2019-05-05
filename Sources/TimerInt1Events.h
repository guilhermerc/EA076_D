/* ###################################################################
**     Filename    : TimerInt1Events.h
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
** @file TimerInt1Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup TimerInt1Events_module TimerInt1Events module documentation
**  @{
*/         

#ifndef __TimerInt1Events_H
#define __TimerInt1Events_H
/* MODULE TimerInt1Events */


#ifdef __cplusplus
extern "C" {
#endif 

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
void TI1_OnInterrupt0(void);


/* END TimerInt1Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __TimerInt1Events_H*/
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
