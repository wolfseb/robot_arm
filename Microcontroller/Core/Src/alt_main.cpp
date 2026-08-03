#include "alt_main.h"
#include "robot_arm.hpp"

// #include "stm32_pwm_configs.hpp"
// #include "stm32_pwm_handler.cpp"
#include "pca9685_pwm_configs.hpp"
#include "pca9685_pwm_handler.cpp"

#define BUTTON_RELEASED                    0U
#define BUTTON_PRESSED                     1U

int alt_main (Params* params, __IO uint32_t* buttonState)
{
	// initialization
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
//	std::array<TimerInit, JointCount> timers {
//		params->timerInitList.hip,
//		params->timerInitList.shoulder,
//		params->timerInitList.elbow,
//		params->timerInitList.wrist,
//		params->timerInitList.wristRot,
//		params->timerInitList.claw,
//	};
//	for (TimerInit& timer : timers)
//	{
//		HAL_TIM_PWM_Start(timer.htim, timer.channel);
//	}
//	Stm32PwmHandler pwmHandler(&timers);

	PCA9685_PwmHandler pwmHandler(params->i2cInit.hi2c);
	std::array<ServoConfig, JointCount> servoConfigs = {
			PCA9685_ServoConfigs::hip,
			PCA9685_ServoConfigs::shoulder,
			PCA9685_ServoConfigs::elbow,
			PCA9685_ServoConfigs::wrist,
			PCA9685_ServoConfigs::wristRot,
			PCA9685_ServoConfigs::claw
	};

	RobotArm robot(&pwmHandler, &servoConfigs);

	std::array<float, 6> pos1 = { 0, 0, 0, 0, 0, 75 };
	std::array<float, 6> pos2 = { -60, 30, -60, -60, 0, 40 };
	std::array<float, 6>* pos = &pos1;
	bool pos_toggle = false;

	while (1)
	{
		if (*buttonState == BUTTON_PRESSED)
		{
			*buttonState = BUTTON_RELEASED;
			BSP_LED_Toggle(LED2);
			if (pos_toggle) pos = &pos1;
			else pos = &pos2;
			pos_toggle = !pos_toggle;
		}

		robot.setJoints(pos);
		robot.update();
	}
}
