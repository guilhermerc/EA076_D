/*!
** @file LOG.h
** @brief This file exports what is necessary from LOG.c
**
** @author Guilherme R C <guilherme.riciolic@gmail.com>
*/

/*
 * LOG.h
 *
 *  Created on: 30/03/2019
 *      Author: guilherme
 */

#ifndef SOURCES_LOG_H_
#define SOURCES_LOG_H_

#include <UART0.h>


#define LOG_BUFFER_SIZE	512

volatile UART0_TComData log_buffer[LOG_BUFFER_SIZE];

void LOG(char * function_name, UART0_TComData * message);

#endif /* SOURCES_LOG_H_ */
