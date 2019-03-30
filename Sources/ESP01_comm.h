/*!
** @file ESP01_comm.h
** @brief
**         This file exports the needed stuff from ESP01_comm.c
*/

#ifndef SOURCES_ESP01_COMM_H_
#define SOURCES_ESP01_COMM_H_

#include <PE_Types.h>
#include <UART2.h>

bool state_changed;

void comm_fsm_start();
void comm_fsm_receive(UART2_TComData* message);
void comm_fsm_send();

#endif /* SOURCES_ESP01_COMM_H_ */
