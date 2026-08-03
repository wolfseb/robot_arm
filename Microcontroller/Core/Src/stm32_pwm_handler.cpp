#include <array>

#include "alt_main.h"
#include "pwm_handler.hpp"
#include "servo.hpp"
#include "robot_arm.hpp"

class STM32_PwmHandler : public PwmHandler
{
public:
	STM32_PwmHandler(std::array<TimerInit, JointCount>* timers) : timers_(timers){}

	void handle(std::array<Servo, JointCount>* servos, std::array<float, JointCount>* pos) override
	{
		for (Joint joint : allJoints)
		{
			std::size_t j = toIndex(joint);
			uint16_t pwm = (*servos)[j].angle_to_pwm((*pos)[j]);
			__HAL_TIM_SET_COMPARE((*timers_)[j].htim, (*timers_)[j].channel, pwm);
		}
	};

private:
	std::array<TimerInit, JointCount>* timers_;
};
