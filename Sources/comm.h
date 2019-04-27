/*!
** @file comm.h
** @brief
**         This file exports the needed stuff from ESP01_comm.c
*/

#ifndef SOURCES_COMM_H_
#define SOURCES_COMM_H_

#include <PE_Types.h>

#define TERMINATING_CHARS "\r\n"
#define TEMPERATURE_TOPIC "\"EA076/grupoD3/temp\""
#define MESSAGE_BUFFER_SIZE	512

typedef enum
{
	DONE,
	SENDING
} COMM_SENDING_STATUS;

typedef enum
{
	AVAILABLE,
	BUSY
} COMM_STATUS;

typedef enum
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

typedef struct
{
	volatile COMM_STATE_ENUM state;
	volatile bool message_received;
	volatile COMM_SENDING_STATUS sending_status;
	volatile COMM_SENDING_STATUS loging_status;
	char message_in[MESSAGE_BUFFER_SIZE];
	char message_out[MESSAGE_BUFFER_SIZE];
} COMM_INFO_STRUCT;

COMM_INFO_STRUCT comm_info;

/*
UART2_TComData message_out[MESSAGE_BUFFER_SIZE];
UART2_TComData message_in[MESSAGE_BUFFER_SIZE];
volatile bool message_recv;
*/

void comm_init();
COMM_STATUS comm_status();
void comm_process_msg();
void comm_clear_input_buffer();
void comm_publish(char * topic, char * message);

#endif /* SOURCES_COMM_H_ */
