/*
 * display.h
 *
 *  Created on: 04/05/2019
 *      Author: guilherme
 */

/*!
 * @file display.h
 * @brief This file exports what is necessary from display.c
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#ifndef SOURCES_DISPLAY_H_
#define SOURCES_DISPLAY_H_

#include <kboard.h>
#include <PE_Types.h>

/*! TODO: Check the width of the display */
#define DISPLAY_LINE_STRING_SIZE	20

typedef enum
{
	OPTIONS_MENU_1,
	OPTIONS_MENU_2,
	OPTIONS_MENU_3,
	THRESHOLD_MENU,
	CURR_STATE_MENU,
	SPEED_DEC_1_MENU,
	DIRECTION_MENU,
	SPEED_INC_1_MENU,
	SPEED_DEC_10_MENU,
	MODE_MENU,
	SPEED_INC_10_MENU
} DISPLAY_FSM_STATE;

typedef struct
{
	bool triggered;
	uint8_t timer;
	uint8_t target;
} DISPLAY_TIMEOUT;

DISPLAY_TIMEOUT display_timeout;

void display_init();
void display_write_line(uint8_t line, char * string);
void display_clean_line(uint8_t line);
void display_fsm(KBOARD_KEY_TYPE last_key_pressed);
void display_update(DISPLAY_FSM_STATE state);
void display_unset_timeout();

#endif /* SOURCES_DISPLAY_H_ */
