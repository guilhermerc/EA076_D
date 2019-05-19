/*!
** @file LOG.c
** @brief This file contains the implementations related to the logging
** process
**
** @author Guilherme R C <guilherme.riciolic@gmail.com>
*/

/*
 * LOG.c
 *
 *  Created on: 30/03/2019
 *      Author: guilherme
 */

#include <console.h>
#include <Events.h>
#include <string.h>

void console_init()
{
	console_info.status = DONE;
}

/*!
 * @brief A function that writes into UART0 TX channel
 *
 * @param	tag		The tag of a log entry
 * @param 	message	The message or log entry content to be written
 *
 * NOTE: If tag is passed as NULL, then the only string written is
 * 'message'. This is useful to echo the received characters from
 * terminal.
 */
void console_write(char * tag, UART0_TComData * message)
{
	console_info.status = SENDING;

	if(tag != NULL)
	{
		strcpy(console_info.buffer, tag);
		strcat(console_info.buffer, ": ");
		strcat(console_info.buffer, message);
	}
	else
		strcpy(console_info.buffer, message);

	UART0_OnTxChar();
}
