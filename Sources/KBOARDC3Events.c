/* ###################################################################
**     Filename    : KBOARDC3Events.c
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-05-11, 15:36, # CodeGen: 173
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         KBOARDC3_OnInterrupt - void KBOARDC3_OnInterrupt(void);
**
** ###################################################################*/
/*!
** @file KBOARDC3Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup KBOARDC3Events_module KBOARDC3Events module documentation
**  @{
*/         
/* MODULE KBOARDC3Events */

#include "KBOARDC3Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  KBOARDC3_OnInterrupt (module KBOARDC3Events)
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
  /* Write your code here ... */
}

/* END KBOARDC3Events */

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
