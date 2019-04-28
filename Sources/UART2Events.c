/* ###################################################################
**     Filename    : UART2Events.c
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
** @file UART2Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
**
** @author Guilherme R C <guilherme.riciolic@gmail.com
*/         
/*!
**  @addtogroup UART2Events_module UART2Events module documentation
**  @{
*/         
/* MODULE UART2Events */

#include <comm.h>
#include <event_ring_buff.h>
#include <stdint.h>
#include <UART2.h>
#include "UART2Events.h"


#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

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
void UART2_OnError(void)
{
  /* Write your code here ... */
}

/*! @brief A handler that checks if a complete message has been
 * received. If so, it inserts a new event in the event ring buffer.
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
void UART2_OnRxChar(void)
{
	if(UART2_HasACompleteMessage())
		event_ring_buff_insert_event(NEW_MESSAGE_FROM_BROKER);
}

/*! @brief A handler that indicates that a character was sent into the
 * TX channel of UART2. This handler is used to trigger chained calls
 * until a complete message is sent.
**
** 	Follows the description generated by ProcessorExpert.
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
void UART2_OnTxChar(void)
{
	static uint8_t curr_idx = 0;

	UART2_TComData curr_char = comm_info.message_out[curr_idx++];
	if(curr_char != '\0')
	{
		UART2_SendChar(curr_char);
	}
	else
	{
		curr_idx = 0;
		comm_info.sending_status = DONE;
	}
}

/* END UART2Events */

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
