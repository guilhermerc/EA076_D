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

#define TEMPERATURE_SIZE 32
#define TIME_AUX_STRING_SIZE	8
#define TEMPERATURE_STRING_SIZE 8
#define TEMPERATURE_MESSAGE_SIZE (TIME_AUX_STRING_SIZE + TEMPERATURE_STRING_SIZE + 8)

typedef struct TEMPERATURE_INFO
{
	float temperature;	// [-60˚C, 270˚C]
	uint16_t raw_temperature;
	char temperature_string[TEMPERATURE_STRING_SIZE];
	char message[TEMPERATURE_MESSAGE_SIZE];
} TEMPERATURE_INFO;

TEMPERATURE_INFO temp_info;

void temp_init();
void temp_assemble_message();

#endif /* SOURCES_TEMP_H_ */
