#include <peripherals/usart.hpp>
#include <utilities/string.hpp>

#define MESSAGE "I am a message\n"

int main(void){

	uint8_t byte;
	cUSART uart;
	cString stream(uart);
	while(1){
			if(!uart.get(byte)){
				uart.put(byte);
			}else{
				for(volatile int i = 0; i < 0x17FFF; i++);
				stream.sendBuffer((uint8_t*)MESSAGE,sizeof(MESSAGE)/sizeof(uint8_t)-1);
			}
	}
}
