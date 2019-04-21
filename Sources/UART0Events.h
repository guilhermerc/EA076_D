/* ###################################################################
**     Filename    : UART0Events.h
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-29, 22:11, # CodeGen: 42
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         UART0_OnError  - void UART0_OnError(void);
**         UART0_OnRxChar - void UART0_OnRxChar(void);
**
** ###################################################################*/
/*!
** @file UART0Events.h
** @version 01.00
** @brief
**         This module contains the handlers related to
**         UART0 interruptions (events).
*/         
/*!
**  @addtogroup UART0Events_module UART0Events module documentation
**  @{
*/         

#ifndef __UART0Events_H
#define __UART0Events_H
/* MODULE UART0Events */


#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  UART0_OnError (module UART0Events)
**
**     Component   :  UART0 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UART0_OnError(void);

/*
** ===================================================================
**     Event       :  UART0_OnRxChar (module UART0Events)
**
**     Component   :  UART0 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UART0_OnRxChar(void);


/*
** ===================================================================
**     Event       :  UART0_OnTxChar (module UART0Events)
**
**     Component   :  UART0 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UART0_OnTxChar(void);

/* END UART0Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __UART0Events_H*/
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
