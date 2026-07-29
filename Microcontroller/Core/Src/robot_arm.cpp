#include "robot_arm.hpp"
#include "servo_configs.hpp"


RobotArm::RobotArm(PwmHandlers* pwmHandlers) :
	servos_{
		Servo(&ServoConfigs::hip, pwmHandlers->hip),
		Servo(&ServoConfigs::shoulder, pwmHandlers->shoulder),
		Servo(&ServoConfigs::elbow, pwmHandlers->elbow),
		Servo(&ServoConfigs::wrist, pwmHandlers->wrist),
		Servo(&ServoConfigs::wristRot, pwmHandlers->wristRot),
		Servo(&ServoConfigs::claw, pwmHandlers->claw)
	},
	next_joint_pos_{
		0, 0, 0, 0, 0, 40
//		1560, 1480, 1450, 1400, 1450, 1450
	}
{
	this->update();
};

void RobotArm::setJoint(Joint joint, float angle)
{
	this->next_joint_pos_[static_cast<std::size_t>(joint)] = angle;
};

void RobotArm::update()
{
	for (int i = 0; i < 6; i++)
	{
		this->servos_[i].move(next_joint_pos_[i]);
	}
};
