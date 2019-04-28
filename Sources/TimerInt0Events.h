/* ###################################################################
**     Filename    : TimerInt0Events.h
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
** @file TimerInt0Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
**
** @author Guilherme R C <guilherme.riciolic@gmail.com>
*/         
/*!
**  @addtogroup TimerInt0Events_module TimerInt0Events module documentation
**  @{
*/         

#ifndef __TimerInt0Events_H
#define __TimerInt0Events_H
/* MODULE TimerInt0Events */


#ifdef __cplusplus
extern "C" {
#endif 

/*
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
void TI1_OnInterrupt(void);


/* END TimerInt0Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __TimerInt0Events_H*/
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
