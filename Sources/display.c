/*
 * display.c
 *
 *  Created on: 04/05/2019
 *      Author: guilherme
 */
/*!
 * @file display.c
 * @brief This file contains implementations related to the display.
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#include <display.h>
#include <NOKIA5110_CONTROLLER.h>
#include <stdint.h>

/*! @brief A function that performs the display's initialization
 * routine
 */
void display_init()
{
	NOKIA5110_CONTROLLER_Init();
}

/*! @brief A function that writes a single line in the display
 *
 * @param	line	Index of the line to be written
 * @param	string	String to be written
 */
void display_write_line(uint8_t line, char * string)
{
	NOKIA5110_CONTROLLER_WriteLineStr(line, string);
}

/*! @brief A function that wipes a single line in the display
 *
 * @param	line	Index of the line to be wiped
 */
void display_clean_line(uint8_t line)
{
	display_write_line(line, "                    ");
}
