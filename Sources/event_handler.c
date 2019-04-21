/*
 * event_handler.c
 *
 *  Created on: 19/04/2019
 *      Author: guilherme
 */

#include <comm.h>
#include <event_ring_buff.h>
#include <stdint.h>
#include <temp.h>
#include <UART0.h>
#include <UART2.h>

typedef enum
{
	BROKER,
	TERMINAL
} EVENT_HANDLER_MESSAGE_ORIGIN;

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

void event_handler(EVENT_RING_BUFF_TYPE event)
{
	while(comm_status() != AVAILABLE);

	switch(event)
	{
	case NEW_MESSAGE_FROM_BROKER:
	{
		event_handler_read_message(BROKER);
		comm_process_msg();

		break;
	}
	case NEW_MESSAGE_FROM_TERMINAL:
	{
		if(comm_info.state == WAITING_FOR_CMD)
		{
			event_handler_read_message(TERMINAL);
			comm_process_msg();
		}

		break;
	}
	case NEW_TEMPERATURE_MEAS:
	{
		/*
		if(temp_info.measurement_state == HAS_RAW_MEASUREMENT)
		{
			if(comm_info.state == WAITING_FOR_CMD)
			{
				temp_assemble_message();
				comm_process_msg();
			}
			temp_info.measurement_state = REQUESTING;
		}
		*/
		break;
	}
	}


}
