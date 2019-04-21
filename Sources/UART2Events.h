/* ###################################################################
**     Filename    : UART2Events.h
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-04-14, 12:42, # CodeGen: 81
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         UART2_OnError  - void UART2_OnError(void);
**         UART2_OnRxChar - void UART2_OnRxChar(void);
**         UART2_OnTxChar - void UART2_OnTxChar(void);
**
** ###################################################################*/
/*!
** @file UART2Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup UART2Events_module UART2Events module documentation
**  @{
*/         

#ifndef __UART2Events_H
#define __UART2Events_H
/* MODULE UART2Events */

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  UART2_OnError (module UART2Events)
**
**     Component   :  UART2 [AsynchroSerial]
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
void UART2_OnError(void);

/*
** ===================================================================
**     Event       :  UART2_OnRxChar (module UART2Events)
**
**     Component   :  UART2 [AsynchroSerial]
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
void UART2_OnRxChar(void);

/*
** ===================================================================
**     Event       :  UART2_OnTxChar (module UART2Events)
**
**     Component   :  UART2 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UART2_OnTxChar(void);


/* END UART2Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __UART2Events_H*/
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
