/*
 * kboard.h
 *
 *  Created on: 11/05/2019
 *      Author: guilherme
 */

#ifndef SOURCES_KBOARD_H_
#define SOURCES_KBOARD_H_

#include <PE_Types.h>

#define KBOARD_C1_PIN	5
#define KBOARD_C2_PIN	12
#define KBOARD_C3_PIN	13
#define KBOARD_NUMBER_OF_ROWS	4
#define DEBOUNCING_DELAY	50

typedef enum
{
	RELEASED,
	PRESSED
} KBOARD_BUTTON_STATE;

void kboard_init();
void kboard_deactivate_row(uint8_t row);
void kboard_activate_rows();

#endif /* SOURCES_KBOARD_H_ */
