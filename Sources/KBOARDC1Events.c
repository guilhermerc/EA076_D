/* ###################################################################
**     Filename    : KBOARDC1Events.c
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
**         KBOARDC1_OnInterrupt - void KBOARDC1_OnInterrupt(void);
**
** ###################################################################*/
/*!
** @file KBOARDC1Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup KBOARDC1Events_module KBOARDC1Events module documentation
**  @{
*/         
/* MODULE KBOARDC1Events */

#include "KBOARDC1Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  KBOARDC1_OnInterrupt (module KBOARDC1Events)
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
  /* Write your code here ... */
}

/* END KBOARDC1Events */

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
