#include "alt_main.h"
#include "robot_arm.hpp"

#include "stm32_pwm_handler.cpp"

#define BUTTON_RELEASED                    0U
#define BUTTON_PRESSED                     1U

int alt_main (Params* params, __IO uint32_t* buttonState)
{
	// initialization
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
	for (TimerInit& timer : params->timerInit)
	{
		HAL_TIM_PWM_Start(timer.htim, timer.channel);
	}

	PwmHandlers pwmHandlers = {
		.hip = new Stm32PwmHandler(&params->timerInit[0]),
		.shoulder = new Stm32PwmHandler(&params->timerInit[1]),
		.elbow = new Stm32PwmHandler(&params->timerInit[2]),
		.wrist = new Stm32PwmHandler(&params->timerInit[3]),
		.wristRot = new Stm32PwmHandler(&params->timerInit[4]),
		.claw = new Stm32PwmHandler(&params->timerInit[5])
	};

	RobotArm robot(&pwmHandlers);

	float pos1[6] = { 0, 0, 0, 0, 0, 75 };
	float pos2[6] = { -60, 30, -60, -60, 0, 40 };
	float *pos = pos1;
	bool pos_toggle = false;

	while (1)
	{
		if (*buttonState == BUTTON_PRESSED)
		{
			*buttonState = BUTTON_RELEASED;
			BSP_LED_Toggle(LED2);
			if (pos_toggle) pos = pos1;
			else pos = pos2;
			pos_toggle = !pos_toggle;
		}

		robot.setJoint(Joint::HIP, pos[0]);
		robot.setJoint(Joint::SHOULDER, pos[1]);
		robot.setJoint(Joint::ELBOW, pos[2]);
		robot.setJoint(Joint::WRIST, pos[3]);
		robot.setJoint(Joint::WRIST_ROT, pos[4]);
		robot.setJoint(Joint::CLAW, pos[5]);
		robot.update();
		// loop
	}
}
