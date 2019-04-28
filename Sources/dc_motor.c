/*
 * dc_motor.c
 *
 *  Created on: 15/04/2019
 *      Author: guilherme
 */

#include <dc_motor.h>
#include <L293D_1_2_EN.h>
#include <L293D_1A.h>
#include <L293D_2A.h>
#include <stdint.h>

#define STOP_PWM	0
#define HALF_PWM	127

/*! @brief A function that initializes the dc motor module
 *
 * This function sets 'CLOCKWISE' as the default direction, '0' as the
 * default PWM and 'OFF' as the default mode. It also enables the PWM.
 */
void dc_motor_init()
{
	dc_motor_set_dir(CLOCKWISE);
	dc_motor_set_pwm(STOP_PWM);
	dc_motor_set_mode(ON);

	L293D_1_2_EN_Enable();
}

/*! @brief A function that sets the dc motor direction
 *
 *  @param	dc_motor_dir:
 * 				CLOCKWISE
 * 				ANTICLOCKWISE
 */
void dc_motor_set_dir(_DC_MOTOR_DIR dc_motor_dir)
{
	if(dc_motor_dir == CLOCKWISE)
	{
		L293D_1A_PutVal(TRUE);
		L293D_2A_PutVal(FALSE);
	}
	else
	{
		L293D_1A_PutVal(FALSE);
		L293D_2A_PutVal(TRUE);
	}

	dc_motor_info.current_dir = dc_motor_dir;
}

/*! @brief A function that sets the dc motor PWM speed
 *
 *  @param	dc_motor_pwm:
 * 				A value between MINIMUM_PWM and MAXIMUM_PWM
 */
void dc_motor_set_pwm(uint8_t dc_motor_pwm)
{
	if(dc_motor_pwm < MINIMUM_PWM)
		dc_motor_pwm = MINIMUM_PWM;
	if(dc_motor_pwm > MAXIMUM_PWM)
		dc_motor_pwm = MAXIMUM_PWM;

	/*!
	 * This function controls the rate of the LOW slice of the
	 * period. Since I think that it is counterintuitive, I made
	 * this "MAXIMUM_PWM - dc_motor_pwm", so the value of
	 * dc_motor_pwm is actually the rate of the HIGH slice.
	 */
	L293D_1_2_EN_SetRatio8(MAXIMUM_PWM - dc_motor_pwm);

	dc_motor_info.current_pwm = dc_motor_pwm;
}

/*! @brief A function to set the dc motor MODE
 *
 * @param dc_motor_mode
 * 				ON - In this mode the PWM and direction can be changed.
 * 				The PWM will start with 0 and the direction keeps the
 * 				same as the previous setting.
 * 				OFF -  In this mode the PWM is set to 0 and it becomes
 * 				unchangeable. The direction is also unchangeable.
 * 				AUTO - In this mode the PWM is set to 255 when the
 * 				temperature reading reaches a threshold set by the user
 * 				(default: 28 degrees C). Also, the direction is set to
 * 				CLOCKWSISE (no reason, just standardizing it). The PWM
 * 				and the direction are unchangeable.
 */
void dc_motor_set_mode(_DC_MOTOR_MODE dc_motor_mode)
{
	static uint8_t previous_pwm = NULL;
	static _DC_MOTOR_DIR previous_dir = NULL;

	/*!
	 * If changing from 'ON' mode, saves the current settings.
	 */
	if(dc_motor_info.current_mode == ON)
	{
		previous_pwm = dc_motor_info.current_pwm;
		previous_dir = dc_motor_info.current_dir;
	}

	if(dc_motor_mode == ON)
	{
		/*!
		 * Restores the previous settings set in the previous 'ON' mode
		 */
		dc_motor_set_pwm(previous_pwm);
		dc_motor_set_dir(previous_dir);
	}
	else if(dc_motor_mode == OFF)
	{
		dc_motor_set_pwm(STOP_PWM);
	}
	else
	{
		dc_motor_set_dir(CLOCKWISE);
	}

	dc_motor_info.current_mode = dc_motor_mode;
}
