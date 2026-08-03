#include "main.h"

#ifndef ALT_MAIN_H
#define ALT_MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
	TIM_HandleTypeDef* htim;
	uint8_t channel;
} TimerInit;

typedef struct {
	TimerInit hip;
	TimerInit shoulder;
	TimerInit elbow;
	TimerInit wrist;
	TimerInit wristRot;
	TimerInit claw;
} TimerInitList;

typedef struct {
	I2C_HandleTypeDef* hi2c;
} I2cInit;

typedef struct {
	TimerInitList timerInitList;
	I2cInit i2cInit;
} Params;

int alt_main(Params* params, __IO uint32_t* buttonState);

#ifdef __cplusplus
}
#endif

#endif
