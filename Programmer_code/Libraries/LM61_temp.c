/*
 * LM61_temp.c
 *
 *  Created on: 13/04/2019
 *      Author: guilherme
 */

#include <ADC0.h>
#include <LM61_temp.h>
#include <TI0.h>

void temp_init()
{
	temp_info.measurement_state = REQUESTING;

	TI0_EnableEvent();
	ADC0_EnableEvent();
}
