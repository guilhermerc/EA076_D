/*!
 * @file dc_motor.c
 * @brief This file contains implementations related to the dc motor.
 *
 * @author Guilherme R C <guilherme.riciolic@gmail.com>
 */

#include <dc_motor.h>
#include <L293D_1_2_EN.h>
#include <L293D_1A.h>
#include <L293D_2A.h>
#include <stdint.h>

#define STOP_PWM	0
#define HALF_PWM	127

#define INITIAL_THRESHOLD	40

/*! @brief A function that initializes the dc motor module
 *
 * This function sets 'CLOCKWISE' as the default direction, '0' as the
 * default PWM, 'OFF' as the default mode and 40 degrees celsius as the
 * default threshold for 'AUTO' mode. It also enables the PWM.
 */
void dc_motor_init()
{
	dc_motor_set_dir(CLOCKWISE);
	dc_motor_set_pwm(STOP_PWM);
	dc_motor_set_mode(OFF);
	dc_motor_set_threshold(INITIAL_THRESHOLD);

	L293D_1_2_EN_Enable();
}

/*! @brief A function that sets the dc motor direction
 *
 *  @param	dc_motor_dir	CLOCKWISE or ANTICLOCKWISE
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

	dc_motor_info.current_dir = dc_motor_dir;
}

/*! @brief A function that sets the dc motor PWM speed
 *
 *  @param	dc_motor_pwm	The PWM value (can be any value, the
 *  						function handles corner cases)
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
 * @param	dc_motor_mode 	ON: In this mode the PWM and direction are
 * 							allowed to be changed. The PWM  and the
 * 							direction keep the same as the previous
 * 							setting.
 * 							OFF: In this mode the PWM is set to 0 and
 * 							the PWM and direction aren't allowed to be
 * 							changed.
 * 							AUTO: In this mode the PWM is set to 255
 * 							when the temperature reading reaches the
 * 							threshold (dc_motor_info.threshold) set by
 * 							the user (default: 40 degrees C). Also, the
 * 							direction is set to CLOCKWSISE (no reason,
 * 							just standardizing it). The PWM and the
 * 							direction aren't allowed to be changed.
 */
void dc_motor_set_mode(DC_MOTOR_MODE dc_motor_mode)
{
	static uint8_t previous_pwm = NULL;
	static DC_MOTOR_DIR previous_dir = NULL;

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

void dc_motor_set_threshold(int16_t threshold)
{
	dc_motor_info.threshold = threshold;
}
