#ifndef _LED_HPP
#define _LED_HPP
#include <peripherals/gpioOutput.hpp>

class cLED : public cGPIOOutput{
	public:
		static void toggle();
		static void blink(uint8_t times, uint16_t highTimeMs = 100, uint16_t lowTimeMs = 100);
};

#endif
