#include <cstdint>

#pragma once

class PwmHandler
{
public:
	virtual void handle(uint16_t value) = 0;
	virtual ~PwmHandler() = default;
};
