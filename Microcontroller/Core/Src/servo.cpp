#include <cmath>
#include <algorithm>

#include "servo.hpp"

//Servo::Servo(ServoConfig config, TimerInit* timer) : config_(config), timer_(timer){};
Servo::Servo(const ServoConfig* config, PwmHandler* pwm) : config_(config), pwm_(pwm){};

void Servo::move(float angle)
{
//	__HAL_TIM_SET_COMPARE(this->timer_->htim, this->timer_->channel, angle_to_pwm_(angle));
	uint16_t value = angle_to_pwm_(angle);
	this->pwm_->handle(value);
};

uint16_t Servo::angle_to_pwm_(float angle)
{
	const float& minAngle = config_->minAngle;
	const float& maxAngle = config_->maxAngle;
	const uint16_t& minPWM = config_->minPWM;
	const uint16_t& centerPWM = config_->centerPWM;
	const uint16_t& maxPWM = config_->maxPWM;

	if (angle < minAngle) angle = minAngle;
	if (angle > maxAngle) angle = maxAngle;

	if (angle < 0)
	{
//		return uint16_t(std::max(int(minPWM), centerPWM + int(std::round((minPWM - centerPWM) * angle/minAngle))));
		return centerPWM + int(std::round((minPWM - centerPWM) * angle/minAngle));
	}
	else if (angle > 0)
	{
//		return uint16_t(std::min(int(maxPWM), centerPWM + int(std::round((maxPWM - centerPWM) * angle/maxAngle))));
		return centerPWM + int(std::round((maxPWM - centerPWM) * angle/maxAngle));
	}
	else
	{
		return centerPWM;
	}
};
