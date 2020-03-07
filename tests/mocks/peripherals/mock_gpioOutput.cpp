#include <peripherals/mock_gpioOutput.hpp>

void cGPIOOutput::init(Gpio_Port port,uint8_t pin){
    cGPIOOutput_mock.init(port,pin);
}

void cGPIOOutput::set(bool state){
    cGPIOOutput_mock.set(state);
}

bool cGPIOOutput::currentState(void){
    return cGPIOOutput_mock.currentState();
}
