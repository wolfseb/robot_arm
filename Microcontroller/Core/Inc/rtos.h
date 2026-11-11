#include "main.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#ifndef INC_RTOS_H_
#define INC_RTOS_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
	I2C_HandleTypeDef* i2c;
} ServoTaskParameters;

void vServoTask(void* pvParameters);

#ifdef __cplusplus
}
#endif

#endif /* INC_RTOS_H_ */
