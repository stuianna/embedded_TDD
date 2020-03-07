#include <peripherals/usart.hpp>
#include <utilities/string.hpp>
#include <utilities/led.hpp>

#define MESSAGE "I am a message\n"

int main(void){

	uint8_t byte;
	cUSART uart;
	cLED::init(cLED::PORTB,7);
	cString stream(uart);
	while(1){
			if(!uart.get(byte)){
				uart.put(byte);
			}else{
				for(volatile int i = 0; i < 0x17FFF; i++);
				cLED::toggle();
				stream.sendBuffer((uint8_t*)MESSAGE,sizeof(MESSAGE)/sizeof(uint8_t)-1);
				cLED::toggle();
			}
	}
}
