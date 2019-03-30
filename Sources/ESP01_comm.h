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

volatile UART2_TComData message_out[MESSAGE_BUFFER_SIZE];
volatile bool state_changed;

void comm_fsm_start();
void comm_fsm_recv(UART2_TComData* message_in);
void comm_fsm_send();

#endif /* SOURCES_ESP01_COMM_H_ */
