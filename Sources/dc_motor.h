/*!
 * @file dc_motor.h
 * @brief This file exports what is necessary from dc_motor.c
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#ifndef SOURCES_DC_MOTOR_H_
#define SOURCES_DC_MOTOR_H_

#include <PE_Types.h>

#define MINIMUM_PWM	0
#define MAXIMUM_PWM	255

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
	uint8_t current_pwm;
	DC_MOTOR_DIR current_dir;
	DC_MOTOR_MODE current_mode;
	float threshold;
} DC_MOTOR_INFO;

DC_MOTOR_INFO dc_motor_info;

void dc_motor_init();
void dc_motor_set_dir(DC_MOTOR_DIR dc_motor_dir);
void dc_motor_set_pwm(uint8_t dc_motor_pwm);
void dc_motor_set_mode(DC_MOTOR_MODE dc_motor_mode);
void dc_motor_set_threshold(float threshold);

#endif /* SOURCES_DC_MOTOR_H_ */
