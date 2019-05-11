/* ###################################################################
**     Filename    : KBOARDC2Events.c
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
**         KBOARDC2_OnInterrupt - void KBOARDC2_OnInterrupt(void);
**
** ###################################################################*/
/*!
** @file KBOARDC2Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup KBOARDC2Events_module KBOARDC2Events module documentation
**  @{
*/         
/* MODULE KBOARDC2Events */

#include "KBOARDC2Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  KBOARDC2_OnInterrupt (module KBOARDC2Events)
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
  /* Write your code here ... */
}

/* END KBOARDC2Events */

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
