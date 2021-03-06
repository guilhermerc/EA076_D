/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
**
** @author Guilherme R C <guilherme.riciolic@gmail.com
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "ADC0.h"
#include "AdcLdd1.h"
#include "RTC.h"
#include "UART0.h"
#include "ASerialLdd1.h"
#include "UART2.h"
#include "ASerialLdd2.h"
#include "L293D_1_2_EN.h"
#include "PwmLdd1.h"
#include "MCUC1.h"
#include "TU2.h"
#include "L293D_1A.h"
#include "BitIoLdd1.h"
#include "L293D_2A.h"
#include "BitIoLdd2.h"
#include "NOKIA5110_CONTROLLER.h"
#include "RESpin1.h"
#include "SCEpin1.h"
#include "D_Cpin1.h"
#include "WAIT1.h"
#include "SM1.h"
#include "NOKIA5110_LIGHT.h"
#include "BitIoLdd3.h"
#include "KBOARD_C1.h"
#include "ExtIntLdd1.h"
#include "KBOARD_C2.h"
#include "ExtIntLdd2.h"
#include "KBOARD_C3.h"
#include "ExtIntLdd3.h"
#include "KBOARD_R1.h"
#include "BitIoLdd4.h"
#include "KBOARD_R2.h"
#include "BitIoLdd5.h"
#include "KBOARD_R3.h"
#include "BitIoLdd6.h"
#include "KBOARD_R4.h"
#include "BitIoLdd7.h"
#include "AT24C164.h"
#include "GI2C1.h"
#include "CI2C1.h"

#include <PE_Types.h>


#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  CPU_OnNMIINT (module Events)
**
**     Component   :  CPU [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void CPU_OnNMIINT(void);


/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  CPU [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);

void KBOARD_C3_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  KBOARD_C3_OnInterrupt (module Events)
**
**     Component   :  KBOARD_C3 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void KBOARD_C2_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  KBOARD_C2_OnInterrupt (module Events)
**
**     Component   :  KBOARD_C2 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void KBOARD_C1_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  KBOARD_C1_OnInterrupt (module Events)
**
**     Component   :  KBOARD_C1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Event       :  RTC1_OnSecond (module Events)
**
**     Component   :  RTC [RTC_LDD]
*/
/*!
**     @brief
**         Called each second if OnSecond event is enabled (see
**         [SetEventMask] and [GetEventMask] methods) and RTC device is
**         enabled. This event is available only if [Interrupt
**         service/event] is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method. 
*/
/* ===================================================================*/
void RTC1_OnSecond(LDD_TUserData *UserDataPtr);

void AD1_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  ADC0 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Event       :  UART0_OnError (module Events)
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
**     Event       :  UART0_OnRxChar (module Events)
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
**     Event       :  UART0_OnTxChar (module Events)
**
**     Component   :  UART0 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UART0_OnTxChar(void);

/*
** ===================================================================
**     Event       :  UART2_OnError (module Events)
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
**     Event       :  UART2_OnRxChar (module Events)
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
**     Event       :  UART2_OnTxChar (module Events)
**
**     Component   :  UART2 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UART2_OnTxChar(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
