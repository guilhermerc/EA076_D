/* ###################################################################
**     Filename    : KBOARDC2Events.h
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
** @file KBOARDC2Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup KBOARDC2Events_module KBOARDC2Events module documentation
**  @{
*/         

#ifndef __KBOARDC2Events_H
#define __KBOARDC2Events_H
/* MODULE KBOARDC2Events */


#ifdef __cplusplus
extern "C" {
#endif 

void KBOARDC2_OnInterrupt(void);
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


/* END KBOARDC2Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __KBOARDC2Events_H*/
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
