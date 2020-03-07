#ifndef _GPIOOUTPUT_MOCK_HPP
#define _GPIOOUTPUT_MOCK_HPP

#include <stdint.h>
#include <trompeloeil.hpp>
#include <peripherals/gpioOutput.hpp>

class cGPIOOutput_Mock{
	public:
		MAKE_MOCK2(init,void(cGPIOOutput::Gpio_Port port,uint8_t pin));
		MAKE_MOCK1(set,void(bool state));
		MAKE_MOCK0(currentState,bool(void));
};

extern cGPIOOutput_Mock cGPIOOutput_mock;

#endif
