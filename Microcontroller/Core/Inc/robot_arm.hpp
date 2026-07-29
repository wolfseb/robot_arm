#include <array>
#include "servo.hpp"

// struct Limbs {
//     float shoulderElbow;
//     float elbowWrist;
//     float wristRotL;
//     float wristRotZ;
//     float wristClawL;
//     float wristClawZ;
// }

#pragma once

struct PwmHandlers {
	PwmHandler* hip;
	PwmHandler* shoulder;
	PwmHandler* elbow;
	PwmHandler* wrist;
	PwmHandler* wristRot;
	PwmHandler* claw;
};

enum class Joint : std::size_t {
    HIP, SHOULDER, ELBOW, WRIST, WRIST_ROT, CLAW
};

class RobotArm {
public:
    RobotArm(PwmHandlers* pwmHandlers);
    void setJoint(Joint joint, float angle);
    void update();

private:
    std::array<Servo, 6> servos_;
    std::array<float, 6> next_joint_pos_;
};
