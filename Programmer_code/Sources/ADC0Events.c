/* ###################################################################
**     Filename    : ADC0Events.c
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
** @file ADC0Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup ADC0Events_module ADC0Events module documentation
**  @{
*/         
/* MODULE ADC0Events */
#include "Cpu.h"
#include "Events.h"
#include "UART0Events.h"
#include "UART2Events.h"
#include "ADC0Events.h"
#include "TI0Events.h"

#include <ADC0Events.h>


#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include <LM61_temp.h>

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
void AD1_OnEnd(void)
{
	temp_info.measurement_state = HAS_RAW_MEASUREMENT;
}

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
void AD1_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

/* END ADC0Events */

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
