#include "main.h"
#include "pwm_handler.hpp"

#pragma once

class PCA9685_PwmHandler : public PwmHandler {
public:
	PCA9685_PwmHandler(I2C_HandleTypeDef* i2c);
    void handle(std::array<Servo, JointCount>* servos, std::array<float, JointCount>* pos) override;

private:
	I2C_HandleTypeDef* i2c_;
	const uint8_t addr_;
	std::array<uint8_t, 2> uint16_to_2uint8_(uint16_t data);
};
