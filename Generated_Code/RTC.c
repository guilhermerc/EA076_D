/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RTC.c
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : RTC_LDD
**     Version     : Component 01.165, Driver 01.08, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-05-18, 14:07, # CodeGen: 250
**     Abstract    :
**         This component implements a real time clock (RTC). Actual date may also be
**         obtained and an alarm function is included.
**     Settings    :
**          Component name                                 : RTC
**          Device                                         : RTC
**          Input clock frequency [s]                      : 1 sec
**          Clock frequency [kHz]                          : 
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_RTC
**            Interrupt priority                           : medium priority
**            Interrupt                                    : INT_RTC_Seconds
**            Interrupt priority                           : medium priority
**          Min year                                       : 2000
**          Max year                                       : 2099
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto Initialization                          : no
**            Event mask                                   : 
**              OnAlarm                                    : Disabled
**              OnSecond                                   : Enabled
**              OnTimeOverflow                             : Disabled
**              OnTimeInvalid                              : Disabled
**            Time and date settings                       : 
**              Time                                       : 00:00:01
**              Date                                       : 2000-01-01
**            Alarm settings                               : Enabled
**              Alarm time                                 : 00:00:00
**              Alarm date                                 : 2000-01-01
**            Compensation settings                        : 
**              Compensation period [s]                    : 0
**              Compensation value [clock cycles]          : 0
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init    - LDD_TDeviceData * RTC_Init(LDD_TUserData *UserDataPtr, bool SoftInit);
**         GetTime - void RTC_GetTime(LDD_TDeviceData *DeviceDataPtr, LDD_RTC_TTime *TimePtr);
**         SetTime - LDD_TError RTC_SetTime(LDD_TDeviceData *DeviceDataPtr, LDD_RTC_TTime *TimePtr);
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
** @file RTC.c
** @version 01.08
** @brief
**         This component implements a real time clock (RTC). Actual date may also be
**         obtained and an alarm function is included.
*/         
/*!
**  @addtogroup RTC_module RTC module documentation
**  @{
*/         

/* MODULE RTC. */

#include "Events.h"
#include "RTC.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "RTC_PDD.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
  LDD_TUserData           *UserDataPtr;          /* Device mode user device data structure */
} RTC_TDeviceData, *RTC_TDeviceDataPtr; /* Device data structure type */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static RTC_TDeviceData DevDataPtr__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static RTC_TDeviceDataPtr INT_RTC__DEFAULT_RTOS_ISRPARAM;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static RTC_TDeviceDataPtr INT_RTC_Seconds__DEFAULT_RTOS_ISRPARAM;
/* Table of month length (in days) */
static const uint8_t ULY[] = {0U,31U,28U,31U,30U,31U,30U,31U,31U,30U,31U,30U,31U}; /* Non-leap-year */
static const uint8_t  LY[] = {0U,31U,29U,31U,30U,31U,30U,31U,31U,30U,31U,30U,31U}; /* Leap-year */
/* Number of days from begin of the year */
static const uint16_t MONTH_DAYS[] = {0U,0U,31U,59U,90U,120U,151U,181U,212U,243U,273U,304U,334U}; /* Leap-year */

/*
** ===================================================================
**     Method      :  RTC_Init (component RTC_LDD)
*/
/*!
**     @brief
**         Initializes the device. There are two modes of
**         initialization.
**         1) RTC device is NOT battery backed up. (SoftInit = FALSE)
**         All registers (interrupts, counters, clock routing �) that
**         influence RTC behavior are initialized. 
**         Note: This initialization mode doesn't preserve time and
**         date settings.
**         2) RTC device IS battery backed up.
**         (SoftInit = TRUE). Only registers that are not backed up are
**         initialized (Interrupt priority �). RTC device is running,
**         time and date a preserved, RTC interrupts (events) are
**         preserved too.
**         Allocates memory for the device data structure.
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @param
**         SoftInit        - If set to "[true]" only
**                           registers that are not battery backup are
**                           initialized (E.g. Interrupt priority in
**                           interrupt controller � )
**                           If set to "[false]" all registers are
**                           initialized.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData * RTC_Init(LDD_TUserData *UserDataPtr, bool SoftInit)
{
  RTC_TDeviceData *DevDataPtr;

  /* Allocate RTC device structure */
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DevDataPtr = &DevDataPtr__DEFAULT_RTOS_ALLOC;
  DevDataPtr->UserDataPtr = UserDataPtr; /* Store the user data */
  /* Allocate interrupt vector(s) */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_RTC__DEFAULT_RTOS_ISRPARAM = DevDataPtr;
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_RTC_Seconds__DEFAULT_RTOS_ISRPARAM = DevDataPtr;
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_RTC_ID,DevDataPtr);
  /* Enable module clock */
  /* SIM_SCGC6: RTC=1 */
  SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;
  if (!SoftInit) {
    RTC_SR = 0x00U;                    /* Disable counter */
    RTC_TPR = RTC_TPR_TPR(0x00);       /* Set prescaler register */
    RTC_TSR = RTC_TSR_TSR(0x02);       /* Set second register - 2000-01-01 0:0:1 */
    RTC_TAR = RTC_TAR_TAR(0x00);       /* Set alarm register - disable alarm */
    RTC_TCR = RTC_TCR_CIC(0x00) |
              RTC_TCR_TCV(0x00) |
              RTC_TCR_CIR(0x00) |
              RTC_TCR_TCR(0x00);       /* Set compensation */
    RTC_SR = RTC_SR_TCE_MASK;          /* Enable counter */
  }
  /* Enable interrupt */
  /* RTC_IER: TAIE=0,TOIE=0,TIIE=0 */
  RTC_IER = RTC_IER_TSIE_MASK;         /* Enable interrupts */
  /* NVIC_IPR5: PRI_20=0x80 */
  NVIC_IPR5 = (uint32_t)((NVIC_IPR5 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_20(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_20(0x80)
              ));
  /* NVIC_ISER: SETENA|=0x00100000 */
  NVIC_ISER |= NVIC_ISER_SETENA(0x00100000);
  /* NVIC_IPR5: PRI_21=0x80 */
  NVIC_IPR5 = (uint32_t)((NVIC_IPR5 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_21(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_21(0x80)
              ));
  /* NVIC_ISER: SETENA|=0x00200000 */
  NVIC_ISER |= NVIC_ISER_SETENA(0x00200000);
  return DevDataPtr;
}

/*
** ===================================================================
**     Method      :  RTC_GetTime (component RTC_LDD)
*/
/*!
**     @brief
**         Returns actual time and date. 
**         Note: Fields not supported by HW are calculated in software.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer returned by [Init] method.
**     @param
**         TimePtr         - Pointer to the time structure to
**                           fill with current time.
*/
/* ===================================================================*/
void RTC_GetTime(LDD_TDeviceData *DeviceDataPtr, LDD_RTC_TTime *TimePtr)
{
  uint32_t x;
  uint32_t Seconds, Days;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  Seconds = RTC_PDD_ReadTimeSecondsReg(RTC_BASE_PTR); /* Seconds since 2000-01-01 */
  Seconds--;
  Days = Seconds / 86400U;             /* Days */
  Seconds = Seconds % 86400U;          /* Seconds left */
  TimePtr->Hour = Seconds / 3600U;     /* Hours */
  Seconds = Seconds % 3600u;           /* Seconds left */
  TimePtr->Minute = Seconds / 60U;     /* Minutes */
  TimePtr->Second = Seconds % 60U;     /* Seconds */
  TimePtr->DayOfWeek = (Days + 6U) % 7U; /* Day of week */
  TimePtr->Year = (4U * (Days / ((4U * 365U) + 1U))) + 2000U; /* Year */
  Days = Days % ((4U * 365U) + 1U);
  if (Days == ((0U * 365U) + 59U)) { /* 59 */
    TimePtr->Day = 29U;
    TimePtr->Month = 2U;
    return;
  } else if (Days > ((0U * 365U) + 59U)) {
    Days--;
  } else {
  }
  x =  Days / 365U;
  TimePtr->Year += x;
  Days -= x * 365U;
  for (x=1U; x <= 12U; x++) {
    if (Days < ULY[x]) {
      TimePtr->Month = x;
      break;
    } else {
      Days -= ULY[x];
    }
  }
  TimePtr->Day = Days + 1U;
}

/*
** ===================================================================
**     Method      :  RTC_SetTime (component RTC_LDD)
*/
/*!
**     @brief
**         Sets new time and date.
**         Note: All LDD_RTC_TTime structure members must be correctly
**         filled in.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer returned by [Init] method.
**     @param
**         TimePtr         - Pointer to the time structure with
**                           new time to set.
**     @return
**                         - Error code, possible codes: 
**                           - ERR_OK - OK. 
**                           - ERR_DISABLED - Component is disabled. 
**                           - ERR_SPEED - Component does not work in
**                           the active clock configuration. 
**                           - ERR_RANGE - Parameter out of range.
*/
/* ===================================================================*/
LDD_TError RTC_SetTime(LDD_TDeviceData *DeviceDataPtr, LDD_RTC_TTime *TimePtr)
{
  uint32_t Seconds;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  if ((TimePtr->Year < 2000U) || (TimePtr->Year > 2099U) || (TimePtr->Month > 12U) || (TimePtr->Month == 0U) || (TimePtr->Day > 31U) || (TimePtr->Day == 0U)) { /* Test correctness of given parameters */
    return ERR_RANGE;                  /* If not correct then error */
  }
  if (TimePtr->Year & 3U) {            /* Is given year non-leap-one? */
    if (ULY[TimePtr->Month] < TimePtr->Day) { /* Does the obtained number of days exceed number of days in the appropriate month & year? */
      return ERR_RANGE;                /* If yes (incorrect date inserted) then error */
    }
  } else {                             /* Is given year leap-one? */
    if (LY[TimePtr->Month] < TimePtr->Day) { /* Does the obtained number of days exceed number of days in the appropriate month & year? */
      return ERR_RANGE;                /* If yes (incorrect date inserted) then error */
    }
  }
  Seconds = ((TimePtr->Year - 2000U) * 365U) + (((TimePtr->Year - 2000U) + 3U) / 4U); /* Compute number of days from 2000 till given year */
  Seconds += MONTH_DAYS[TimePtr->Month]; /* Add number of days till given month */
  Seconds += TimePtr->Day;             /* Add days in given month */
  if ((TimePtr->Year & 3U) || (TimePtr->Month <= 2U)) { /* For non-leap year or month <= 2, decrement day counter */
    Seconds--;
  }
  Seconds = (Seconds * 86400U) + (TimePtr->Hour * 3600U) + (TimePtr->Minute * 60U) + TimePtr->Second;
  Seconds++;
  RTC_PDD_EnableCounter(RTC_BASE_PTR, PDD_DISABLE); /* Disable counter */
  RTC_PDD_WriteTimePrescalerReg(RTC_BASE_PTR, 0x00U); /* Clear prescaler */
  RTC_PDD_WriteTimeSecondsReg(RTC_BASE_PTR, Seconds); /* Set seconds counter */
  RTC_PDD_EnableCounter(RTC_BASE_PTR, PDD_ENABLE); /* Enable counter */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  RTC_Interrupt (component RTC_LDD)
**
**     Description :
**         RTC interrupt handler
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(RTC_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  RTC_TDeviceDataPtr DevDataPtr = INT_RTC__DEFAULT_RTOS_ISRPARAM;
  uint32_t Status = RTC_PDD_ReadStatusReg(RTC_BASE_PTR);

  if ((Status & RTC_PDD_TIF_INT) != 0x00U) { /* Timer invalid (Vbat POR or RTC SW reset)? */
    /* Restart RTC module */
    RTC_PDD_EnableCounter(RTC_BASE_PTR, PDD_DISABLE); /* Disable counter */
    RTC_PDD_WriteTimePrescalerReg(RTC_BASE_PTR, 0x00U); /* Reset prescaler */
    RTC_PDD_WriteTimeSecondsReg(RTC_BASE_PTR, 0x02UL); /* Set init. time - 2000-01-01 0:0:1 (clears flag)*/
  } else if ((Status & RTC_PDD_TOF_INT) != 0x00u) { /* Timer overflow ? */
    /* Restart RTC module */
    RTC_PDD_EnableCounter(RTC_BASE_PTR, PDD_DISABLE); /* Disable counter */
    RTC_PDD_WriteTimePrescalerReg(RTC_BASE_PTR, 0x00U); /* Reset prescaler */
    RTC_PDD_WriteTimeSecondsReg(RTC_BASE_PTR, 0x02UL); /* Set init. time - 2000-01-01 0:0:1 (clears flag)*/
  } else {                             /* Alarm interrupt */
    RTC_PDD_WriteTimeAlarmReg(RTC_BASE_PTR, RTC_PDD_ReadTimeAlarmReg(RTC_BASE_PTR)); /* Clear alarm interrupt flag */
  }
}

/*
** ===================================================================
**     Method      :  RTC_SecondsInterrupt (component RTC_LDD)
**
**     Description :
**         RTC seconds interrupt handler
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(RTC_SecondsInterrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  RTC_TDeviceDataPtr DevDataPtr = INT_RTC_Seconds__DEFAULT_RTOS_ISRPARAM;
  RTC1_OnSecond(DevDataPtr->UserDataPtr);
}
/* END RTC. */

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
