#include "alt_main.h"
#include "pwm_handler.hpp"

class PCA9685_PwmHandler : public PwmHandler
{
public:
	PCA9685_PwmHandler(I2C_HandleTypeDef* i2c) : i2c_(i2c){
		// set SLEEP mode to set prescale
		uint8_t data[] = {
				0x00,
				0b00010001
		};
		HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(
				i2c_,
				addr_ << 1,
				data,
				sizeof(data),
				HAL_MAX_DELAY
		);
		if (status != HAL_OK)
		{
		    Error_Handler();
		}
		HAL_Delay(1);

		uint8_t data_prescale[] = {
			0xFE,	// prescale register
			0x1D ,	// 30-1
		};
		status = HAL_I2C_Master_Transmit(
				i2c_,
				addr_ << 1,
				data_prescale,
				sizeof(data_prescale),
				HAL_MAX_DELAY
		);
		if (status != HAL_OK)
		{
		    Error_Handler();
		}
		HAL_Delay(1);


		// Set pca to MODE1, AutoIncrement enabled, SLEEP normal mode
		uint8_t data2[] = {
				0x00,	// Mode register 1
				0b00100001
				//  ^^   ^
				//  ||   allcall enable
				//  |SLEEP normal mode
				//  AI (auto increment) enable
		};
		status = HAL_I2C_Master_Transmit(
				i2c_,
				addr_ << 1,
				data2,
				sizeof(data2),
				HAL_MAX_DELAY
		);
		if (status != HAL_OK)
		{
		    Error_Handler();
		}
		HAL_Delay(1);

		uint8_t resp;
		status = HAL_I2C_Mem_Read(
				i2c_,
				addr_ << 1,
				0xFE,
				I2C_MEMADD_SIZE_8BIT,
				&resp,
				1,
				HAL_MAX_DELAY
		);
		if (status != HAL_OK || resp != 29)
		{
		    Error_Handler();
		}
	}


	void handle(std::array<Servo, JointCount>* servos, std::array<float, JointCount>* pos) override
	{
		std::array<std::array<uint8_t, 2>, JointCount> pwm = {
				uint16_to_2uint8_((*servos)[0].angle_to_pwm((*pos)[0])),
				uint16_to_2uint8_((*servos)[1].angle_to_pwm((*pos)[1])),
				uint16_to_2uint8_((*servos)[2].angle_to_pwm((*pos)[2])),
				uint16_to_2uint8_((*servos)[3].angle_to_pwm((*pos)[3])),
				uint16_to_2uint8_((*servos)[4].angle_to_pwm((*pos)[4])),
				uint16_to_2uint8_((*servos)[5].angle_to_pwm((*pos)[5])),
		};

		uint8_t data[] = {
				0x06,	// first servo address (hip)
			 // High L, High H, Low L,     Low H
				// hip
				0x00,   0x00,   pwm[0][0], pwm[0][1],
				// shoulder
				0x00,   0x00,   pwm[1][0], pwm[1][1],
				// elbow
				0x00,   0x00,   pwm[2][0], pwm[2][1],
				// wrist
				0x00,   0x00,   pwm[3][0], pwm[3][1],
				// wristRot
				0x00,   0x00,   pwm[4][0], pwm[4][1],
				// claw
				0x00,   0x00,   pwm[5][0], pwm[5][1],
		};

		HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(
				i2c_,
				addr_ << 1,
				data,
				sizeof(data),
				HAL_MAX_DELAY
		);
		if (status != HAL_OK)
		{
			Error_Handler();
		}
	};

private:
	I2C_HandleTypeDef* i2c_;
	const uint8_t addr_ = 0x40;

	std::array<uint8_t, 2> uint16_to_2uint8_(uint16_t data)
	{
		return std::array<uint8_t, 2>{
				static_cast<uint8_t>(data & 0xFF),			// low byte
				static_cast<uint8_t>((data >> 8) & 0xFF)	// high byte
		};
	}
};
