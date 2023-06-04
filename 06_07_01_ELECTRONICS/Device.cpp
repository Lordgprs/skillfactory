#include "Device.h"
#include <iostream>

Device::Device(const std::string &manufacturer, const std::string &model, const unsigned short batteryLife) :
	_batteryLife{ batteryLife } {
	_manufacturer = manufacturer;
	_model = model;
}
void Device::ShowSpec() const {
	std::cout << "Battery life, h: " << _batteryLife << std::endl;
}