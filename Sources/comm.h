/*!
** @file comm.h
** @brief
**         This file exports the needed stuff from ESP01_comm.c
*/

#ifndef SOURCES_COMM_H_
#define SOURCES_COMM_H_

#include <PE_Types.h>
#include <UART2.h>

#define TERMINATING_CHARS "\r\n"
#define MESSAGE_BUFFER_SIZE	512

typedef enum COMM_SENDING_STATUS
{
	DONE,
	SENDING
} COMM_SENDING_STATUS;

typedef enum COMM_STATUS
{
	AVAILABLE,
	BUSY
} COMM_STATUS;

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
	volatile COMM_STATE_ENUM state;
	volatile bool message_received;
	volatile COMM_SENDING_STATUS sending_status;
	volatile COMM_SENDING_STATUS loging_status;
} COMM_INFO_STRUCT;

COMM_INFO_STRUCT comm_info;
UART2_TComData message_out[MESSAGE_BUFFER_SIZE];
UART2_TComData message_in[MESSAGE_BUFFER_SIZE];
volatile bool message_recv;

void comm_init();
COMM_STATUS comm_status();
void comm_parse();
void comm_response();

#endif /* SOURCES_COMM_H_ */
