#include <array>

#include "servo.hpp"
#include "pwm_handler.hpp"
#include "robot_arm_joints.hpp"

#pragma once

class RobotArm {
public:
    RobotArm(PwmHandler* pwmHandler, std::array<ServoConfig, JointCount>* servoConfigs);
    void setJoint(Joint joint, float angle);
    void setJoints(std::array<float, JointCount>* angles);
    void update();

private:
    std::array<Servo, JointCount> servos_;
    std::array<float, JointCount> next_joint_pos_;
    PwmHandler* pwmHandler_;
};
