/* ###################################################################
**     Filename    : UART2Events.h
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-29, 22:15, # CodeGen: 43
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         UART2_OnError  - void UART2_OnError(void);
**         UART2_OnRxChar - void UART2_OnRxChar(void);
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

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "UART0.h"
#include "ASerialLdd1.h"
#include "UART2.h"
#include "ASerialLdd2.h"

#ifdef __cplusplus
extern "C" {
#endif 

#define MESSAGE_BUFFER_SIZE	512

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
