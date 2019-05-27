/*
 * memory.h
 *
 *  Created on: 26/05/2019
 *      Author: guilherme
 */

#ifndef SOURCES_MEMORY_H_
#define SOURCES_MEMORY_H_

#define WORDS_PER_PAGE	16
#define TEMPERATURE_LOG_PERIOD	5
#define TEMPERATURE_SIZE_IN_WORDS	4

typedef struct
{
	uint8_t timer;
	char buffer[WORDS_PER_PAGE + 1];
	uint8_t pages_written;
	uint8_t pages_dumped;
	uint8_t words_written;
} MEMORY_INFO_STRUCT;

MEMORY_INFO_STRUCT memory_info;

void memory_init();
void memory_bufferize_temperature(char * temperature);
void memory_write_page(uint8_t page, char * buffer);
void memory_dump(char * buffer);

#endif /* SOURCES_MEMORY_H_ */

