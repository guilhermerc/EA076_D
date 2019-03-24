/* ###################################################################
**     Filename    : TerminalEvents.h
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-23, 11:19, # CodeGen: 10
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Terminal_OnError  - void Terminal_OnError(void);
**         Terminal_OnRxChar - void Terminal_OnRxChar(void);
**         Terminal_OnTxChar - void Terminal_OnTxChar(void);
**
** ###################################################################*/
/*!
** @file TerminalEvents.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup TerminalEvents_module TerminalEvents module documentation
**  @{
*/         

#ifndef __TerminalEvents_H
#define __TerminalEvents_H
/* MODULE TerminalEvents */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Terminal.h"
#include "ASerialLdd1.h"
#include "ESP01.h"
#include "ASerialLdd2.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Terminal_OnError (module TerminalEvents)
**
**     Component   :  Terminal [AsynchroSerial]
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
void Terminal_OnError(void);

/*
** ===================================================================
**     Event       :  Terminal_OnRxChar (module TerminalEvents)
**
**     Component   :  Terminal [AsynchroSerial]
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
void Terminal_OnRxChar(void);

/* END TerminalEvents */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __TerminalEvents_H*/
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
