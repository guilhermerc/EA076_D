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
#include <rtc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <UTIL1.h>

#define SPEED_STRING_SIZE	8
#define THRESHOLD_STRING_SIZE	16

#define CURR_STATE_MENU_TIMEOUT	5
#define STANDARD_TIMEOUT 3

static DISPLAY_FSM_STATE state;

static char threshold[THRESHOLD_STRING_SIZE];
static bool typing_threshold = FALSE;

static LDD_RTC_TTime current_time;

void display_set_timeout(uint8_t timeout);

/*! @brief A function that performs the display's initialization
 * routine
 */
void display_init()
{
	NOKIA5110_CONTROLLER_Init();
	NOKIA5110_LIGHT_ClrVal();

	display_unset_timeout();
	display_fsm_force_state_change(CURRENT_TIME_MENU);
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

/*! @brief A function that updates what is currently being displayed
 *
 * This function takes no arguments but it depends hardly on the
 * current state of the display FSM (which is a "globally static"
 * variable).
 *
 * */
void display_update()
{
	switch(state)
	{
	case CURRENT_TIME_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Hi            "
		 * 2: "--------------"
		 * 3: "    MM/DD/YYYY"
		 * 4: "      HH:MM:SS"
		 * 5: "              "
		 * 6: "9|Options list"
		 * 	  """"""""""""""""
		 */

		char line_string[DISPLAY_LINE_STRING_SIZE];

		rtc_get_time(&current_time);

		display_write_line(1, "Hi            ");
		display_write_line(2, "--------------");

		/*! Assembles the string "    MM/DD/YYYY" */
		UTIL1_strcpy(line_string, DISPLAY_LINE_STRING_SIZE, "    ");
		UTIL1_strcatNum32uFormatted(line_string,
				DISPLAY_LINE_STRING_SIZE, current_time.Month, '0', 2);
		UTIL1_strcat(line_string, DISPLAY_LINE_STRING_SIZE, "/");
		UTIL1_strcatNum32uFormatted(line_string,
				DISPLAY_LINE_STRING_SIZE, current_time.Day, '0', 2);
		UTIL1_strcat(line_string, DISPLAY_LINE_STRING_SIZE, "/");
		UTIL1_strcatNum32uFormatted(line_string,
				DISPLAY_LINE_STRING_SIZE, current_time.Year, '0', 4);

		display_write_line(3, "    MM/DD/YYYY");

		/*! Assembles the string "      HH:MM:SS" */
		UTIL1_strcpy(line_string, DISPLAY_LINE_STRING_SIZE, "      ");
		UTIL1_strcatNum32uFormatted(line_string,
				DISPLAY_LINE_STRING_SIZE, current_time.Hour, '0', 2);
		UTIL1_strcat(line_string, DISPLAY_LINE_STRING_SIZE, ":");
		UTIL1_strcatNum32uFormatted(line_string,
				DISPLAY_LINE_STRING_SIZE, current_time.Minute, '0', 2);
		UTIL1_strcat(line_string, DISPLAY_LINE_STRING_SIZE, ":");
		UTIL1_strcatNum32uFormatted(line_string,
				DISPLAY_LINE_STRING_SIZE, current_time.Second, '0', 2);

		display_write_line(4, "      HH:MM:SS");

		display_write_line(5, "              ");
		display_write_line(6, "9|Options list");

		break;
	}
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
		 * 6: "Threshold|20.0"
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

		/*! 6th line */
		strcpy(line, "Threshold|");
		sprintf(threshold, "%.1f", motor_info.threshold);
		strcat(line, threshold);
		display_write_line(6, line);

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
		 * 3: "4|ON          "
		 * 4: "5|OFF         "
		 * 5: "6|AUTO        "
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		display_write_line(1, "Choose mode   ");
		display_write_line(2, "--------------");
		display_write_line(3, "4|ON          ");
		display_write_line(4, "5|OFF         ");
		display_write_line(5, "6|AUTO        ");
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
	case THRESHOLD_MENU:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Type the new  "
		 * 2: "threshold and "
		 * 3: "press '#'     "
		 * 4: "--------------"
		 * 5: "              "
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		char line[DISPLAY_LINE_STRING_SIZE];

		display_write_line(1, "Type the new  ");
		display_write_line(2, "threshold and ");
		display_write_line(3, "press '#'     ");
		display_write_line(4, "--------------");

		if(typing_threshold == TRUE)
			display_write_line(5, threshold);
		else
			display_clean_line(5);

		display_clean_line(6);

		break;
	}
	case THRESHOLD_CONF:
	{
		/*!
		 * 	  """"""""""""""""
		 * 1: "Threshold     "
		 * 2: "changed with  "
		 * 3: "success!      "
		 * 4: "--------------"
		 * 5: "        20.0 C"
		 * 6: "              "
		 * 	  """"""""""""""""
		 */

		char line[DISPLAY_LINE_STRING_SIZE];

		display_write_line(1, "Threshold     ");
		display_write_line(2, "changed with  ");
		display_write_line(3, "success!      ");
		display_write_line(4, "--------------");

		strcpy(line, "          ");
		sprintf(threshold, "%.1f", motor_info.threshold);
		strcat(line, threshold);
		strcat(line, " C");

		display_write_line(5, line);

		display_clean_line(6);

		display_set_timeout(STANDARD_TIMEOUT);

		break;
	}
	}
}

/*! @brief A function that forcibly changes the current state of
 * display FSM
 *
 * This function currently is used by timeout purposes.
 *
 */
void display_fsm_force_state_change(DISPLAY_FSM_STATE new_state)
{
	state = new_state;
	display_update();
}

/*! @brief A function that iterates over a FSM, which controls the
 * display menus and motor configurations
 *
 * The states are:
 *
 *  CURRENT_TIME_MENU	->	Home "page"
 * 	OPTIONS_MENU_1		->	First "page" of options
 *	OPTIONS_MENU_2		-> 	Last "page" of options
 *	CURR_STATE_MENU		-> 	Displays for CURR_STATE_MENU_TIMEOUT
 *							seconds the motor current configs
 *	DIRECTION_MENU		->	Enables the user to change motor direction
 *	DIRECTION_CONF		->	Confirms the change in motor direction
 *	MODE_MENU			->	Enables the user to change motor mode
 *	MODE_CONF			->	Confirms the change in motor mode
 *	SPEED_MENU			->	Enables the user to change motor speed
 *	SPEED_CONF			->	Confirms the change in motor speed
 *	THRESHOLD_MENU		->	Enables the user to change motor threshold
 *	THRESHOLD_CONF		->	Enables the user to change motor threshold
 *
 *	NOTE: I'm not using the proposed FSM. I find this design more
 *	intuitive.
 */
void display_fsm()
{
	switch(state)
	{
	case CURRENT_TIME_MENU:
	{
		if(kboard_info.last_key_pressed == KEY_9)
			state = OPTIONS_MENU_1;

		break;
	}
	case OPTIONS_MENU_1:
	{
		if(kboard_info.last_key_pressed == KEY_4)
			state = CURR_STATE_MENU;
		else if(kboard_info.last_key_pressed == KEY_5)
			state = DIRECTION_MENU;
		else if(kboard_info.last_key_pressed == KEY_6)
			state = MODE_MENU;
		else if(kboard_info.last_key_pressed == KEY_9)
			state = OPTIONS_MENU_2;

		break;
	}
	case OPTIONS_MENU_2:
	{
		if(kboard_info.last_key_pressed == KEY_4)
			state = SPEED_MENU;
		else if(kboard_info.last_key_pressed == KEY_5)
			state = THRESHOLD_MENU;
		else if(kboard_info.last_key_pressed == KEY_7)
			state = OPTIONS_MENU_1;

		break;
	}
	case SPEED_MENU:
	{
		state = SPEED_CONF;

		if(kboard_info.last_key_pressed == KEY_4)
			motor_change_speed(-1);
		else if(kboard_info.last_key_pressed == KEY_5)
			motor_change_speed(1);
		else if(kboard_info.last_key_pressed == KEY_6)
			motor_change_speed(-10);
		else if(kboard_info.last_key_pressed == KEY_8)
			motor_change_speed(10);
		else
			state = SPEED_MENU;

		break;
	}
	case DIRECTION_MENU:
	{
		state = DIRECTION_CONF;

		if(kboard_info.last_key_pressed == KEY_5)
			motor_set_dir(CLOCKWISE);
		else if(kboard_info.last_key_pressed == KEY_8)
			motor_set_dir(COUNTERCLOCKWISE);
		else
			state = DIRECTION_MENU;

		break;
	}
	case MODE_MENU:
	{
		state = MODE_CONF;

		if(kboard_info.last_key_pressed == KEY_4)
			motor_set_mode(ON);
		else if(kboard_info.last_key_pressed == KEY_5)
			motor_set_mode(OFF);
		else if(kboard_info.last_key_pressed == KEY_6)
			motor_set_mode(AUTO);
		else
			state = MODE_MENU;

		break;
	}
	case THRESHOLD_MENU:
	{
		if(typing_threshold == FALSE)
		{
			*threshold = '\0';
			typing_threshold = TRUE;
		}

		char curr_char = '\0';

		if(kboard_info.last_key_pressed == KEY_0)
			curr_char = '0';
		else if(kboard_info.last_key_pressed == KEY_1)
			curr_char = '1';
		else if(kboard_info.last_key_pressed == KEY_2)
			curr_char = '2';
		else if(kboard_info.last_key_pressed == KEY_3)
			curr_char = '3';
		else if(kboard_info.last_key_pressed == KEY_4)
			curr_char = '4';
		else if(kboard_info.last_key_pressed == KEY_5)
			curr_char = '5';
		else if(kboard_info.last_key_pressed == KEY_6)
			curr_char = '6';
		else if(kboard_info.last_key_pressed == KEY_7)
			curr_char = '7';
		else if(kboard_info.last_key_pressed == KEY_8)
			curr_char = '8';
		else if(kboard_info.last_key_pressed == KEY_9)
			curr_char = '9';
		else if(kboard_info.last_key_pressed == KEY_ASTERISK)
			curr_char = '.';
		else if(kboard_info.last_key_pressed  == KEY_HASHTAG)
			curr_char = '#';

		if(curr_char == '#')
		{
			motor_set_threshold(atof(threshold));
			typing_threshold = FALSE;

			state = THRESHOLD_CONF;
		}
		else
			UTIL1_chcat(threshold, THRESHOLD_STRING_SIZE, curr_char);

		break;
	}
	}

	display_update();
}

/*! @brief A function that sets a timeout of 'timeout' seconds
 *
 * @param	timeout	The timeout in seconds
 */
void display_set_timeout(uint8_t timeout)
{
	display_timeout.timer = 0;
	display_timeout.target = timeout;
	display_timeout.triggered = ON;
}

/*! @brief	A function that unsets the current configuration of timeout */
void display_unset_timeout()
{
	display_timeout.timer = 0;
	display_timeout.target = 0;
	display_timeout.triggered = OFF;
}
