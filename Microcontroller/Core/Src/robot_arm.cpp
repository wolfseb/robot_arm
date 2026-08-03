#include "robot_arm.hpp"

RobotArm::RobotArm(PwmHandler* pwmHandler, std::array<ServoConfig, JointCount>* servoConfigs) :
	servos_{
		Servo(&(*servoConfigs)[0]),
		Servo(&(*servoConfigs)[1]),
		Servo(&(*servoConfigs)[2]),
		Servo(&(*servoConfigs)[3]),
		Servo(&(*servoConfigs)[4]),
		Servo(&(*servoConfigs)[5])
	},
	next_joint_pos_{
		0, 0, 0, 0, 0, 40
	},
	pwmHandler_{pwmHandler}
{
	this->update();
};

void RobotArm::setJoint(Joint joint, float angle)
{
	this->next_joint_pos_[toIndex(joint)] = angle;
};

void RobotArm::setJoints(std::array<float, JointCount>* angles)
{
	this->next_joint_pos_ = *angles;
}

void RobotArm::update()
{
	this->pwmHandler_->handle(&servos_, &next_joint_pos_);
};
