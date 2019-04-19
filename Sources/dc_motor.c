/*
 * dc_motor.c
 *
 *  Created on: 15/04/2019
 *      Author: guilherme
 */

#include <dc_motor.h>
#include <L293D_1A.h>
#include <L293D_2A.h>
#include <L293D_1_2_EN.h>

#define STOP_PWM	0
#define HALF_PWM	127

void dc_motor_init()
{
	dc_motor_set_dir(CLOCKWISE);
	dc_motor_set_pwm(STOP_PWM);
	dc_motor_set_mode(OFF);

	L293D_1_2_EN_Enable();
}

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

void dc_motor_set_pwm(uint8_t dc_motor_pwm)
{
	L293D_1_2_EN_SetRatio8(dc_motor_pwm);

	dc_motor_info.last_pwm = dc_motor_pwm;
}

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
