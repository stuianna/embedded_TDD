#include <peripherals/gpioOutput.hpp>
#include <stm32f7xx.h>

bool cGPIOOutput::_currentState = false;
cGPIOOutput::Gpio_Port cGPIOOutput::_port = PORTA;
uint8_t cGPIOOutput::_pin = 0;

static GPIO_TypeDef* translatePort(cGPIOOutput::Gpio_Port port);
static void enableCorrectClock(cGPIOOutput::Gpio_Port port);

void cGPIOOutput::init(Gpio_Port port,uint8_t pin){
	_port = port;
	_pin = pin;

	enableCorrectClock(port);
	MODIFY_REG(translatePort(port)->MODER,0x3 << (pin*2),0x1 << (pin*2));
	SET_BIT(translatePort(port)->BSRR,0x1 << (pin + 16));
}

void cGPIOOutput::set(bool state){
	SET_BIT(translatePort(_port)->BSRR,1 << (state ? _pin : _pin + 16));
	_currentState = state;
}

bool cGPIOOutput::currentState(){
	return _currentState;
}

GPIO_TypeDef* translatePort(cGPIOOutput::Gpio_Port port){
	switch(port){
		case cGPIOOutput::PORTA: return GPIOA;
		case cGPIOOutput::PORTB: return GPIOB;
		case cGPIOOutput::PORTC: return GPIOC;
		case cGPIOOutput::PORTD: return GPIOD;
	}
	return GPIOA;
}

void enableCorrectClock(cGPIOOutput::Gpio_Port port){
	switch(port){
		default:
		case cGPIOOutput::PORTA: SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN); break;
		case cGPIOOutput::PORTB: SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN); break;
		case cGPIOOutput::PORTC: SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN); break;
		case cGPIOOutput::PORTD: SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN); break;
	}
}
