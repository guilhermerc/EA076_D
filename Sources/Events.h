/* ###################################################################
**     Filename    : Events.h
**     Project     : EA076_D
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-18, 16:31, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         CPU_OnNMIINT - void CPU_OnNMIINT(void);
**
** ###################################################################*/
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
