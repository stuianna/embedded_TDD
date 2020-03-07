#ifndef __GPIOOUTPUT_HPP
#define __GPIOOUTPUT_HPP

#include <stdint.h>

class cGPIOOutput{
	public:
		enum Gpio_Port{PORTA,PORTB,PORTC,PORTD};

	static void init(Gpio_Port port, uint8_t pin);
	static void set(bool state);
	static bool currentState(void);

	private:
		static bool _currentState;
		static Gpio_Port _port;
		static uint8_t _pin;
};


#endif
