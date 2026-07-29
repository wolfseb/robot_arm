#include "pwm_handler.hpp"

class MockPwmHandler : public PwmHandler
{
public:
    MockPwmHandler(){};
    void handle(uint16_t value) override
    {
        last_value = value;
    };

    uint16_t last_value;
};
