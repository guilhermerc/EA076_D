/* ###################################################################
**     Filename    : UART0Events.c
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
** @file UART0Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
**
** @author Guilherme R C <guilherme.riciolic@gmail.com>
*/         
/*!
**  @addtogroup UART0Events_module UART0Events module documentation
**  @{
*/         
/* MODULE UART0Events */

#include <comm.h>
#include <event_ring_buff.h>
#include <LOG.h>
#include <PE_Types.h>
#include <stdint.h>
#include <UART0.h>
#include "UART0Events.h"


#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */


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
void UART0_OnError(void)
{
  /* Write your code here ... */
}

/*! @brief A handler that echoes the received char and also insert an
 * event in the event ring buffer if a complete message was received
**
** 	Follows the description generated by ProcessorExpert.
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
void UART0_OnRxChar(void)
{
	/*!
	 * Echoes the just received char
	 * Using the LOG function ensures that the next handling of an
	 * event will wait this echoing to be done. This is important as
	 * during this handling a LOG function can also be used and this
	 * message would be overwritten.
	 */
	LOG(NULL, UART0_GetPtrToLastRecvChar());

	if(UART0_HasACompleteMessage())
		event_ring_buff_insert_event(NEW_MESSAGE_FROM_TERMINAL);
}

/*! @brief A function that indicates that a character was sent into the
 * TX channel of UART0. This handler is used to trigger chained calls
 * to send a message.
**
** 	Follows the description generated by ProcessorExpert.
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
void UART0_OnTxChar(void)
{
	static uint8_t curr_idx = 0;

	UART0_TComData curr_char = log_buffer[curr_idx++];
	if(curr_char != '\0')
	{
		UART0_SendChar(curr_char);
	}
	else
	{
		curr_idx = 0;

		comm_info.loging_status = DONE;
	}
}

/* END UART0Events */

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
