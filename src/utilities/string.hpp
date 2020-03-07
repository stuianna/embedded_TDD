#ifndef _STRING_HPP
#define _STRING_HPP
#include <stdint.h>
#include <peripherals/usart.hpp>

class cString{

	public:
		cString(cUSART& publicInterface);
		bool sendBuffer(uint8_t* buffer, uint8_t length);

	private:
		uint8_t lastByteSent;
		cUSART& interface;
};


#endif
