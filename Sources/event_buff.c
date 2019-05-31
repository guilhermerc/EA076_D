/*!
 * @file event_buff.c
 * @brief This file contains implementations related to the event ring
 * buffer
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#include <comm.h>
#include <display.h>
#include <event_buff.h>
#include <memory.h>
#include <motor.h>
#include <stdlib.h>
#include <string.h>
#include <temp.h>
#include <UART0.h>
#include <UART2.h>

typedef enum
{
	NONE, //!< NONE
	EMPTY,//!< EMPTY
	FULL  //!< FULL
} EVENT_BUFF_STATE_ENUM;

EVENT_BUFF_STATE_ENUM state;

typedef enum
{
	BROKER,
	TERMINAL
} EVENT_HANDLER_MESSAGE_ORIGIN;

/*!
 * @brief A function that initializes the event ring buffer module
 */
void event_buff_init()
{
	state = EMPTY;
	event_buff_info.head_ptr = 0;
	event_buff_info.tail_ptr = 0;
}

/*!
 * @brief A function that checks if the event ring buffer is empty
 * @return	bool	TRUE: if it is empty
 * 					FALSE: if it isn't empty
 */
bool event_buff_is_empty()
{
	return (state == EMPTY) ? TRUE : FALSE;
}

/*!
 * @brief A function that checks if the event ring buffer is full
 * @return	bool	TRUE: if it is full
 * 					FALSE: if it isn't full
 */
bool event_buff_is_full()
{
	return (state == FULL) ? TRUE : FALSE;
}

/*!
 * @brief A function that inserts an event in the event ring buffer (if
 * it is not full)
 * @param	type	The event to be inserted
 */
void event_buff_insert_event(EVENT_BUFF_TYPE event)
{
	/*!
	 * Check if state is either NONE or EMPTY
	 */
	if(!event_buff_is_full())
	{
		event_buff_info.ring_buff[event_buff_info.head_ptr] =
				event;
		event_buff_info.head_ptr++;
		event_buff_info.head_ptr %= EVENT_BUFF_SIZE;

		if(event_buff_info.head_ptr ==
				event_buff_info.tail_ptr)
		{
			state = FULL;
		}

		if(state == EMPTY)
		{
			state = NONE;
		}
	}
}

/*!
 * @brief A function that consumes an event from the event ring buffer
 * @return	EVENT_BUFF_TYPE	The event itself
 */
EVENT_BUFF_TYPE event_buff_consume_event()
{
	/*!
	 * This function is only called when ring buffer is not empty.
	 * Therefore
	 * 	1 - I don't need to check it
	 * 	2 - The state is either NONE or FULL
	 */
	EVENT_BUFF_TYPE event =
			event_buff_info.ring_buff[event_buff_info.tail_ptr];
	event_buff_info.tail_ptr++;
	event_buff_info.tail_ptr %= EVENT_BUFF_SIZE;

	if(event_buff_info.head_ptr ==
			event_buff_info.tail_ptr)
	{
		state = EMPTY;
	}

	if(state == FULL)
	{
		state = NONE;
	}

	return event;
}

/*!
 * @brief A function to read a message from a determined UART
 * @param	origin	A param that indicates from which UART ring buffer
 * 					should this function read a message
 */
void event_handler_read_message(EVENT_HANDLER_MESSAGE_ORIGIN origin)
{
	uint8_t index = 0;
	comm_info.message_in[index] = '\0';

	do {
		switch(origin)
		{
		case TERMINAL:
		{
			UART0_RecvChar(&comm_info.message_in[index]);
			break;
		}
		case BROKER:
		{
			UART2_RecvChar(&comm_info.message_in[index]);
			break;
		}
		}
	} while(comm_info.message_in[index++] != '\n');
}

/*!
 * @brief A function that handles an event
 * @param	event	The event to be handled
 */
void event_handler(EVENT_BUFF_TYPE event)
{
	static bool is_dumping = FALSE;
	static uint8_t pages_to_be_dumped = 0;
	static uint8_t words_to_be_dumped = 0;
	static uint8_t words_already_dumped = 0;
	static char * buffer = NULL;

	/*! If the event is somewhat related to the communication process,
	 * waits (blocking) for the channel to be available
	 */
	if(event == NEW_MESSAGE_FROM_BROKER ||
			event == NEW_MESSAGE_FROM_TERMINAL ||
			event == NEW_TEMPERATURE_MEAS ||
			event == MEMORY_DUMP_REQUEST)
		while(comm_status() != AVAILABLE);

	if(event == DISPLAY_REFRESH)
	{
		display_update();
	}
	else if(event == MEMORY_BUFFER_FULL)
	{
		memory_write_page(memory_info.pages_written,
				memory_info.buffer);
	}
	else if(event == MEMORY_DUMP_REQUEST)
	{
		if(is_dumping == FALSE)
		{
			pages_to_be_dumped = memory_info.pages_written - memory_info.pages_dumped;
			words_to_be_dumped = pages_to_be_dumped * TEMPERATURE_SIZE_IN_WORDS;
			words_already_dumped = 0;

			if(pages_to_be_dumped > 0)
			{
				buffer = (char *) malloc((pages_to_be_dumped *
						WORDS_PER_PAGE) * sizeof(char));
				memory_dump(buffer);

				is_dumping = TRUE;
			}
		}

		if(is_dumping == TRUE)
		{
			if(comm_info.state == WAITING_FOR_CMD)
			{
				char temperature[TEMPERATURE_STRING_SIZE];

				memcpy(temperature, &(buffer[words_already_dumped *
											 TEMPERATURE_SIZE_IN_WORDS]),
						TEMPERATURE_SIZE_IN_WORDS);
				temperature[TEMPERATURE_SIZE_IN_WORDS] = '\0';

				comm_publish(LOG_TOPIC, temperature);

				if(++words_already_dumped == words_to_be_dumped)
				{
					free(buffer);
					is_dumping = FALSE;
				}
				else
					event_buff_insert_event(MEMORY_DUMP_REQUEST);
			}
			else
				event_buff_insert_event(MEMORY_DUMP_REQUEST);
		}
	}
	else if(event == LOG_TEMPERATURE_PERIOD)
	{
		memory_bufferize_temperature(temp_info.temperature_string);
	}
	else if(event == NEW_MESSAGE_FROM_BROKER)
	{
		event_handler_read_message(BROKER);
		comm_process_msg();
	}
	else if(event == NEW_MESSAGE_FROM_TERMINAL)
	{
		if(comm_info.state == WAITING_FOR_CMD)
		{
			event_handler_read_message(TERMINAL);
			comm_process_msg();
		}
	}
	else if(event == NEW_TEMPERATURE_MEAS)
	{
		if(comm_info.state == WAITING_FOR_CMD)
		{
			temp_assemble_message();
			comm_publish(TEMPERATURE_TOPIC, temp_info.message);
		}

		/*!
		 * The 'AUTO' mode and the threshold thing is checked whenever
		 * a new temperature measurement was published
		 */
		if(motor_info.current_mode == AUTO)
		{
			if(temp_info.temperature >= motor_info.threshold)
				motor_set_pwm(MAXIMUM_PWM);
			else
				motor_set_pwm(MINIMUM_PWM);
		}
	}
	else if(event == NEW_KEY_PRESSING)
	{
		display_fsm();
	}
	else if(event == TIMEOUT)
	{
		display_fsm_force_state_change(CURRENT_TIME_MENU);
	}
}
