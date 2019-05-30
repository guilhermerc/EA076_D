/*!
** @file rtc.h
** @brief This file exports what is necessary from rtc.c
**
** @author Guilherme R C <guilherme.riciolic@gmail.com>
*/

#ifndef PROGRAMMER_CODE_LIBRARIES_STAMP_H_
#define PROGRAMMER_CODE_LIBRARIES_STAMP_H_

#include <PE_Types.h>

LDD_TDeviceData * RTC_dd_ptr;

void rtc_init();
void rtc_get_time(LDD_RTC_TTime * current_time_ptr);
void rtc_set_current_time(uint32_t second, uint32_t minute,
		uint32_t hour);

#endif /* PROGRAMMER_CODE_LIBRARIES_STAMP_H_ */
