/*!
 * @file motor.h
 * @brief This file exports what is necessary from motor.c
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#ifndef SOURCES_MOTOR_H_
#define SOURCES_MOTOR_H_

#include <PE_Types.h>

#define MINIMUM_PWM	0
#define MAXIMUM_PWM	255

typedef enum
{
	CLOCKWISE,
	ANTICLOCKWISE
} MOTOR_DIR;

typedef enum
{
	ON,
	OFF,
	AUTO
} MOTOR_MODE;

typedef struct
{
	uint8_t current_pwm;
	MOTOR_DIR current_dir;
	MOTOR_MODE current_mode;
	float threshold;
} MOTOR_INFO;

MOTOR_INFO motor_info;

void motor_init();
void motor_set_dir(MOTOR_DIR motor_dir);
void motor_set_pwm(uint8_t motor_pwm);
void motor_set_mode(MOTOR_MODE motor_mode);
void motor_set_threshold(float threshold);
void motor_change_speed(int8_t amount);

#endif /* SOURCES_MOTOR_H_ */
