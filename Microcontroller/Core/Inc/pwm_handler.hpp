#include <cstdint>

#include "servo.hpp"
#include "robot_arm_joints.hpp"

#pragma once

class PwmHandler
{
public:
	virtual void handle(std::array<Servo, JointCount>* servos, std::array<float, JointCount>* pos) = 0;
	virtual ~PwmHandler() = default;
};
