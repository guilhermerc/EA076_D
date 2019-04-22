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
#define MAXIMUM_PWM	255

/*! @brief A function that initializes the dc motor module
 *
 * This function sets 'CLOCKWISE' as the default direction, '0' as the
 * default PWM and 'OFF' as the default mode. It also enables the PWM.
 */
void dc_motor_init()
{
	dc_motor_set_dir(CLOCKWISE);
	dc_motor_set_pwm(STOP_PWM);
	//dc_motor_set_mode(OFF);

	L293D_1_2_EN_Enable();
}

/*! @brief A function that sets the dc motor direction
 *
 *  @param	dc_motor_dir:
 * 				CLOCKWISE
 * 				ANTICLOCKWISE
 */
void dc_motor_set_dir(DC_MOTOR_DIR dc_motor_dir)
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

	dc_motor_info.last_dir = dc_motor_dir;
}

/*! @brief A function that sets the dc motor PWM speed
 *
 *  @param	dc_motor_pwm:
 * 				A value between MINIMUM_PWM and MAXIMUM_PWM
 */
void dc_motor_set_pwm(uint8_t dc_motor_pwm)
{
	if(dc_motor_pwm >= MINIMUM_PWM && dc_motor_pwm <= MAXIMUM_PWM)
	{
		/*!
		 * This function controls the rate of the LOW slice of the
		 * period. Since I think that it is counterintuitive, I made
		 * this "MAXIMUM_PWM - dc_motor_pwm", so the value of
		 * dc_motor_pwm is actually the rate of the HIGH slice.
		 */
		L293D_1_2_EN_SetRatio8(MAXIMUM_PWM - dc_motor_pwm);
		dc_motor_info.last_pwm = dc_motor_pwm;
	}
}

/*
void dc_motor_set_mode(DC_MOTOR_MODE dc_motor_mode)
{
	switch(dc_motor_mode)
	{
	case ON:
	{
		dc_motor_set_pwm(dc_motor_info.last_pwm);
		break;
	}
	case OFF:
	{
		dc_motor_set_pwm(STOP_PWM);
		break;
	}
	case AUTO:
	{
	}
	}

	dc_motor_info.last_mode = dc_motor_mode;
}
*/
