/*!
** @file LOG.c
*/

/*
 * LOG.c
 *
 *  Created on: 30/03/2019
 *      Author: guilherme
 */

#include <comm.h>
#include <LOG.h>
#include <string.h>
#include <UART0Events.h>

/*! \brief A function that logs something into UART0 TX
**
** 	This function assembles the log entry message and
**  triggers the sending process.
** 	This handler also notifies the main loop when a
** 	log entry is being sent (using the log_entry_sent
** 	flags).
**
** 	NOTE: If tag is passed as NULL, then the only message logged
** 	is the 'message' string. This is used to echo the received
** 	characters from terminal.
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
