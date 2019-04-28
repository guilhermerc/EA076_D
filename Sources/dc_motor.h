/*
 * dc_motor.h
 *
 *  Created on: 15/04/2019
 *      Author: guilherme
 */

#ifndef SOURCES_DC_MOTOR_H_
#define SOURCES_DC_MOTOR_H_

#include <PE_Types.h>

#define MINIMUM_PWM	0
#define MAXIMUM_PWM	255
//typedef uint8_t DC_MOTOR_PWM DC;

typedef enum
{
	CLOCKWISE,
	ANTICLOCKWISE
} _DC_MOTOR_DIR;

typedef enum
{
	ON,
	OFF,
	AUTO
} _DC_MOTOR_MODE;

typedef struct
{
	uint8_t current_pwm;
	_DC_MOTOR_DIR current_dir;
	_DC_MOTOR_MODE current_mode;
} DC_MOTOR_INFO;

DC_MOTOR_INFO dc_motor_info;

void dc_motor_init();
void dc_motor_set_dir(_DC_MOTOR_DIR dc_motor_dir);
void dc_motor_set_pwm(uint8_t dc_motor_pwm);
void dc_motor_set_mode(_DC_MOTOR_MODE dc_motor_mode);

#endif /* SOURCES_DC_MOTOR_H_ */
