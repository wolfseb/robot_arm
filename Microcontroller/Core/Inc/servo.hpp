#include <cstdint>

#include "servo_configs.hpp"
#include "pwm_handler.hpp"

#pragma once

class Servo {
public:
	Servo(const ServoConfig* config, PwmHandler* pwm);
	void move(float angle);

private:
	const ServoConfig* config_;
	PwmHandler* pwm_;
	uint16_t angle_to_pwm_(float angle);
};
