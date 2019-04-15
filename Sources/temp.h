/*!
** @file temp.h
*/

/*
 * LM61_temp.h
 *
 *  Created on: 13/04/2019
 *      Author: guilherme
 */

#ifndef SOURCES_TEMP_H_
#define SOURCES_TEMP_H_

#define TEMPERATURE_SIZE 32
#define TEMPERATURE_STRING_SIZE 8
#define MAX_NUMBER_OF_SAMPLES 500

typedef enum MEASUREMENT_STATE
{
	REQUESTING,
	HAS_RAW_MEASUREMENT,
	HAS_PRINTABLE_MEASUREMENT
} MEASUREMENT_STATE;

typedef struct TEMPERATURE_INFO
{
	volatile int16_t temperature;	// [-60˚C, 270˚C]
	volatile uint16_t raw_temperature;
	volatile uint16_t curr_samples_number;
	volatile MEASUREMENT_STATE measurement_state;
} TEMPERATURE_INFO;

TEMPERATURE_INFO temp_info;

void temp_init();
void temp_assemble_message();

#endif /* SOURCES_TEMP_H_ */
