/*
 * display.c
 *
 *  Created on: 04/05/2019
 *      Author: guilherme
 */

#include <display.h>

void display_init()
{
	NOKIA5110_CONTROLLER_Init();
}

void display_write_line(uint8_t line, char * string)
{
	NOKIA5110_CONTROLLER_WriteLineStr(line, string);
}
