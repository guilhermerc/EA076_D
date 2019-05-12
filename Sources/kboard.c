/*
 * kboard.c
 *
 *  Created on: 11/05/2019
 *      Author: guilherme
 */

#include <kboard.h>
#include <KBOARDC1.h>
#include <KBOARDC2.h>
#include <KBOARDC3.h>
#include <KBOARDR1.h>
#include <KBOARDR2.h>
#include <KBOARDR3.h>
#include <KBOARDR4.h>
#include <PORT_PDD.h>
#include <stdint.h>

void kboard_activate_rows();

void kboard_init()
{
	/*! Selecting the pull up resistor on KBOARD_C[1|2|3]_PIN pins */
	PORT_PDD_SetPinPullSelect(PORTA_BASE_PTR, KBOARD_C1_PIN,
			PORT_PDD_PULL_UP);
	PORT_PDD_SetPinPullSelect(PORTA_BASE_PTR, KBOARD_C2_PIN,
			PORT_PDD_PULL_UP);
	PORT_PDD_SetPinPullSelect(PORTA_BASE_PTR, KBOARD_C3_PIN,
			PORT_PDD_PULL_UP);

	/*! Enabling the internal pull resistors on KBOARD_C[1|2|3]_PIN
	 * pins */
	PORT_PDD_SetPinPullEnable(PORTA_BASE_PTR, KBOARD_C1_PIN,
			PORT_PDD_PULL_ENABLE);
	PORT_PDD_SetPinPullEnable(PORTA_BASE_PTR, KBOARD_C2_PIN,
			PORT_PDD_PULL_ENABLE);
	PORT_PDD_SetPinPullEnable(PORTA_BASE_PTR, KBOARD_C3_PIN,
			PORT_PDD_PULL_ENABLE);

	kboard_activate_rows();

	KBOARDC1_Enable();
	KBOARDC2_Enable();
	KBOARDC3_Enable();
}

void kboard_deactivate_row(uint8_t row)
{
	switch(row)
	{
	case 1:
	{
		KBOARDR1_SetVal();
		break;
	}
	case 2:
	{
		KBOARDR2_SetVal();
		break;
	}
	case 3:
	{
		KBOARDR3_SetVal();
		break;
	}
	case 4:
	{
		KBOARDR4_SetVal();
		break;
	}
	}
}

void kboard_activate_rows()
{
	KBOARDR1_ClrVal();
	KBOARDR2_ClrVal();
	KBOARDR3_ClrVal();
	KBOARDR4_ClrVal();
}
