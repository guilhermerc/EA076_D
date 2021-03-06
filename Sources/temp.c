/*!
** @file temp.c
** @brief This file contains implementations related to the temperature
** reading
**
** @author Guilherme R C <guilherme.riciolic@gmail.com>
*/

#include <ADC0.h>
#include <stdio.h>
#include <string.h>
#include <temp.h>

#define ADC_AREF		3300
#define ADC_MAX_RANGE	65536

#define ANGULAR_CONV_CONST	10.0
#define LINEAR_CONV_CONST	600.0

/*! @brief A function that initializes the temperature module
 *
 * This function initializes the temp_info structure and also enables
 * the events from the TimerInt0 and ADC0 PE modules.
*/
void temp_init()
{
	temp_info.temperature = 0;
	temp_info.raw_temperature = 0;
	ADC0_EnableEvent();
}

/*! @brief A function that converts a raw reading to a temperature
 *
 * Using the ADC0 configuration (ADC_AREF and ADC_MAX_RANGE) and the
 * correspondence between voltage and temperature equation given in the
 * LM61 datasheet, this function sets the 'temperature' field from the
 * 'temp_info' structure.
*/
void temp_convert_raw_value()
{
	// T ˚C = (VO - 600 mV) / (+10 mV/˚C)
	uint16_t raw_temperature_in_mv = (temp_info.raw_temperature *
			ADC_AREF) / ADC_MAX_RANGE;
	temp_info.temperature = ((float) raw_temperature_in_mv - LINEAR_CONV_CONST) /
			ANGULAR_CONV_CONST;
}

/*! @brief A function that assembles a message to be published
 *
 * This function assembles a message containing a time stamp and the
 * current temperature.
*/
void temp_assemble_message()
{
	temp_convert_raw_value();

	sprintf(temp_info.temperature_string, "%.1f",
			temp_info.temperature);
	strcpy(temp_info.message, temp_info.temperature_string);
}
