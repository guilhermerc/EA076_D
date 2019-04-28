/*
 * event_ring_buffer.h
 *
 *  Created on: 19/04/2019
 *      Author: guilherme
 */

/*!
 * @file event_ring_buff.h
 * @brief This file exports what is necessary from event_ring_buff.c
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#ifndef SOURCES_EVENT_RING_BUFF_H_
#define SOURCES_EVENT_RING_BUFF_H_

#include <PE_Types.h>

#define EVENT_RING_BUFF_SIZE	32

typedef enum
{
	NEW_MESSAGE_FROM_BROKER,  //!< NEW_MESSAGE_FROM_BROKER
	NEW_MESSAGE_FROM_TERMINAL,//!< NEW_MESSAGE_FROM_TERMINAL
	NEW_TEMPERATURE_MEAS,     //!< NEW_TEMPERATURE_MEAS
} EVENT_RING_BUFF_TYPE;

typedef struct
{
	EVENT_RING_BUFF_TYPE ring_buff[EVENT_RING_BUFF_SIZE];
	/*!
	 * The 'head pointer' will point to the next possibly available
	 * slot, while the 'tail_pointer' will point to next event to be
	 * consumed
	 */
	uint8_t head_ptr;
	uint8_t tail_ptr;
} EVENT_RING_BUFF_INFO;

EVENT_RING_BUFF_INFO event_ring_buff_info;

void event_ring_buff_init();
bool event_ring_buff_is_empty();
bool event_ring_buff_is_full();
void event_ring_buff_insert_event(EVENT_RING_BUFF_TYPE type);
EVENT_RING_BUFF_TYPE event_ring_buff_consume_event();

#endif /* SOURCES_EVENT_RING_BUFFER_H_ */
