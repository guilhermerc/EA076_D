/*!
** @file ESP01_comm.h
** @brief
**         This file exports the needed stuff from ESP01_comm.c
*/

#ifndef SOURCES_ESP01_COMM_H_
#define SOURCES_ESP01_COMM_H_

#include <PE_Types.h>
#include <UART2.h>

#define MESSAGE_BUFFER_SIZE	512

UART2_TComData message_out[MESSAGE_BUFFER_SIZE];
UART2_TComData message_in[MESSAGE_BUFFER_SIZE];
volatile bool message_recv;
volatile bool message_sent;

void comm_start();
void comm_parse();
void comm_response();

#endif /* SOURCES_ESP01_COMM_H_ */
