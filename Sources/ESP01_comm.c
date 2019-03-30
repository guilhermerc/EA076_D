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

void comm_fsm_recv(UART2_TComData* message_in)
{
	switch(comm_state)
	{
	case CONNECT_WIFI:
	{
		LOG("comm_fsm_recv (CONNECT_WIFI)", (UART0_TComData*)message_in);

		if(strcmp(message_in, "CONNECT WIFI\r\n") == 0)
		{
			comm_state = GET_IP_NUMB;
		}
		else if(strcmp(message_in, "ERROR WIFI\r\n") == 0)
		{
			comm_state = CONNECT_WIFI;
		}
		else
		{
			//LOG("[UNEXPECTED] comm_fsm_recv (CONNECT_WIFI)", message_in);
		}

		break;
	}
	case GET_IP_NUMB:
	{
		LOG("comm_fsm_recv (GET_IP_NUMB)", message_in);
		break;
	}
	case GET_MAC_ADD:
	{
		LOG("comm_fsm_recv (GET_MAC_ADD)", message_in);
		break;
	}
	case CONNECT_MQTT:
	{
		LOG("comm_fsm_recv (CONNECT_MQTT)", message_in);
		break;
	}
	case INDEED_COMM:
	{
		LOG("comm_fsm_recv (INDEED_COMM)", message_in);
		break;
	}
	}
	state_changed = TRUE;
}

void comm_fsm_send()
{
	switch(comm_state)
	{
	case CONNECT_WIFI:
	{
		strcpy(message_out, "CONNWIFI ");
		strcat(message_out, WIFI_SSID);
		strcat(message_out, ",");
		strcat(message_out, WIFI_PASSWORD);
		strcat(message_out, TERMINATING_CHARS);

		LOG("comm_fsm_send (CONNECT_WIFI)", message_out);
		UART2_OnTxChar();

		break;
	}
	case GET_IP_NUMB:
	{
		LOG("comm_fsm_send (GET_IP_NUMB)", message_out);
		break;
	}
	case GET_MAC_ADD:
	{
		LOG("comm_fsm_send (GET_MAC_ADD)", message_out);
		break;
	}
	case CONNECT_MQTT:
	{
		LOG("comm_fsm_send (CONNECT_MQTT)", message_out);
		break;
	}
	case INDEED_COMM:
	{
		LOG("comm_fsm_send (INDEED_COMM)", message_out);
		break;
	}
	}
	state_changed = FALSE;
}
