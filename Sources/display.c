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
#include <motor.h>
#include <NOKIA5110_CONTROLLER.h>
#include <NOKIA5110_LIGHT.h>
#include <stdint.h>
#include <string.h>
#include <UTIL1.h>

#define SPEED_STRING_SIZE	8

#define CURR_STATE_MENU_TIMEOUT	3
#define SPEED_SETUP_MENU_TIMEOUT	3

/*!
 	[OK] OPTIONS_MENU_1,
	[OK] OPTIONS_MENU_2,
	[OK] OPTIONS_MENU_3,
	[OK] OPTIONS_MENU_4,
	TODO: THRESHOLD_MENU,
	[OK] CURR_STATE_MENU,
	[OK] SPEED_DEC_1_MENU,
	TODO: DIRECTION_MENU,
	[OK] SPEED_INC_1_MENU,
	[OK] SPEED_DEC_10_MENU,
	TODO: MODE_MENU,
	[OK] SPEED_INC_10_MENU
*/

static DISPLAY_FSM_STATE state;
static uint8_t last_pwm = 0;

void display_set_timeout(uint8_t timeout);

/*! @brief A function that performs the display's initialization
 * routine
 */
void display_init()
{
	NOKIA5110_CONTROLLER_Init();
	NOKIA5110_LIGHT_ClrVal();

	display_unset_timeout();
	display_fsm_force_state_change(OPTIONS_MENU_1);
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

void display_update()
{
	/*! TODO: Remember to ensure that you're overwriting all lines */

	switch(state)
	{
	case OPTIONS_MENU_1:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Options  (1/4)"
		 * 2: "--------------"
		 * 3: "0|Set thresh  "
		 * 4: "2|Show state  "
		 * 5: "              "
		 * 6: "3|More options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Options  (1/4)");
		display_write_line(2, "--------------");
		display_write_line(3, "0|Set thresh  ");
		display_write_line(4, "2|Show state  ");
		display_write_line(5, "              ");
		display_write_line(6, "3|More options");

		break;
	}
	case OPTIONS_MENU_2:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Options  (2/4)"
		 * 2: "--------------"
		 * 3: "4|Speed -1%   "
		 * 4: "6|Speed +1%   "
		 * 5: "1|Prev options"
		 * 6: "3|More options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Options  (2/4)");
		display_write_line(2, "--------------");
		display_write_line(3, "4|Speed -1%   ");
		display_write_line(4, "6|Speed +1%   ");
		display_write_line(5, "1|Prev options");
		display_write_line(6, "3|More options");

		break;
	}
	case OPTIONS_MENU_3:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Options  (3/4)"
		 * 2: "--------------"
		 * 3: "7|Speed -10%  "
		 * 4: "9|Speed +10%  "
		 * 5: "1|Prev options"
		 * 6: "3|More options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Options  (3/4)");
		display_write_line(2, "--------------");
		display_write_line(3, "7|Speed -10%  ");
		display_write_line(4, "9|Speed +10%  ");
		display_write_line(5, "1|Prev options");
		display_write_line(6, "3|More options");

		break;
	}
	case OPTIONS_MENU_4:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Options  (4/4)"
		 * 2: "--------------"
		 * 3: "5|Choose dir  "
		 * 4: "8|Choose mode "
		 * 5: "              "
		 * 6: "1|Prev options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Options  (4/4)");
		display_write_line(2, "--------------");
		display_write_line(3, "5|Choose dir  ");
		display_write_line(4, "8|Choose mode ");
		display_write_line(5, "              ");
		display_write_line(6, "1|Prev options");

		break;
	}
	case CURR_STATE_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Current state "
		 * 2: "--------------"
		 * 3: "Speed    |100%"
		 * 4: "Direction|  CW"
		 * 5: "Mode     |  ON"
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		char speed[SPEED_STRING_SIZE];
		char line[DISPLAY_LINE_STRING_SIZE];

		/*! 1st line */
		display_write_line(1, "Current state:");

		/*! 2nd line */
		display_write_line(2, "--------------");

		/*! 3rd line */
		strcpy(line, "Speed    |");

		*speed = '\0'; /*! Ensuring that the following strcat will work
		* properly */
		UTIL1_strcatNum16uFormatted(speed, DISPLAY_LINE_STRING_SIZE,
				(motor_info.current_pwm * 100) / MAXIMUM_PWM, '0', 3);
		strcat(speed, "%");

		strcat(line, speed);
		display_write_line(3, line);

		/*! 4th line */
		if(motor_info.current_dir == CLOCKWISE)
			display_write_line(4, "Direction|  CW");
		else
			display_write_line(4, "Direction| CCW");

		/*! 5th line */
		if(motor_info.current_mode == AUTO)
			display_write_line(5, "Mode     |AUTO");
		else if(motor_info.current_mode == ON)
			display_write_line(5, "Mode     |  ON");
		else
			display_write_line(5, "Mode     | OFF");

		display_write_line(6, "              ");

		display_set_timeout(CURR_STATE_MENU_TIMEOUT);

		state = OPTIONS_MENU_1;

		break;
	}
	case SPEED_DEC_1_MENU:
	case SPEED_INC_1_MENU:
	case SPEED_DEC_10_MENU:
	case SPEED_INC_10_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Speed changed!"
		 * 2: "--------------"
		 * 3: "From|     100%"
		 * 4: "To  |     100%"
		 * 5: "              "
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		char last_speed[SPEED_STRING_SIZE];
		char speed[SPEED_STRING_SIZE];
		char line[DISPLAY_LINE_STRING_SIZE];

		/*! 1st line */
		display_write_line(1, "Speed changed!");

		/*! 2nd line */
		display_write_line(2, "--------------");

		/*! 3rd line */
		*last_speed = '\0'; /*! Ensuring that the following strcat will
		* work properly */
		UTIL1_strcatNum16uFormatted(last_speed, DISPLAY_LINE_STRING_SIZE,
				(last_pwm * 100) / MAXIMUM_PWM, '0', 3);
		strcat(last_speed, "%");

		strcpy(line, "From|     ");
		strcat(line, last_speed);
		display_write_line(3, line);

		/*! 4th line */
		*speed = '\0'; /*! Ensuring that the following strcat will work
		* properly */
		UTIL1_strcatNum16uFormatted(speed, DISPLAY_LINE_STRING_SIZE,
				(motor_info.current_pwm * 100) / MAXIMUM_PWM, '0', 3);
		strcat(speed, "%");

		strcpy(line, "To  |     ");
		strcat(line, speed);

		display_write_line(4, line);

		/*! 5th line */
		display_clean_line(5);

		/*! 6th line */
		display_clean_line(6);

		display_set_timeout(SPEED_SETUP_MENU_TIMEOUT);

		state = OPTIONS_MENU_1;

		break;
	}
	}
}

void display_fsm_force_state_change(DISPLAY_FSM_STATE new_state)
{
	state = new_state;
	display_update();
}

void display_fsm(KBOARD_KEY_TYPE last_key_pressed)
{
	last_pwm = motor_info.current_pwm;

	switch(state)
	{
	case OPTIONS_MENU_1:
	{
		switch(last_key_pressed)
		{
		case KEY_0:
		{
			state = THRESHOLD_MENU;
			break;
		}
		case KEY_2:
		{
			state = CURR_STATE_MENU;
			break;
		}
		case KEY_3:
		{
			state = OPTIONS_MENU_2;
			break;
		}
		}

		break;
	}
	case OPTIONS_MENU_2:
	{
		switch(last_key_pressed)
		{
		case KEY_1:
		{
			state = OPTIONS_MENU_1;
			break;
		}
		case KEY_3:
		{
			state = OPTIONS_MENU_3;
			break;
		}
		case KEY_4:
		{
			motor_change_speed(-1);
			state = SPEED_DEC_1_MENU;
			break;
		}
		case KEY_6:
		{
			motor_change_speed(1);
			state = SPEED_INC_1_MENU;
			break;
		}
		}

		break;
	}
	case OPTIONS_MENU_3:
	{
		switch(last_key_pressed)
		{
		case KEY_1:
		{
			state = OPTIONS_MENU_2;
			break;
		}
		case KEY_3:
		{
			state = OPTIONS_MENU_4;
			break;
		}
		case KEY_7:
		{
			motor_change_speed(-10);
			state = SPEED_DEC_10_MENU;
			break;
		}
		case KEY_9:
		{
			motor_change_speed(10);
			state = SPEED_INC_10_MENU;
			break;
		}
		}

		break;
	}
	case OPTIONS_MENU_4:
	{
		switch(last_key_pressed)
		{
		case KEY_1:
		{
			state = OPTIONS_MENU_3;
			break;
		}
		case KEY_5:
		{
			state = DIRECTION_MENU;
			break;
		}
		case KEY_8:
		{
			state = MODE_MENU;
			break;
		}
		}

		break;
	}
	}

	display_update();
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
