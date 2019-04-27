/*
 * event_ring_buffer.c
 *
 *  Created on: 19/04/2019
 *      Author: guilherme
 */

#include <event_ring_buff.h>
#include <PE_Types.h>

typedef enum
{
	NONE,
	EMPTY,
	FULL
} EVENT_RING_BUFF_STATE_ENUM;

EVENT_RING_BUFF_STATE_ENUM state;

void event_ring_buff_init()
{
	state = EMPTY;
	event_ring_buff_info.head_ptr = 0;
	event_ring_buff_info.tail_ptr = 0;
}

bool event_ring_buff_is_empty()
{
	return (state == EMPTY) ? TRUE : FALSE;
}

bool event_ring_buff_is_full()
{
	return (state == FULL) ? TRUE : FALSE;
}

void event_ring_buff_insert_event(EVENT_RING_BUFF_TYPE type)
{
	/*!
	 * Check if state is either NONE or EMPTY
	 */
	if(!event_ring_buff_is_full())
	{
		event_ring_buff_info.ring_buff[event_ring_buff_info.head_ptr] =
				type;
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
