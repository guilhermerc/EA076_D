/*!
** @file ESP01_comm.c
** @brief
**         This file contains the FSM implementation for communicating
**         with the MQTT Broker (using the ESP-01 module).
*/

#include <ESP01_comm.h>
#include <LOG.h>
#include <string.h>
#include <UART2Events.h>

#define WIFI_SSID "\"EA076\""
#define WIFI_PASSWORD "\"FRDMKL25Z\""
#define MQTT_PORT "\"1883\""
#define MQTT_USERNAME "\"GUILHERME\""
#define MQTT_PSSWORD "\"UNICAMP\""
#define TERMINATING_CHARS "\r\n"

typedef enum COMM_STATE
{
	CONNECT_WIFI,
	GET_IP_NUMB,
	GET_MAC_ADD,
	CONNECT_MQTT,
	INDEED_COMM
} COMM_STATE_ENUM;

static COMM_STATE_ENUM comm_state = CONNECT_WIFI;

void comm_fsm_start()
{
	comm_state = CONNECT_WIFI;
	state_changed = FALSE;
	comm_fsm_send();
}

void comm_fsm_receive(UART2_TComData* message)
{
	switch(comm_state)
	{
	case CONNECT_WIFI:
	{
		if(strcmp(message, "CONNECT WIFI\r\n") == 0)
		{
			comm_state = GET_IP_NUMB;
		}
		else if(strcmp(message, "ERROR WIFI\r\n") == 0)
		{
			comm_state = CONNECT_WIFI;
		}
		else
		{
			LOG("comm_fsm_parse", message);
		}
		break;
	}
	case GET_IP_NUMB:
	case GET_MAC_ADD:
	case CONNECT_MQTT:
	case INDEED_COMM:
	{
		break;
	}
	}
	state_changed = TRUE;
}

void comm_fsm_send()
{
	UART2_TComData message[MESSAGE_BUFFER_SIZE];

	switch(comm_state)
	{
	case CONNECT_WIFI:
	{
		strcpy(message, "CONNWIFI ");
		strcat(message, WIFI_SSID);
		strcat(message, ",");
		strcat(message, WIFI_PASSWORD);
		strcat(message, TERMINATING_CHARS);
		// LOG the message into UART0: "comm_fsm_send: <message>"
		LOG("comm_fsm_send", message);
		/*
		 * Call function that sends a string via UART2
		 */
		break;
	}
	case GET_IP_NUMB:
	case GET_MAC_ADD:
	case CONNECT_MQTT:
	case INDEED_COMM:
	{
		break;
	}
	}
	state_changed = FALSE;
}
