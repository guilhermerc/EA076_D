/*!
** @file ESP01_comm.h
** @brief
**         This file exports the needed stuff from ESP01_comm.c
*/

#include <UART2.h>

void comm_fsm_start();
void comm_fsm_parse(UART2_TComData* message);
void comm_fsm_send();
