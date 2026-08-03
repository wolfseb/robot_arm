#include <cmath>
#include <algorithm>

#include "servo.hpp"

Servo::Servo(const ServoConfig* config) : config_(config){};

uint16_t Servo::angle_to_pwm(float angle)
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
		return centerPWM + int(std::round((minPWM - centerPWM) * angle/minAngle));
	}
	else if (angle > 0)
	{
		return centerPWM + int(std::round((maxPWM - centerPWM) * angle/maxAngle));
	}
	else
	{
		return centerPWM;
	}
};
