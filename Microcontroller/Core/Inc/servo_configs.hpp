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

namespace ServoConfigs {
    inline constexpr ServoConfig hip = {
        .minAngle = -90,
        .maxAngle = 90,
        .minPWM = 560,
        .centerPWM = 1560,
        .maxPWM = 2560,
		.inverted = false
    };
    inline constexpr ServoConfig shoulder = {
        .minAngle = -80,
        .maxAngle = 80,
        .minPWM = 2350, // forward
        .centerPWM = 1480,
        .maxPWM = 580, // backward
		.inverted = false
    };
    inline constexpr ServoConfig elbow = {
        .minAngle = -90,
        .maxAngle = 90,
        .minPWM = 2450,
        .centerPWM = 1450,
        .maxPWM = 480,
		.inverted = false
    };
    inline constexpr ServoConfig wrist = {
        .minAngle = -90,
        .maxAngle = 0,  // mechanical block, don't go over 0 deg!!
        .minPWM = 430,
        .centerPWM = 1400,
        .maxPWM = 1400,
		.inverted = false
    };
    inline constexpr ServoConfig wristRot = {
        .minAngle = -90.0,
        .maxAngle = 90.0,
        .minPWM = 2450, // -90deg (ccw)
        .centerPWM = 1450,
        .maxPWM = 450,   // +90deg (cw)
		.inverted = false
    };
    inline constexpr ServoConfig claw = {
        .minAngle = 0,
        .maxAngle = 75,
        .minPWM = 900,
        .centerPWM = 900,
        .maxPWM = 1450,
		.inverted = false
    };
}
