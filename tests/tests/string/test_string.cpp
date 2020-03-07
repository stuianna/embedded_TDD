#include <doctest.h>
#include <doctest/trompeloeil.hpp>
#include <peripherals/usart.hpp>
#include <utilities/string.hpp>

using trompeloeil::_;

TEST_CASE("Send buffer through USART operation."){

	cUSART usart;
	cString string(usart);
	uint8_t buffer[] = "Test";
	bool error;

	SUBCASE("Send a string in the correct sequence"){
			trompeloeil::sequence seq;

			REQUIRE_CALL(usart,put('T'))
				.IN_SEQUENCE(seq)
				.RETURN(false);
			REQUIRE_CALL(usart,put('e'))
				.IN_SEQUENCE(seq)
				.RETURN(false);
			REQUIRE_CALL(usart,put('s'))
				.IN_SEQUENCE(seq)
				.RETURN(false);
			REQUIRE_CALL(usart,put('t'))
				.IN_SEQUENCE(seq)
				.RETURN(false);
			REQUIRE_CALL(usart,put(0))
				.IN_SEQUENCE(seq)
				.RETURN(false);
			error = string.sendBuffer(buffer,sizeof(buffer)/sizeof(uint8_t));
			CHECK(error == false);
	}
	SUBCASE("USART error causes sending to be terminated"){

			trompeloeil::sequence seq;

			REQUIRE_CALL(usart,put('T'))
				.IN_SEQUENCE(seq)
				.RETURN(false);
			REQUIRE_CALL(usart,put('e'))
				.IN_SEQUENCE(seq)
				.RETURN(true);
			error = string.sendBuffer(buffer,sizeof(buffer)/sizeof(uint8_t));
			CHECK(error == true);
	}
}
