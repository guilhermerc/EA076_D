/*!
 * @file motor.c
 * @brief This file contains implementations related to the dc motor.
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#include <L293D_1_2_EN.h>
#include <L293D_1A.h>
#include <L293D_2A.h>
#include <motor.h>
#include <stdint.h>

#define STOP_PWM	0
#define HALF_PWM	127

#define INITIAL_THRESHOLD	30.0

/*! @brief A function that initializes the dc motor module
 *
 * This function sets 'CLOCKWISE' as the default direction, '0' as the
 * default PWM, 'OFF' as the default mode and 30.0 degrees celsius as the
 * default threshold for 'AUTO' mode. It also enables the PWM.
 */
void motor_init()
{
	motor_set_dir(CLOCKWISE);
	motor_set_pwm(STOP_PWM);
	motor_set_mode(OFF);
	motor_set_threshold(INITIAL_THRESHOLD);

	L293D_1_2_EN_Enable();
}

/*! @brief A function that sets the dc motor direction
 *
 *  @param	motor_dir	CLOCKWISE or ANTICLOCKWISE
 */
void motor_set_dir(MOTOR_DIR motor_dir)
{
	if(motor_dir == CLOCKWISE)
	{
		L293D_1A_PutVal(TRUE);
		L293D_2A_PutVal(FALSE);
	}
	else
	{
		L293D_1A_PutVal(FALSE);
		L293D_2A_PutVal(TRUE);
	}

	motor_info.current_dir = motor_dir;
}

/*! @brief A function that sets the dc motor PWM speed
 *
 *  @param	motor_pwm	The PWM value (can be any value, the
 *  						function handles corner cases)
 */
void motor_set_pwm(uint8_t motor_pwm)
{
	if(motor_pwm < MINIMUM_PWM)
		motor_pwm = MINIMUM_PWM;
	if(motor_pwm > MAXIMUM_PWM)
		motor_pwm = MAXIMUM_PWM;

	/*!
	 * This function controls the rate of the LOW slice of the
	 * period. Since I think that it is counterintuitive, I made
	 * this "MAXIMUM_PWM - motor_pwm", so the value of
	 * motor_pwm is actually the rate of the HIGH slice.
	 */
	L293D_1_2_EN_SetRatio8(MAXIMUM_PWM - motor_pwm);

	motor_info.current_pwm = motor_pwm;
}

/*! @brief A function to set the dc motor MODE
 *
 * @param	motor_mode 	ON: In this mode the PWM and direction are
 * 							allowed to be changed. The PWM  and the
 * 							direction keep the same as the previous
 * 							setting.
 * 							OFF: In this mode the PWM is set to 0 and
 * 							the PWM and direction aren't allowed to be
 * 							changed.
 * 							AUTO: In this mode the PWM is set to 255
 * 							when the temperature reading reaches the
 * 							threshold (motor_info.threshold) set by
 * 							the user (default: 40 degrees C). Also, the
 * 							direction is set to CLOCKWSISE (no reason,
 * 							just standardizing it). The PWM and the
 * 							direction aren't allowed to be changed.
 */
void motor_set_mode(MOTOR_MODE motor_mode)
{
	static uint8_t previous_pwm = NULL;
	static MOTOR_DIR previous_dir = NULL;

	/*!
	 * If changing from 'ON' mode, saves the current settings.
	 */
	if(motor_info.current_mode == ON)
	{
		previous_pwm = motor_info.current_pwm;
		previous_dir = motor_info.current_dir;
	}

	if(motor_mode == ON)
	{
		/*!
		 * Restores the previous settings set in the previous 'ON' mode
		 */
		motor_set_pwm(previous_pwm);
		motor_set_dir(previous_dir);
	}
	else if(motor_mode == OFF)
	{
		motor_set_pwm(STOP_PWM);
	}
	else
	{
		motor_set_dir(CLOCKWISE);
	}

	motor_info.current_mode = motor_mode;
}

void motor_set_threshold(float threshold)
{
	motor_info.threshold = threshold;
}
