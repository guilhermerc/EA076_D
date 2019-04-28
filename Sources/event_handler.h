/*!
 * @file event_handler.h
 * @brief This file exports what is necessary from event_handler.c
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#ifndef SOURCES_EVENT_HANDLER_H_
#define SOURCES_EVENT_HANDLER_H_

#include <event_ring_buff.h>

void event_handler(EVENT_RING_BUFF_TYPE event);

#endif /* SOURCES_EVENT_HANDLER_H_ */
