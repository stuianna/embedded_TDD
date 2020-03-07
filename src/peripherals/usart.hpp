#ifndef _USART_HPP
#define _USART_HPP

#include <stdint.h>

class cUSART{

	public:
	cUSART();
	bool get(uint8_t& byte);
	bool put(uint8_t byte);

	private:
		void gpioInit();

};

#endif
