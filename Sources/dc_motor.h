/*
 * dc_motor.h
 *
 *  Created on: 15/04/2019
 *      Author: guilherme
 */

#ifndef SOURCES_DC_MOTOR_H_
#define SOURCES_DC_MOTOR_H_

#include "PE_Types.h"

//typedef uint8_t DC_MOTOR_PWM DC;

typedef enum
{
	CLOCKWISE,
	ANTICLOCKWISE
} DC_MOTOR_DIR;

typedef enum
{
	ON,
	OFF,
	AUTO
} DC_MOTOR_MODE;

typedef struct
{
	uint8_t last_pwm;
	DC_MOTOR_DIR last_dir;
	DC_MOTOR_MODE last_mode;
} DC_MOTOR_INFO;

DC_MOTOR_INFO dc_motor_info;

void dc_motor_init();
void dc_motor_set_dir(DC_MOTOR_DIR dc_motor_dir);
void dc_motor_set_pwm(uint8_t dc_motor_pwm);
void dc_motor_set_mode(DC_MOTOR_MODE dc_motor_mode);

#endif /* SOURCES_DC_MOTOR_H_ */
