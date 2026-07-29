#include "alt_main.h"
#include "pwm_handler.hpp"

class Stm32PwmHandler : public PwmHandler
{
public:
	Stm32PwmHandler(TimerInit* timer) : timer_(timer){}

	void handle(uint16_t pwm) override
	{
		__HAL_TIM_SET_COMPARE(timer_->htim, timer_->channel, pwm);
	};

private:
	TimerInit* timer_;
};
