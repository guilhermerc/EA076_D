/*
 * LOG.c
 *
 *  Created on: 30/03/2019
 *      Author: guilherme
 */

#include <LOG.h>
#include <string.h>
#include <UART0Events.h>

void LOG(char * function_name, UART0_TComData * message)
{
	strcpy(log_buffer, function_name);
	strcat(log_buffer, ": ");
	strcat(log_buffer, message);
	UART0_EnableEvent();
	UART0_OnTxChar();
}
