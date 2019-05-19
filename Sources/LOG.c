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

#include <comm.h>
#include <Events.h>
#include <LOG.h>
#include <string.h>

/*!
 * @brief A function that logs into UART0 TX
 *
 * @param	tag		The tag of the log entry
 * @param 	message	The log entry content to be logged
 *
 * NOTE: If tag is passed as NULL, then the only string logged is
 * 'message'. This is useful to echo the received characters from
 * terminal.
 */
void LOG(char * tag, UART0_TComData * message)
{
	comm_info.loging_status = SENDING;

	if(tag != NULL)
	{
		strcpy(log_buffer, tag);
		strcat(log_buffer, ": ");
		strcat(log_buffer, message);
	}
	else
		strcpy(log_buffer, message);
	UART0_OnTxChar();
}
