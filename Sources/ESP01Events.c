/* ###################################################################
**     Filename    : ESP01Events.c
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-23, 13:28, # CodeGen: 12
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         ESP01_OnError  - void ESP01_OnError(void);
**         ESP01_OnRxChar - void ESP01_OnRxChar(void);
**         ESP01_OnTxChar - void ESP01_OnTxChar(void);
**
** ###################################################################*/
/*!
** @file ESP01Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup ESP01Events_module ESP01Events module documentation
**  @{
*/         
/* MODULE ESP01Events */

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
**     Event       :  ESP01_OnError (module ESP01Events)
**
**     Component   :  ESP01 [AsynchroSerial]
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
void ESP01_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  ESP01_OnRxChar (module ESP01Events)
**
**     Component   :  ESP01 [AsynchroSerial]
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
void ESP01_OnRxChar(void)
{
	volatile ESP01_TComData received = '\0';

	ESP01_RecvChar(&received);	// Receiving the char from RX buffer

	// Retransmitting the received char to the Terminal
	Terminal_SendChar((Terminal_TComData)received);
}

/*
** ===================================================================
**     Event       :  ESP01_OnTxChar (module ESP01Events)
**
**     Component   :  ESP01 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ESP01_OnTxChar(void)
{
  /* Write your code here ... */
}

/* END ESP01Events */

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
