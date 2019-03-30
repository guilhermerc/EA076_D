/*!
** @file ESP01_comm.c
** @brief
**         This file contains the FSM implementation for communicating
**         with the MQTT Broker (using the ESP-01 module).
*/


#define WIFI_SSID "EA076"
#define WIFI_PASSWORD "FRDMKL25Z"
#define MQTT_PORT "1883"
#define MQTT_USERNAME "GUILHERME"
#define MQTT_PSSWORD "UNICAMP"

typedef enum COMM_STATE
{
	CONNECT_WIFI,
	GET_IP_NUMB,
	GET_MAC_ADD,
	CONNECT_MQTT,
	INDEED_COMM
} COMM_STATE_ENUM;

COMM_STATE_ENUM comm_state = CONNECT_WIFI;

void communication_fsm()
{
	switch(comm_state)
	{
	case CONNECT_WIFI:
	case GET_IP_NUMB:
	case GET_MAC_ADD:
	case CONNECT_MQTT:
	case INDEED_COMM:
	{
		break;
	}
	}
}
