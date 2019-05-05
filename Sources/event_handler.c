/*!
 * @file event_handler.c
 * @brief This file contains the handler of all events that can be
 * inserted in the event ring buffer
 *
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#include <comm.h>
#include <event_ring_buff.h>
#include <motor.h>
#include <stdint.h>
#include <temp.h>
#include <UART0.h>
#include <UART2.h>

typedef enum
{
	BROKER,
	TERMINAL
} EVENT_HANDLER_MESSAGE_ORIGIN;

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
			{
				motor_set_pwm(MAXIMUM_PWM);
			}
			else
			{
				motor_set_pwm(MINIMUM_PWM);
			}

		break;
	}
	}
	}
}
