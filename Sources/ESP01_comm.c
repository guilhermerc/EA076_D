/*!
 ** @file ESP01_comm.c
 ** @brief
 **         This file contains the FSM implementation for communicating
 **         with the MQTT Broker (using the ESP-01 module).
 */

#include <ESP01_comm.h>
#include <LOG.h>
#include <stdint.h>
#include <string.h>
#include <UART0.h>
#include <UART2Events.h>

#define WIFI_SSID "\"EA076R\""
#define WIFI_PASSWORD "\"FRDMKL25\""
#define MQTT_IP "\"192.168.1.111\""
#define MQTT_PORT "1883"
#define MQTT_USERNAME "\"aluno\""
#define MQTT_PASSWORD "\"UNICAMP\""
#define SMARTPHONE_TOPIC "\"EA076/grupoD3/celular\""
#define SMARTPHONE_TOPIC_WQ "EA076/grupoD3/celular"
#define TERMINATING_CHARS "\r\n"
#define MAX_TOKENS	32

#define IP_NUMBER_SIZE	32
static char ip_number[IP_NUMBER_SIZE];	// it should be const

#define MAC_ADDR_SIZE	64
static char mac_addr[MAC_ADDR_SIZE];	// it should be const

static UART2_TComData * tokens[MAX_TOKENS];

typedef enum COMM_STATE
{
	CONNECT_WIFI,
	GET_IP_NUMB,
	GET_MAC_ADDR,
	CONNECT_MQTT,
	WAITING_FOR_CMD,
	TOPIC_SUBSC,
	TOPIC_UNSUBSC,
	PUBLISHING,
	PINGING
} COMM_STATE_ENUM;

typedef struct COMM_INFO
{
	COMM_STATE_ENUM state;
} COMM_INFO_STRUCT;

COMM_INFO_STRUCT comm_info;

void comm_established_recv();
bool comm_are_there_conn_errors();

void comm_start()
{
	comm_info.state = CONNECT_WIFI;
	message_received = FALSE;
	comm_send();
}

void comm_send_msg()
{
	UART2_OnTxChar();
}

void comm_send()
{
	switch(comm_info.state)
	{
	case CONNECT_WIFI:
	{
		strcpy(message_out, "CONNWIFI ");
		strcat(message_out, WIFI_SSID);
		strcat(message_out, ",");
		strcat(message_out, WIFI_PASSWORD);
		strcat(message_out, TERMINATING_CHARS);

		//LOG("comm_fsm_send (CONNECT_WIFI)", message_out);

		break;
	}
	case GET_IP_NUMB:
	{
		strcpy(message_out, "GETIP");
		strcat(message_out, TERMINATING_CHARS);

		//LOG("comm_fsm_send (GET_IP_NUMB)", message_out);

		break;
	}
	case GET_MAC_ADDR:
	{
		strcpy(message_out, "GETMAC");
		strcat(message_out, TERMINATING_CHARS);

		//LOG("comm_fsm_send (GET_MAC_ADDR)", message_out);

		break;
	}
	case CONNECT_MQTT:
	{
		strcpy(message_out, "CONNMQTT ");
		strcat(message_out, MQTT_IP);
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

		break;
	}
	case TOPIC_SUBSC:
	{
		strcpy(message_out, "SUBSCRIBE ");
		strcat(message_out, SMARTPHONE_TOPIC);
		strcat(message_out, TERMINATING_CHARS);

		//LOG("comm_fsm_send (COMM_INDEED)", message_out);

		break;
	}
	case TOPIC_UNSUBSC:
	case PUBLISHING:
	case PINGING:
	{
		strcpy(message_out, message_in);
		break;
	}
	}
	comm_send_msg();
}

void comm_recv()
{
	static bool has_ip_number = FALSE;
	static bool has_mac_addr = FALSE;

	if(comm_are_there_conn_errors())	return;

	switch(comm_info.state)
	{
	case CONNECT_WIFI:
	{
		LOG("comm_fsm_recv (CONNECT_WIFI)", message_in);

		if(strcmp(message_in, "CONNECT WIFI\r\n") == 0)
		{
			if(has_ip_number != TRUE)
				comm_info.state = GET_IP_NUMB;
			else if(has_mac_addr != TRUE)
				comm_info.state = GET_MAC_ADDR;
			else
				comm_info.state = CONNECT_MQTT;
		}
		else if(strcmp(message_in, "ERROR WIFI\r\n") == 0)
		{
			comm_info.state = CONNECT_WIFI;
		}

		break;
	}
	case GET_IP_NUMB:
	{
		LOG("comm_fsm_recv (GET_IP_NUMB)", message_in);
		if(strcmp(message_in, "NOIP\r\n") == 0)
		{
			comm_info.state = GET_IP_NUMB;
		}
		else if(strcmp(message_in, "WIFI_DISCONNECTED\r\n") == 0)
		{
			comm_info.state = CONNECT_WIFI;
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
			comm_info.state = GET_MAC_ADDR;
		}
		break;
	}
	case GET_MAC_ADDR:
	{
		LOG("comm_fsm_recv (GET_MAC_ADDR)", message_in);
		if(strcmp(message_in, "WIFI_DISCONNECTED\r\n") == 0)
		{
			comm_info.state = CONNECT_WIFI;
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
			comm_info.state = CONNECT_MQTT;
		}
		break;
	}
	case CONNECT_MQTT:
	{
		LOG("comm_fsm_recv (CONNECT_MQTT)", message_in);

		if(strcmp(message_in, "CONNECT MQTT\r\n") == 0)
		{
			comm_info.state = TOPIC_SUBSC;
		}
		else if(strcmp(message_in, "NOWIFI\r\n") == 0 ||
				strcmp(message_in, "WIFI_DISCONNECTED\r\n") == 0)
		{
			comm_info.state = CONNECT_WIFI;
		}
		else if(strcmp(message_in, "ERROR: -1\r\n") == 0 ||
				strcmp(message_in, "ERROR: -2\r\n") == 0 ||
				strcmp(message_in, "ERROR: -3\r\n") == 0 ||
				strcmp(message_in, "ERROR: -4\r\n") == 0 ||
				strcmp(message_in, "MQTT_DISCONNECTED\r\n") == 0)
		{
			comm_info.state = CONNECT_MQTT;
		}

		break;
	}
	case WAITING_FOR_CMD:
	{
		LOG("comm_fsm_recv (WAITING_FOR_CMD)", "Waiting for commands...");

		UART2_TComData message_in_copy[strlen(message_in) + 1];
		strcpy(message_in_copy, message_in);

		uint8_t curr_token_idx = 0;

		tokens[curr_token_idx++] = strtok(message_in_copy, " ");

		//LOG("comm_fsm_recv (TOPIC_SUBSD)", message_in);

		if((strcmp(tokens[0], "MESSAGE") == 0))
		{
			while(tokens[curr_token_idx++] != NULL)
			{
				// The message cannot contain '[', ']' or ','
				tokens[curr_token_idx] = strtok(NULL, "[],");
			}

			if(strcmp(tokens[1], SMARTPHONE_TOPIC_WQ) == 0)
			{
				strcat(tokens[2], "\n");
				LOG("comm_fsm_recv (WAITING_FOR_CMD)", tokens[2]);
			}
		}
		else if((strcmp(tokens[0], "SUBSCRIBE") == 0))
		{
			comm_info.state = TOPIC_SUBSC;
		}
		else if((strcmp(tokens[0], "UNSUBSCRIBE") == 0))
		{
			comm_info.state = TOPIC_UNSUBSC;
		}
		else if((strcmp(tokens[0], "PUBLISH") == 0))
		{
			comm_info.state = PUBLISHING;
		}
		else if((strcmp(tokens[0], "PINGING") == 0))
		{
			comm_info.state = PINGING;
		}

		break;
	}
	case TOPIC_SUBSC:
	{
		//LOG("comm_fsm_recv (TOPIC_SUBSC)", message_in);

		if(strcmp(message_in, "OK SUBSCRIBE\r\n") == 0)
		{
			comm_info.state = TOPIC_SUBSC;
		}
		else if(strcmp(message_in, "NOT CONNECTED\r\n") == 0 |
				strcmp(message_in, "MQTT_DISCONNECTED\r\n") == 0)
		{
			comm_info.state = CONNECT_MQTT;
		}
		else if(strcmp(message_in, "ERROR SUBSCRIBE\r\n") == 0)
		{
			comm_info.state = TOPIC_SUBSC;
		}
		else if(strcmp(message_in, "WIFI_DISCONNECTED\r\n") == 0)
		{
			comm_info.state = CONNECT_WIFI;
		}

		break;
	}
	case TOPIC_UNSUBSC:
	{
		if(strcmp(message_in, "OK UNSUBSCRIBE\r\n") == 0)
		{
			comm_info.state = WAITING_FOR_CMD;
		}
		else if(strcmp(message_in, "NOT CONNECTED\r\n") == 0)
		{
			comm_info.state = CONNECT_MQTT;
		}
		else if(strcmp(message_in, "ERROR SUBSCRIBE\r\n") == 0)
		{
			comm_info.state = TOPIC_UNSUBSC;
		}

		break;
	}
	case PUBLISHING:
	{
		if(strcmp(message_in, "OK PUBLISH\r\n") == 0)
		{
			comm_info.state = WAITING_FOR_CMD;
		}
		else if(strcmp(message_in, "NOT CONNECTED\r\n") == 0)
		{
			comm_info.state = CONNECT_MQTT;
		}
		else if(strcmp(message_in, "ERROR PUBLISH\r\n") == 0)
		{
			comm_info.state = PUBLISHING;
		}
	}
	case PINGING:
	{
		if(strcmp(message_in, "PONG\r\n") == 0)
		{
			comm_info.state = WAITING_FOR_CMD;
		}
		else if(strcmp(message_in, "NO PONG\r\n") == 0)
		{
			comm_info.state = PINGING;
		}
	}
	}
}

bool comm_are_there_conn_errors()
{
	bool status = FALSE;
	if(strcmp(message_in, "WIFI_DISCONNECTED\r\n") == 0)
	{
		comm_info.state = CONNECT_WIFI;
		status = TRUE;
	}
	else if(strcmp(message_in, "MQTT_DISCONNECTED\r\n") == 0)
	{
		comm_info.state = CONNECT_MQTT;
		status = TRUE;
	}

	if(status = TRUE)
	{
		LOG("comm_fsm_recv (TOPIC_SUBSD)", message_in);
	}

	return status;
}
