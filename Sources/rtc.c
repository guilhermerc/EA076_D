/*!
** @file rtc.c
** @brief This file contains implementations related to the
** RTC operation
**
** @author Guilherme R C <guilherme.riciolic@gmail.com>
*/
#include <rtc.h>
#include <RTC.h>
#include <stdint.h>

#define CURRENT_SECOND		0
#define CURRENT_MINUTE		0
#define CURRENT_HOUR		0
#define CURRENT_DAY_OF_WEEK	0
#define CURRENT_DAY			1
#define CURRENT_MONTH		1
#define CURRENT_YEAR		2000

static void rtc_set_time(uint32_t second, uint32_t minute, uint32_t hour,
		uint32_t day_of_week, uint32_t day, uint32_t month, uint32_t year);

/*! @brief A function that initializes the time stamp module
 *
 * This function calls the RTC initializer, getting its device data
 * pointer, which will be useful to set and get the current time. Also,
 * this function sets a standard current time.
*/
void rtc_init()
{
	RTC_dd_ptr = RTC_Init((LDD_TUserData *)NULL, FALSE);
	rtc_set_time(CURRENT_SECOND, CURRENT_MINUTE, CURRENT_HOUR,
			CURRENT_DAY_OF_WEEK, CURRENT_DAY, CURRENT_MONTH, CURRENT_YEAR);
}

/*! @brief A function that gets the current time from RTC
 *
 * This function fills a time data structure with the current time
 * info.
 *
 * @param	current_time_ptr	Time data structure to be filled
*/
void rtc_get_time(LDD_RTC_TTime * current_time_ptr)
{
	RTC_GetTime(RTC_dd_ptr, current_time_ptr);
}

void rtc_set_current_time(uint32_t second, uint32_t minute,
		uint32_t hour)
{
	rtc_set_time(second, minute, hour, CURRENT_DAY_OF_WEEK,
			CURRENT_DAY, CURRENT_MONTH, CURRENT_YEAR);
}

/*! @brief A function that sets the current time in the RTC
 *
 * This function sets the current time in the RTC with a nice
 * interface. It is not being exported and only being used internally
 * to this file, but it might be useful at some point.
 *
*/
static void rtc_set_time(uint32_t second, uint32_t minute, uint32_t hour,
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
