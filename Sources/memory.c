/*!
 * @file memory.c
 * @brief This file contains implementations related to the EEPROM
 * memory.
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#include <AT24C164.h>
#include <event_buff.h>
#include <memory.h>
#include <string.h>
#include <WAIT1.h>

#define MEMORY_I2C_ADDRESS	0x00
#define WRITE_CYCLE_TIME	10

void memory_read_page(uint8_t page, char * buffer);

/*! @brief A function that initializes the memory module
 *
 */
void memory_init()
{
	memory_info.timer = 0;
	memory_info.words_written = 0;
	memory_info.pages_written = 0;
	memory_info.pages_dumped = 0;
}

/*! @brief A function that bufferizes a 4-char string size representing
 * a temperature
 * @param 	temperature		A pointer to string representation of the
 * 							current temperature
 */
void memory_bufferize_temperature(char * temperature)
{
	strcpy(&(memory_info.buffer[memory_info.words_written]),
			temperature);

	memory_info.words_written += TEMPERATURE_SIZE_IN_WORDS;

	if(memory_info.words_written == WORDS_PER_PAGE)
	{
		event_buff_insert_event(MEMORY_BUFFER_FULL);
		memory_info.words_written = 0;
	}
}

/*! @brief A function that dumps the memory's content into a buffer
 *
 * @param 	buffer	A pointer to buffer which will receive the memory's
 * 					content
 */
void memory_dump(char * buffer)
{
	for(uint8_t page = memory_info.pages_dumped, i = 0;
			page < memory_info.pages_written; page++)
	{
		memory_read_page(page, &(buffer[(i++) * WORDS_PER_PAGE]));
	}
	memory_info.pages_dumped = memory_info.pages_written;
}

/*! @brief A function that writes a single page in the memory
 *
 * @param 	page	The page index on which the content of 'buffer'
 * 					will be written
 * @param 	buffer	The content to write in the memory page
 */
void memory_write_page(uint8_t page, char * buffer)
{
	AT24C164_SelectDevice(MEMORY_I2C_ADDRESS);

	AT24C164_WriteBlock(page * WORDS_PER_PAGE, buffer,
			AT24C164_PAGE_SIZE);
	WAIT1_Waitms(WRITE_CYCLE_TIME * 2);

	memory_info.pages_written++;
}

/*! @brief A function that reads a single page of the memory
 *
 * @param 	page	The page index of which the content will be read
 * @param 	buffer	The buffer that will be filled with the content of
 * 					a memory page indexed by 'page'
 */
void memory_read_page(uint8_t page, char * buffer)
{
	AT24C164_SelectDevice(MEMORY_I2C_ADDRESS);

	AT24C164_ReadBlock(page * WORDS_PER_PAGE, buffer,
			AT24C164_PAGE_SIZE);
	/*! TODO: Check if this is really necessary */
	WAIT1_Waitms(WRITE_CYCLE_TIME * 2);
}
