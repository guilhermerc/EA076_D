/*!
** @file temp.h
** @brief This file exports what is necessary from temp.c
**
** @author Guilherme R C <guilherme.riciolic@gmail.com>
*/

/*
 * LM61_temp.h
 *
 *  Created on: 13/04/2019
 *      Author: guilherme
 */

#ifndef SOURCES_TEMP_H_
#define SOURCES_TEMP_H_

#include <timestamp.h>

#define TEMPERATURE_SIZE 32
#define TEMPERATURE_STRING_SIZE 8
#define TEMPERATURE_MESSAGE_SIZE (TIME_AUX_STRING_SIZE + TEMPERATURE_STRING_SIZE + 8)

#define MAX_NUMBER_OF_SAMPLES 500

typedef struct TEMPERATURE_INFO
{
	volatile float temperature;	// [-60˚C, 270˚C]
	volatile uint16_t raw_temperature;
	volatile uint16_t curr_samples_number;
	volatile char message[TEMPERATURE_MESSAGE_SIZE];
} TEMPERATURE_INFO;

TEMPERATURE_INFO temp_info;

void temp_init();
void temp_assemble_message();

#endif /* SOURCES_TEMP_H_ */
