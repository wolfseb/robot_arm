#include <cstdint>

#pragma once

struct ServoConfig {
	float minAngle;
//	float centerAngle = 0;
	float maxAngle;

	uint16_t minPWM;
	uint16_t centerPWM;
	uint16_t maxPWM;

	bool inverted;
};

class Servo {
public:
	Servo(const ServoConfig* config);
	uint16_t angle_to_pwm(float angle);

private:
	const ServoConfig* config_;
};
