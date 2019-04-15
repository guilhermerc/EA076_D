/*!
** @file timestamp.c
*/

/*
 * Timestamp.c
 *
 *  Created on: 14/04/2019
 *      Author: guilherme
 */

#include <RTC.h>
#include <stdint.h>
#include <timestamp.h>

static void timestamp_set_time(uint32_t second, uint32_t minute, uint32_t hour,
		uint32_t day_of_week, uint32_t day, uint32_t month, uint32_t year);

/*! \brief A function that initializes the timestamp module
 *
 * This function calls the RTC initializer, getting its device data
 * pointer, which will be useful to set and get the current time.
 * Also, this function sets a standard current time.
*/
void timestamp_init()
{
	RTC_dd_ptr = RTC_Init((LDD_TUserData *)NULL, FALSE);
	timestamp_set_time(0, 0, 0, 0, 0, 0, 0);
}

/*! \brief A function that gets the current time from the RTC
 *
 * This function fills a time data structure with the current time info.
 *
 * @param
 * 		current_time_ptr	- time data structure to be filled in
*/
void timestamp_get_time(LDD_RTC_TTime * current_time_ptr)
{
	RTC_GetTime(RTC_dd_ptr, current_time_ptr);
}

/*! \brief A function that sets the current time in the RTC
 *
 * This function sets the current time in the RTC in a nice API.
 * It Is not being exported and only being used internally to this file,
 * but it might be useful at some point.
 *
*/
static void timestamp_set_time(uint32_t second, uint32_t minute, uint32_t hour,
		uint32_t day_of_week, uint32_t day, uint32_t month, uint32_t year)
{
	LDD_RTC_TTime time;

	/* Set possibly the current time */
	time.Second = second;
	time.Minute = minute;
	time.Hour = hour;
	time.DayOfWeek = day_of_week;
	time.Day = day;
	time.Month = month;
	time.Year = year;

	RTC_SetTime(RTC_dd_ptr, &time);
}
