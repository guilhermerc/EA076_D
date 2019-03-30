/*!
** @file ESP01_comm.c
** @brief
**         This file contains the FSM implementation for communicating
**         with the MQTT Broker (using the ESP-01 module).
*/

#include <ESP01_comm.h>
#include <LOG.h>
#include <string.h>
#include <UART0.h>
#include <UART2Events.h>

#define WIFI_SSID "\"EA076\""
#define WIFI_PASSWORD "\"FRDMKL25Z\""
#define MQTT_PORT "1883"
#define MQTT_USERNAME "\"GUILHERME\""
#define MQTT_PASSWORD "\"UNICAMP\""
#define TERMINATING_CHARS "\r\n"

#define IP_NUMBER_SIZE	32
static char ip_number[IP_NUMBER_SIZE];	// it should be const

#define MAC_ADDR_SIZE	64
static char mac_addr[MAC_ADDR_SIZE];	// it should be const

typedef enum COMM_STATE
{
	CONNECT_WIFI,
	GET_IP_NUMB,
	GET_MAC_ADDR,
	CONNECT_MQTT,
	COMM_INDEED
} COMM_STATE_ENUM;

static COMM_STATE_ENUM comm_state = CONNECT_WIFI;

void comm_fsm_start()
{
	comm_state = CONNECT_WIFI;
	state_changed = FALSE;
	comm_fsm_send();
}

void comm_send_msg()
{
	UART2_OnTxChar();
}

void comm_fsm_recv(UART2_TComData* message_in)
{
	static bool has_ip_number = FALSE;
	static bool has_mac_addr = FALSE;

	switch(comm_state)
	{
	case CONNECT_WIFI:
	{
		LOG("comm_fsm_recv (CONNECT_WIFI)", (UART0_TComData*)message_in);

		if(strcmp(message_in, "CONNECT WIFI\r\n") == 0)
		{
			if(has_ip_number != TRUE)
				comm_state = GET_IP_NUMB;
			else if(has_mac_addr != TRUE)
				comm_state = GET_MAC_ADDR;
			else
				comm_state = CONNECT_MQTT;
		}
		else if(strcmp(message_in, "ERROR WIFI\r\n") == 0)
		{
			comm_state = CONNECT_WIFI;
		}

		break;
	}
	case GET_IP_NUMB:
	{
		LOG("comm_fsm_recv (GET_IP_NUMB)", message_in);
		if(strcmp(message_in, "NOIP\r\n") == 0)
		{
			comm_state = GET_IP_NUMB;
		}
		else if(strcmp(message_in, "WIFI_DISCONNECTED\r\n") == 0)
		{
			comm_state = CONNECT_WIFI;
		}
		else
		{
			strcpy(ip_number, "\"");
			strcat(ip_number, message_in);
			// The index which corresponds to the '\r' char is overwritten with '\"'
			ip_number[strlen(message_in) - 1] = '\"';
			// The index which corresponds to the '\n' char is overwritten with '\0'
			ip_number[strlen(message_in)] = '\0';
			has_ip_number = TRUE;
			comm_state = GET_MAC_ADDR;
		}
		break;
	}
	case GET_MAC_ADDR:
	{
		LOG("comm_fsm_recv (GET_MAC_ADDR)", message_in);
		if(strcmp(message_in, "WIFI_DISCONNECTED\r\n") == 0)
		{
			comm_state = CONNECT_WIFI;
		}
		else
		{
			strcpy(mac_addr, "\"");
			strcat(mac_addr, message_in);
			// The index which corresponds to the '\r' char is overwritten with '\"'
			mac_addr[strlen(message_in) - 1] = '\"';
			// The index which corresponds to the '\n' char is overwritten with '\0'
			mac_addr[strlen(message_in)] = '\0';
			has_mac_addr = TRUE;
			comm_state = CONNECT_MQTT;
		}
		break;
	}
	case CONNECT_MQTT:
	{
		LOG("comm_fsm_recv (CONNECT_MQTT)", message_in);

		if(strcmp(message_in, "CONNECT MQTT\r\n") == 0)
		{
			comm_state = COMM_INDEED;
		}
		else if(strcmp(message_in, "NOWIFI\r\n") == 0 |
				strcmp(message_in, "WIFI_DISCONNECTED\r\n") == 0)
		{
			comm_state = CONNECT_WIFI;
		}
		else if(strcmp(message_in, "ERROR: 1\r\n") == 0 |
				strcmp(message_in, "ERROR: 2\r\n") == 0 |
				strcmp(message_in, "ERROR: 3\r\n") == 0 |
				strcmp(message_in, "ERROR: 4\r\n") == 0 |
				strcmp(message_in, "MQTT_DISCONNECTED\r\n") == 0)
		{
					comm_state = CONNECT_MQTT;
		}

		break;
	}
	case COMM_INDEED:
	{
		LOG("comm_fsm_recv (COMM_INDEED)", message_in);
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

		//LOG("comm_fsm_send (CONNECT_WIFI)", message_out);
		comm_send_msg();

		break;
	}
	case GET_IP_NUMB:
	{
		strcpy(message_out, "GETIP");
		strcat(message_out, TERMINATING_CHARS);

		//LOG("comm_fsm_send (GET_IP_NUMB)", message_out);
		comm_send_msg();

		break;
	}
	case GET_MAC_ADDR:
	{
		strcpy(message_out, "GETMAC");
		strcat(message_out, TERMINATING_CHARS);

		//LOG("comm_fsm_send (GET_MAC_ADDR)", message_out);
		comm_send_msg();

		break;
	}
	case CONNECT_MQTT:
	{
		strcpy(message_out, "CONNMQTT ");
		strcat(message_out, ip_number);
		strcat(message_out, ",");
		strcat(message_out, MQTT_PORT);
		strcat(message_out, ",");
		strcat(message_out, mac_addr);
		strcat(message_out, ",");
		strcat(message_out, MQTT_USERNAME);
		strcat(message_out, ",");
		strcat(message_out, MQTT_PASSWORD);
		strcat(message_out, TERMINATING_CHARS);

		//LOG("comm_fsm_send (CONNECT_MQTT)", message_out);
		comm_send_msg();

		break;
	}
	case COMM_INDEED:
	{
		//LOG("comm_fsm_send (COMM_INDEED)", message_out);
		break;
	}
	}
	state_changed = FALSE;
}
