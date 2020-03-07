#include <doctest.h>
#include <doctest/trompeloeil.hpp>
#include <utilities/led.hpp>
#include <peripherals/mock_gpioOutput.hpp>

using trompeloeil::_;
cGPIOOutput_Mock cGPIOOutput_mock;

TEST_CASE("Output functions for GPIO"){

	uint8_t pin = 0;
	uint8_t blinkCount;
	ALLOW_CALL(cGPIOOutput_mock,init(cLED::PORTA,pin));
	cLED::init(cLED::PORTA,pin);


	SUBCASE("Toggle function changes LED state"){
		ALLOW_CALL(cGPIOOutput_mock,currentState())
			.RETURN(false);
		ALLOW_CALL(cGPIOOutput_mock,set(true));
		cLED::toggle();
	}

	SUBCASE("Blink function sets state to off first."){
		ALLOW_CALL(cGPIOOutput_mock,set(_));
		REQUIRE_CALL(cGPIOOutput_mock,set(false));
		blinkCount = 1;
		cLED::blink(blinkCount);
	}

	SUBCASE("Setting a blinkCount of zero causes nothing to happen to GPIO state."){
		blinkCount = 0;
		FORBID_CALL(cGPIOOutput_mock,set(_));
		cLED::blink(blinkCount);
	}

	SUBCASE("GPIO is toggled as many times as passed blinkCount"){
		blinkCount = 2;
		REQUIRE_CALL(cGPIOOutput_mock,set(false))
			.TIMES(3);
		REQUIRE_CALL(cGPIOOutput_mock,set(true))
			.TIMES(2);
		cLED::blink(blinkCount);

	}

}
