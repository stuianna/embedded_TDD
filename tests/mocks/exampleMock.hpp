#ifndef _EXAMPLE_MOCK_HPP
#define _EXAMPLE_MOCK_HPP

#include <stdint.h>
#include <trompeloeil.hpp>

class cMock{

	public:
		MAKE_MOCK1(example,bool(int in));
};

#endif
