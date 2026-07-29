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
	TimerInit timerInit[6];

} Params;

int alt_main(Params* params, __IO uint32_t* buttonState);

#ifdef __cplusplus
}
#endif

#endif
