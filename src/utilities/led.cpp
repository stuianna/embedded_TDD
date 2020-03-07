#include <utilities/led.hpp>

void cLED::toggle(){
	cGPIOOutput::set(!cGPIOOutput::currentState());
}

void cLED::blink(uint8_t times, uint16_t highTimeMs, uint16_t lowTimeMs){

	if(!times){
		return;
	}
	cGPIOOutput::set(false);
	for(uint8_t i = 0; i < times; i++){
		cGPIOOutput::set(true);
		cGPIOOutput::set(false);
	}
	(void)highTimeMs;
	(void)lowTimeMs;
}
