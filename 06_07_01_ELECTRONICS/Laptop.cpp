#include "Laptop.h"
#include <iostream>

Laptop::Laptop(const std::string &manufacturer, const std::string &model, const unsigned short batteryLife, const unsigned weight, 
	const double displaySize, const unsigned short ramSize, const unsigned short storageSize):
Device(manufacturer, model, batteryLife), 
_displaySize{ displaySize },
_ramSize{ ramSize },
_storageSize{ storageSize } {
	_weight = weight;
}

void Laptop::ShowSpec() const {
	std::cout << "Device, appliance type: Laptop" <<
		"\nModel name: " << _manufacturer << " " << _model <<
		"\nBattery life, h: " << _batteryLife <<
		"\nWeight, g: " << _weight <<
		"\nDisplay size, inches: " << _displaySize <<
		"\nRAM size, MB: " << _ramSize <<
		"\nStorage size, GB: " << _storageSize << std::endl;
}
