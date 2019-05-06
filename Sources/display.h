/*
 * display.h
 *
 *  Created on: 04/05/2019
 *      Author: guilherme
 */

#ifndef SOURCES_DISPLAY_H_
#define SOURCES_DISPLAY_H_

#include <PE_Types.h>

#define DISPLAY_LINE_STRING_SIZE	20

void display_init();
void display_write_line(uint8_t line, char * string);
void display_clean_line(uint8_t line);

#endif /* SOURCES_DISPLAY_H_ */
