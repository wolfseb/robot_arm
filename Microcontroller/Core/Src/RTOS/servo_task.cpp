#include "rtos.h"

#include "pca9685_pwm_handler.hpp"
#include "pca9685_pwm_configs.hpp"
#include "robot_arm.hpp"

void vServoTask(void* pvParameters) {
    ServoTaskParameters* pParams = (ServoTaskParameters*) pvParameters;
    PCA9685_PwmHandler pwmHandler(pParams->i2c);
    
	std::array<ServoConfig, JointCount> servoConfigs = {
			PCA9685_ServoConfigs::hip,
			PCA9685_ServoConfigs::shoulder,
			PCA9685_ServoConfigs::elbow,
			PCA9685_ServoConfigs::wrist,
			PCA9685_ServoConfigs::wristRot,
			PCA9685_ServoConfigs::claw
	};
	RobotArm robot(&pwmHandler, &servoConfigs);

	std::array<float, JointCount> pos1 = { 0, 0, 0, 0, 0, 75 };
	std::array<float, JointCount> pos2 = { -60, 30, -60, -60, 0, 40 };
	std::array<float, JointCount>* pos = &pos1;
	bool pos_toggle = false;

	for (;;) {
        vTaskDelay(2000);
        
        if (pos_toggle) {
            pos = &pos2;
        } else {
            pos = &pos1;
        }
        pos_toggle = !pos_toggle;

        robot.setJoints(pos);
        robot.update();
	}
}
