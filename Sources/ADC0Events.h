/* ###################################################################
**     Filename    : ADC0Events.h
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-04-13, 10:42, # CodeGen: 61
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         AD1_OnEnd            - void AD1_OnEnd(void);
**         AD1_OnCalibrationEnd - void AD1_OnCalibrationEnd(void);
**
** ###################################################################*/
/*!
** @file ADC0Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup ADC0Events_module ADC0Events module documentation
**  @{
*/         

#ifndef __ADC0Events_H
#define __ADC0Events_H
/* MODULE ADC0Events */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "ADC0.h"
#include "AdcLdd1.h"
#include "RTC.h"
#include "TimerInt0.h"
#include "TimerIntLdd1.h"
#include "UART0.h"
#include "ASerialLdd1.h"
#include "UART2.h"
#include "ASerialLdd2.h"
#include "TU1.h"
#include "MCUC1.h"


#ifdef __cplusplus
extern "C" {
#endif 

void AD1_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD1_OnEnd (module ADC0Events)
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

void AD1_OnCalibrationEnd(void);
/*
** ===================================================================
**     Event       :  AD1_OnCalibrationEnd (module ADC0Events)
**
**     Component   :  ADC0 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


/* END ADC0Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __ADC0Events_H*/
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
