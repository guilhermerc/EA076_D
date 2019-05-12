 /* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
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
/* MODULE Events */

#include <kboard.h>
#include <WAIT1.h>
#include "CPU.h"
#include "Events.h"

#include <PORT_PDD.h>


#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

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
void CPU_OnNMIINT(void)
{
  /* Write your code here ... */
}

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
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  KBOARDC3_OnInterrupt (module Events)
**
**     Component   :  KBOARDC3 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void KBOARDC3_OnInterrupt(void)
{
	WAIT1_Waitms(300);
	PORT_PDD_ClearPinInterruptFlag(PORTA_BASE_PTR, KBOARD_C3_PIN);
}


/*
** ===================================================================
**     Event       :  KBOARDC2_OnInterrupt (module Events)
**
**     Component   :  KBOARDC2 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void KBOARDC2_OnInterrupt(void)
{
	WAIT1_Waitms(300);
	PORT_PDD_ClearPinInterruptFlag(PORTA_BASE_PTR, KBOARD_C2_PIN);
}

/*
** ===================================================================
**     Event       :  KBOARDC1_OnInterrupt (module Events)
**
**     Component   :  KBOARDC1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void KBOARDC1_OnInterrupt(void)
{
	WAIT1_Waitms(300);
	PORT_PDD_ClearPinInterruptFlag(PORTA_BASE_PTR, KBOARD_C1_PIN);
}

/* END Events */

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
