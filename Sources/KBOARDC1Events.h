/* ###################################################################
**     Filename    : KBOARDC1Events.h
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
** @file KBOARDC1Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup KBOARDC1Events_module KBOARDC1Events module documentation
**  @{
*/         

#ifndef __KBOARDC1Events_H
#define __KBOARDC1Events_H
/* MODULE KBOARDC1Events */


#ifdef __cplusplus
extern "C" {
#endif 

void KBOARDC1_OnInterrupt(void);
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


/* END KBOARDC1Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __KBOARDC1Events_H*/
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