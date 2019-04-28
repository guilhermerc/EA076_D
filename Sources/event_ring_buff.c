/*
 * event_ring_buffer.c
 *
 *  Created on: 19/04/2019
 *      Author: guilherme
 */

/*!
 * @file event_ring_buff.c
 * @brief This file contains implementations related to the event ring
 * buffer
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */
#include <event_ring_buff.h>
#include <PE_Types.h>

typedef enum
{
	NONE, //!< NONE
	EMPTY,//!< EMPTY
	FULL  //!< FULL
} EVENT_RING_BUFF_STATE_ENUM;

EVENT_RING_BUFF_STATE_ENUM state;

/*!
 * @brief A function that initializes the event ring buffer module
 */
void event_ring_buff_init()
{
	state = EMPTY;
	event_ring_buff_info.head_ptr = 0;
	event_ring_buff_info.tail_ptr = 0;
}

/*!
 * @brief A function that checks if the event ring buffer is empty
 * @return	bool	TRUE: if it is empty
 * 					FALSE: if it isn't empty
 */
bool event_ring_buff_is_empty()
{
	return (state == EMPTY) ? TRUE : FALSE;
}

/*!
 * @brief A function that checks if the event ring buffer is full
 * @return	bool	TRUE: if it is full
 * 					FALSE: if it isn't full
 */
bool event_ring_buff_is_full()
{
	return (state == FULL) ? TRUE : FALSE;
}

/*!
 * @brief A function that inserts an event in the event ring buffer (if
 * it is not full)
 * @param	type	The event to be inserted
 */
void event_ring_buff_insert_event(EVENT_RING_BUFF_TYPE event)
{
	/*!
	 * Check if state is either NONE or EMPTY
	 */
	if(!event_ring_buff_is_full())
	{
		event_ring_buff_info.ring_buff[event_ring_buff_info.head_ptr] =
				event;
		event_ring_buff_info.head_ptr++;
		event_ring_buff_info.head_ptr %= EVENT_RING_BUFF_SIZE;

		if(event_ring_buff_info.head_ptr ==
				event_ring_buff_info.tail_ptr)
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
 * @return	EVENT_RING_BUFF_TYPE	The event itself
 */
EVENT_RING_BUFF_TYPE event_ring_buff_consume_event()
{
	/*!
	 * This function is only called when ring buffer is not empty.
	 * Therefore
	 * 	1 - I don't need to check it
	 * 	2 - The state is either NONE or FULL
	 */
		EVENT_RING_BUFF_TYPE event =
				event_ring_buff_info.ring_buff[event_ring_buff_info.tail_ptr];
		event_ring_buff_info.tail_ptr++;
		event_ring_buff_info.tail_ptr %= EVENT_RING_BUFF_SIZE;

		if(event_ring_buff_info.head_ptr ==
				event_ring_buff_info.tail_ptr)
		{
			state = EMPTY;
		}

		if(state == FULL)
		{
			state = NONE;
		}

	return event;
}
