/*!
 * @file kboard.c
 * @brief This file contains implementations related to the keyboard.
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#include <kboard.h>
#include <KBOARD_C1.h>
#include <KBOARD_C2.h>
#include <KBOARD_C3.h>
#include <KBOARD_R1.h>
#include <KBOARD_R2.h>
#include <KBOARD_R3.h>
#include <KBOARD_R4.h>
#include <PORT_PDD.h>
#include <stdint.h>

void kboard_activate_rows();

/*! @brief A function that initializes the keyboard module.
 *
 * This function selects and enables the internal pull-ups on pins
 * which are connected to the keyboard columns; activates (set as LOW)
 * the pins which are connected to the keyboard rows; enables the
 * external interruptions on the pins which are connected to the
 * keyboard columns.
 */
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

	KBOARD_C1_Enable();
	KBOARD_C2_Enable();
	KBOARD_C3_Enable();

	kboard_info.last_key_pressed = NULL;
}

/*! @brief A function that deactivates a single row (set it as HIGH)
 *
 * This function is useful for scanning the row to which the key that
 * generated a interruption belongs: since the column is shorted to the
 * row while this key is pressed, if the logical value of this row
 * changes, the column logical values changes equally.
 *
 * @param row	The row intended to be deactivated
 */
void kboard_deactivate_row(uint8_t row)
{
	switch(row)
	{
	case 1:
	{
		KBOARD_R1_SetVal();
		break;
	}
	case 2:
	{
		KBOARD_R2_SetVal();
		break;
	}
	case 3:
	{
		KBOARD_R3_SetVal();
		break;
	}
	case 4:
	{
		KBOARD_R4_SetVal();
		break;
	}
	}
}

/*! @brief A function that activates the pins which are connected to
 * the keyboard rows (set them as LOW since I'm using pull-ups on
 * column ones)
 */
void kboard_activate_rows()
{
	KBOARD_R1_ClrVal();
	KBOARD_R2_ClrVal();
	KBOARD_R3_ClrVal();
	KBOARD_R4_ClrVal();
}
