/*
 * LOG.c
 *
 *  Created on: 30/03/2019
 *      Author: guilherme
 */

#include <string.h>
#include <UART0.h>
#include "LOG.h"

void LOG(char * function_name, UART0_TComData * message)
{
	strcpy(log_buffer, function_name);
	strcat(log_buffer, ": ");
	strcat(log_buffer, message);
	UART0_EnableEvent();
}
