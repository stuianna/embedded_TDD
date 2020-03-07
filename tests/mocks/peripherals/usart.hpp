#ifndef _USART_HPP
#define _USART_HPP

#include <stdint.h>
#include <trompeloeil.hpp>

class cUSART{

	public:
		MAKE_MOCK1(put,bool(uint8_t byte));
		MAKE_MOCK1(get,bool(uint8_t& byte));
};

#endif
