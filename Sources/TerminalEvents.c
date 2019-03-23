/* ###################################################################
**     Filename    : TerminalEvents.c
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
** @file TerminalEvents.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup TerminalEvents_module TerminalEvents module documentation
**  @{
*/         
/* MODULE TerminalEvents */

#include "Cpu.h"
#include "Events.h"
#include "TerminalEvents.h"
#include "ESP01Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

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
void Terminal_OnError(void)
{
  /* Write your code here ... */
}

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
void Terminal_OnRxChar(void)
{
	volatile Terminal_TComData received = '\0';

	Terminal_RecvChar(&received);	// Receiving the char from the RX buffer

	Terminal_SendChar(received);	// Echoing the received char to the Terminal
	// Retransmitting the received char to the ESP-01 module
	ESP01_SendChar((ESP01_TComData)received);
}

/*
** ===================================================================
**     Event       :  Terminal_OnTxChar (module TerminalEvents)
**
**     Component   :  Terminal [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Terminal_OnTxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Terminal_OnFullRxBuf (module TerminalEvents)
**
**     Component   :  Terminal [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Terminal_OnFullRxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Terminal_OnFreeTxBuf (module TerminalEvents)
**
**     Component   :  Terminal [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Terminal_OnFreeTxBuf(void)
{
  /* Write your code here ... */
}

/* END TerminalEvents */

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
