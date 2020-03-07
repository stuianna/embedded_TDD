#include <utilities/string.hpp>

cString::cString(cUSART& publicInterface) :
	interface(publicInterface){}

bool cString::sendBuffer(uint8_t* buffer, uint8_t length){

	bool error = false;
	uint8_t pos = 0;
	while(length && !error){
		lastByteSent = buffer[pos++];
		error = interface.put(lastByteSent);
		length--;
	}
	return error;
}
