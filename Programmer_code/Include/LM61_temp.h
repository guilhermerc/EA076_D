/*
 * LM61_temp.h
 *
 *  Created on: 13/04/2019
 *      Author: guilherme
 */

#ifndef SOURCES_LM61_TEMP_H_
#define SOURCES_LM61_TEMP_H_

#define TEMPERATURE_SIZE 32

typedef enum MEASUREMENT_STATE
{
	REQUESTING,
	HAS_RAW_MEASUREMENT,
	HAS_PRINTABLE_MEASUREMENT
} MEASUREMENT_STATE;

typedef struct TEMPERATURE_INFO
{
	MEASUREMENT_STATE measurement_state;
} TEMPERATURE_INFO;

TEMPERATURE_INFO temp_info;

void temp_init();

#endif /* SOURCES_LM61_TEMP_H_ */
