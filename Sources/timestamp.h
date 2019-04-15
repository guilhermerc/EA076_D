/*
 * Timestamp.h
 *
 *  Created on: 14/04/2019
 *      Author: guilherme
 */

#ifndef PROGRAMMER_CODE_LIBRARIES_TIMESTAMP_H_
#define PROGRAMMER_CODE_LIBRARIES_TIMESTAMP_H_

#include <PE_Types.h>


#define TIME_AUX_STRING_SIZE	8

LDD_TDeviceData * RTC_dd_ptr;

void timestamp_get_time(LDD_RTC_TTime * current_time_ptr);

#endif /* PROGRAMMER_CODE_LIBRARIES_TIMESTAMP_H_ */
