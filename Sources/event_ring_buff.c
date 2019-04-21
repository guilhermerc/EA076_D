/*
 * event_ring_buffer.c
 *
 *  Created on: 19/04/2019
 *      Author: guilherme
 */

#include <event_ring_buff.h>
#include <PE_Types.h>

void event_ring_buff_init()
{
	event_ring_buff_info.head_ptr = 0;
	event_ring_buff_info.tail_ptr = 0;
}

bool event_ring_buff_is_empty()
{
	bool status = event_ring_buff_info.head_ptr ==
			event_ring_buff_info.tail_ptr ? TRUE : FALSE;
	return status;
}

bool event_ring_buff_is_full()
{
	bool status = FALSE;
	/*!
	 * Tests if the next event slot isn't available
	 */
	if(((event_ring_buff_info.head_ptr + 1) % EVENT_RING_BUFF_SIZE) ==
			event_ring_buff_info.tail_ptr)
		status = TRUE;
	return status;
}

void event_ring_buff_insert_event(EVENT_RING_BUFF_TYPE type)
{
	if(!event_ring_buff_is_full())
	{
		event_ring_buff_info.head_ptr++;
		event_ring_buff_info.head_ptr %= EVENT_RING_BUFF_SIZE;
		event_ring_buff_info.ring_buff[event_ring_buff_info.head_ptr] =
				type;
	}
}

EVENT_RING_BUFF_TYPE event_ring_buff_consume_event()
{
	EVENT_RING_BUFF_TYPE event =
			event_ring_buff_info.ring_buff[event_ring_buff_info.tail_ptr];
	event_ring_buff_info.tail_ptr++;
	event_ring_buff_info.tail_ptr %= EVENT_RING_BUFF_SIZE;
	return event;
}
