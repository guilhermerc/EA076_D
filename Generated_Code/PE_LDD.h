/** ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PE_LDD.h
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Version     : Component 01.025, Driver 01.04, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-05-18, 23:34, # CodeGen: 257
**     Abstract    :
**
**     Settings    :
**
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file PE_LDD.h                                                  
** @version 01.04
** @brief
**
*/         
/*!
**  @addtogroup PE_LDD_module PE_LDD module documentation
**  @{
*/         
#ifndef __PE_LDD_H
#define __PE_LDD_H

/* MODULE PE_LDD. */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "ADC0.h"
#include "AdcLdd1.h"
#include "RTC.h"
#include "TimerInt0.h"
#include "TimerIntLdd1.h"
#include "TimerInt1.h"
#include "TimerIntLdd2.h"
#include "UART2.h"
#include "ASerialLdd2.h"
#include "UART0.h"
#include "ASerialLdd1.h"
#include "L293D_1_2_EN.h"
#include "PwmLdd1.h"
#include "TU1.h"
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
#include "TU3.h"
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


/*
** ===================================================================
** Function prototypes
** ===================================================================
*/

/*
** ===================================================================
**     Method      :  CPU_PE_FillMemory (component MKL25Z128LK4)
*/
/*!
**     @brief
**         Fills a memory area block by a specified value.
**     @param
**       SourceAddressPtr - Source address pointer.
**     @param
**       c - A value used to fill a memory block.
**     @param
**       len - Length of a memory block to fill.
*/
/* ===================================================================*/
void PE_FillMemory(register void* SourceAddressPtr, register uint8_t c, register uint32_t len);

/*
** ===================================================================
**     Method      :  CPU_PE_PeripheralUsed (component MKL25Z128LK4)
*/
/*!
**     @brief
**         Returns information whether a peripheral is allocated by PEx 
**         or not.
**     @param
**       PrphBaseAddress - Base address of a peripheral.
**     @return
**       TRUE if a peripheral is used by PEx or FALSE if it isn't used.
*/
/* ===================================================================*/
bool PE_PeripheralUsed(uint32_t PrphBaseAddress);

/*
** ===================================================================
**     Method      :  CPU_LDD_SetClockConfiguration (component MKL25Z128LK4)
*/
/*!
**     @brief
**         Changes the clock configuration of all LDD components in a 
**         project.
**     @param
**       ClockConfiguration - New CPU clock configuration changed by CPU SetClockConfiguration method.
*/
/* ===================================================================*/
void LDD_SetClockConfiguration(LDD_TClockConfiguration ClockConfiguration);

/* END PE_LDD. */


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
