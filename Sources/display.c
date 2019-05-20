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

#define CURR_STATE_MENU_TIMEOUT	5
#define STANDARD_TIMEOUT 3

/*
 * 	[OK] OPTIONS_MENU_1,
	[OK] OPTIONS_MENU_2,
	[OK] CURR_STATE_MENU,
	[OK] DIRECTION_MENU,
	[OK] DIRECTION_CONF,
	[OK] MODE_MENU,
	[OK] MODE_CONF,
	[OK] SPEED_MENU,
	[OK] SPEED_CONF,
	THRESHOLD_MENU,
	THRESHOLD_CONF
 */

static DISPLAY_FSM_STATE state;

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
		 * 1: "Options  (1/2)"
		 * 2: "--------------"
		 * 3: "4|Show state  "
		 * 4: "5|Change dir  "
		 * 5: "6|Change mode "
		 * 6: "9|More options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Options  (1/2)");
		display_write_line(2, "--------------");
		display_write_line(3, "4|Show state  ");
		display_write_line(4, "5|Change dir  ");
		display_write_line(5, "6|Change mode ");
		display_write_line(6, "9|More options");

		break;
	}
	case OPTIONS_MENU_2:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Options  (2/2)"
		 * 2: "--------------"
		 * 3: "4|Change speed"
		 * 4: "5|Change thres"
		 * 5: "              "
		 * 6: "7|Prev options"
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Options  (2/2)");
		display_write_line(2, "--------------");
		display_write_line(3, "4|Change speed");
		display_write_line(4, "5|Change thres");
		display_clean_line(5);
		display_write_line(6, "7|Prev options");

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

		display_clean_line(6);

		display_set_timeout(CURR_STATE_MENU_TIMEOUT);

		state = OPTIONS_MENU_1;

		break;
	}
	case SPEED_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Choose amount "
		 * 2: "--------------"
		 * 3: "4|SPEED - 1%  "
		 * 4: "5|SPEED + 1%  "
		 * 5: "6|SPEED - 10% "
		 * 6: "8|SPEED + 10% "
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Choose amount ");
		display_write_line(2, "--------------");
		display_write_line(3, "4|SPEED - 1%  ");
		display_write_line(4, "5|SPEED + 1%  ");
		display_write_line(5, "6|SPEED - 10% ");
		display_write_line(6, "8|SPEED + 10% ");

		break;
	}
	case SPEED_CONF:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Speed changed "
		 * 2: "with success! "
		 * 3: "--------------"
		 * 4: "          100%"
		 * 5: "              "
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		char speed[SPEED_STRING_SIZE];
		char line[DISPLAY_LINE_STRING_SIZE];

		strcpy(line, "          ");
		*speed = '\0'; /*! Ensuring that the following strcat will work
		* properly */
		UTIL1_strcatNum16uFormatted(speed, DISPLAY_LINE_STRING_SIZE,
				(motor_info.current_pwm * 100) / MAXIMUM_PWM, '0', 3);
		strcat(speed, "%");
		strcat(line, speed);


		display_write_line(1, "Speed changed ");
		display_write_line(2, "with success! ");
		display_write_line(3, "--------------");
		display_write_line(4, line);
		display_clean_line(5);
		display_clean_line(6);

		display_set_timeout(STANDARD_TIMEOUT);

		break;
	}
	case DIRECTION_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Choose dir    "
		 * 2: "--------------"
		 * 3: "5|CLOCKWISE   "
		 * 4: "8|COUNTERCLOCK"
		 * 5: "              "
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Choose dir    ");
		display_write_line(2, "--------------");
		display_write_line(3, "5|CLOCKWISE   ");
		display_write_line(4, "8|COUNTERCLOCK");
		display_clean_line(5);
		display_clean_line(6);

		break;
	}
	case DIRECTION_CONF:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Direction     "
		 * 2: "changed with  "
		 * 3: "success!      "
		 * 4: "--------------"
		 * 5: "     CLOCKWISE"
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Direction     ");
		display_write_line(2, "changed with  ");
		display_write_line(3, "success!      ");
		display_write_line(4, "--------------");
		if(motor_info.current_dir == CLOCKWISE)
			display_write_line(5, "     CLOCKWISE");
		else
			display_write_line(5, "  COUNTERCLOCK");
		display_clean_line(6);

		display_set_timeout(STANDARD_TIMEOUT);

		break;
	}
	case MODE_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Choose mode   "
		 * 2: "--------------"
		 * 3: "5|ON          "
		 * 4: "8|OFF         "
		 * 5: "0|AUTO        "
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Choose mode   ");
		display_write_line(2, "--------------");
		display_write_line(3, "5|ON          ");
		display_write_line(4, "8|OFF         ");
		display_write_line(5, "0|AUTO        ");
		display_clean_line(6);

		break;
	}
	case MODE_CONF:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Mode changed  "
		 * 2: "with success! "
		 * 3: "--------------"
		 * 4: "            ON"
		 * 5: "              "
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Mode changed  ");
		display_write_line(2, "with success! ");
		display_write_line(3, "--------------");
		if(motor_info.current_mode == ON)
			display_write_line(4, "            ON");
		else if(motor_info.current_mode == OFF)
			display_write_line(4, "           OFF");
		else
			display_write_line(4, "          AUTO");
		display_clean_line(5);
		display_clean_line(6);

		display_set_timeout(STANDARD_TIMEOUT);

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
	switch(state)
	{
	case OPTIONS_MENU_1:
	{
		if(last_key_pressed == KEY_4)
			state = CURR_STATE_MENU;
		else if(last_key_pressed == KEY_5)
			state = DIRECTION_MENU;
		else if(last_key_pressed == KEY_6)
			state = MODE_MENU;
		else if(last_key_pressed == KEY_9)
			state = OPTIONS_MENU_2;

		break;
	}
	case OPTIONS_MENU_2:
	{
		if(last_key_pressed == KEY_4)
			state = SPEED_MENU;
		else if(last_key_pressed == KEY_5)
			state = THRESHOLD_MENU;
		else if(last_key_pressed == KEY_7)
			state = OPTIONS_MENU_1;

		break;
	}
	case SPEED_MENU:
	{
		state = SPEED_CONF;

		if(last_key_pressed == KEY_4)
			motor_change_speed(-1);
		else if(last_key_pressed == KEY_5)
			motor_change_speed(1);
		else if(last_key_pressed == KEY_6)
			motor_change_speed(-10);
		else if(last_key_pressed == KEY_8)
			motor_change_speed(10);
		else
			state = SPEED_MENU;

		break;

	}
	case DIRECTION_MENU:
	{
		state = DIRECTION_CONF;

		if(last_key_pressed == KEY_5)
			motor_set_dir(CLOCKWISE);
		else if(last_key_pressed == KEY_8)
			motor_set_dir(ANTICLOCKWISE);
		else
			state = DIRECTION_MENU;

		break;
	}
	case MODE_MENU:
	{
		state = MODE_CONF;

		if(last_key_pressed == KEY_5)
			motor_set_mode(ON);
		else if(last_key_pressed == KEY_8)
			motor_set_mode(OFF);
		else if(last_key_pressed == KEY_0)
			motor_set_mode(AUTO);
		else
			state = MODE_MENU;

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
