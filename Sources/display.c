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
#include <kboard.h>
#include <motor.h>
#include <NOKIA5110_CONTROLLER.h>
#include <NOKIA5110_LIGHT.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SPEED_STRING_SIZE	8

#define CURR_STATE_MENU_TIMEOUT	3
#define SPEED_SETUP_MENU_TIMEOUT	1

/*!
 	[OK] OPTIONS_MENU_1,
	[OK] OPTIONS_MENU_2,
	[OK] OPTIONS_MENU_3,
	TODO: THRESHOLD_MENU,
	[OK] CURR_STATE_MENU,
	[OK] SPEED_DEC_1_MENU,
	TODO: DIRECTION_MENU,
	[OK] SPEED_INC_1_MENU,
	[OK] SPEED_DEC_10_MENU,
	TODO: MODE_MENU,
	[OK] SPEED_INC_10_MENU
*/

static uint8_t last_pwm = 0;

void display_set_timeout(uint8_t timeout);

/*! @brief A function that performs the display's initialization
 * routine
 */
void display_init()
{
	NOKIA5110_CONTROLLER_Init();
	NOKIA5110_LIGHT_ClrVal();

	display_timeout.triggered = FALSE;
	display_timeout.timer = 0;
	display_timeout.target = 0;
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

void display_update(DISPLAY_FSM_STATE state)
{
	/*! TODO: Remember to ensure that you're overwriting all lines */

	switch(state)
	{
	case OPTIONS_MENU_1:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Options    1/3"
		 * 3: "2 Curr. state "
		 * 2: "4 Speed -1%   "
		 * 4: "6 Speed +1%   "
		 * 5: "3 More options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Options    1/3");
		display_write_line(2, "2 Curr. state ");
		display_write_line(3, "4 Speed -1%   ");
		display_write_line(4, "6 Speed +1%   ");
		display_write_line(5, "3 More options");

		break;
	}
	case OPTIONS_MENU_2:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "           2/3"
		 * 3: "7 Speed -10%  "
		 * 2: "9 Speed +10%  "
		 * 4: "1 Back to prev"
		 * 5: "3 More options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "           2/3");
		display_write_line(2, "7 Speed -10%  ");
		display_write_line(3, "9 Speed +10%  ");
		display_write_line(4, "1 Back to prev");
		display_write_line(5, "3 More options");

		break;
	}
	case OPTIONS_MENU_3:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "           3/3"
		 * 3: "5 Choose dir. "
		 * 2: "8 Choose mode "
		 * 4: "1 Back to prev"
		 * 5: "End of options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "           3/3");
		display_write_line(2, "5 Choose dir. ");
		display_write_line(3, "8 Choose mode ");
		display_write_line(4, "1 Back to prev");
		display_write_line(5, "End of options");

		break;
	}
	case CURR_STATE_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Current state:"
		 * 2: "              "
		 * 3: "Speed:    100%"
		 * 4: "Direction:  CW"
		 * 5: "Mode:       ON"
		 * 	  """"""""""""""""
		 */

		char speed[SPEED_STRING_SIZE];
		char line[DISPLAY_LINE_STRING_SIZE];

		/*! 1st line */
		display_write_line(1, "Current state:");

		/*! 2nd line */
		display_write_line(2, "              ");

		/*! 3rd line */
		strcpy(line, "Speed:    ");
		sprintf(speed, "%d", (motor_info.current_pwm * 100) /
				MAXIMUM_PWM);
		strcat(speed, "%");
		strcpy(line, speed);
		display_write_line(3, line);

		/*! 4th line */
		if(motor_info.current_dir == CLOCKWISE)
			display_write_line(4, "Direction:  CW");
		else
			display_write_line(4, "Direction: CCW");

		/*! 5th line */
		if(motor_info.current_mode == AUTO)
			display_write_line(5, "Mode:     AUTO");
		else if(motor_info.current_mode == ON)
			display_write_line(5, "Mode:       ON");
		else
			display_write_line(5, "Mode:      OFF");

		display_set_timeout(CURR_STATE_MENU_TIMEOUT);
	}
	case SPEED_DEC_1_MENU:
	case SPEED_INC_1_MENU:
	case SPEED_DEC_10_MENU:
	case SPEED_INC_10_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Speed changed "
		 * 2: "successfully! "
		 * 3: "              "
		 * 4: " 100% -> 100% "
		 * 5: "              "
		 * 	  """"""""""""""""
		 */

		char last_speed[SPEED_STRING_SIZE];
		char speed[SPEED_STRING_SIZE];
		char line[DISPLAY_LINE_STRING_SIZE];

		/*! 1st line */
		display_write_line(1, "Speed changed ");

		/*! 2nd line */
		display_write_line(2, "successfully! ");

		/*! 3rd line */
		display_clean_line(3);

		/*! 4th line */
		sprintf(last_speed, "%d", (last_pwm * 100) / MAXIMUM_PWM);
		strcat(last_speed, "%");

		sprintf(speed, "%d", (motor_info.current_pwm * 100) /
				MAXIMUM_PWM);
		strcat(speed, "%");

		strcpy(line, " ");
		strcat(line, last_speed);
		strcat(line, " -> ");
		strcat(line, speed);
		strcat(line, "  ");

		display_write_line(4, line);

		/*! 5th line */
		display_clean_line(5);

		display_set_timeout(SPEED_SETUP_MENU_TIMEOUT);
	}
	}
}

void display_fsm(KBOARD_KEY_TYPE last_key_pressed)
{
	static DISPLAY_FSM_STATE state;

	last_pwm = motor_info.current_pwm;

	switch(state)
	{
	case OPTIONS_MENU_1:
	case OPTIONS_MENU_2:
	case OPTIONS_MENU_3:
	{
		switch(last_key_pressed)
		{
		case KEY_1:
		{
			if(state == OPTIONS_MENU_2)
				state = OPTIONS_MENU_1;
			else if(state == OPTIONS_MENU_3)
				state = OPTIONS_MENU_2;
			break;
		}
		case KEY_2:
		{
			state = CURR_STATE_MENU;
			break;
		}
		case KEY_3:
		{
			if(state == OPTIONS_MENU_1)
				state = OPTIONS_MENU_2;
			else if(state == OPTIONS_MENU_2)
				state = OPTIONS_MENU_3;
			break;
		}
		case KEY_4:
		{
			state = SPEED_DEC_1_MENU;
			break;
		}
		case KEY_5:
		{
			break;
		}
		case KEY_6:
		{
			state = SPEED_INC_1_MENU;
			break;
		}
		case KEY_7:
		{
			state = SPEED_DEC_10_MENU;
			break;
		}
		case KEY_8:
		{
			break;
		}
		case KEY_9:
		{
			state = SPEED_INC_10_MENU;
			break;
		}
		}

		break;
	}
	case CURR_STATE_MENU:
	{
		/*! It doesn't matter what the uses presses here, he/she has to
		 * wait the timeout */
		break;
	}
	case SPEED_DEC_1_MENU:
	{
		motor_change_speed(-1);
		break;
	}
	case SPEED_INC_1_MENU:
	{
		motor_change_speed(1);
		break;
	}
	case SPEED_DEC_10_MENU:
	{
		motor_change_speed(-10);
		break;
	}
	case SPEED_INC_10_MENU:
	{
		motor_change_speed(10);
		break;
	}
	}

	display_update(state);
}

void display_set_timeout(uint8_t timeout)
{
	display_timeout.timer = 0;
	display_timeout.target = timeout;
	display_timeout.triggered = ON;
}

void display_unset_timeout()
{
	display_timeout.timer = 0;
	display_timeout.target = 0;
	display_timeout.triggered = OFF;
}
