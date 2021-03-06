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

#define DISPLAY_LINE_STRING_SIZE	20

typedef enum
{
	CURRENT_TIME_MENU,
	OPTIONS_MENU_1,
	OPTIONS_MENU_2,
	CURR_STATE_MENU,
	DIRECTION_MENU,
	DIRECTION_CONF,
	MODE_MENU,
	MODE_CONF,
	SPEED_MENU,
	SPEED_CONF,
	THRESHOLD_MENU,
	THRESHOLD_CONF
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
void display_update();
DISPLAY_FSM_STATE display_get_state();
void display_fsm();
void display_fsm_force_state_change(DISPLAY_FSM_STATE new_state);
void display_unset_timeout();

#endif /* SOURCES_DISPLAY_H_ */
