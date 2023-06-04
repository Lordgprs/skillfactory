#include "WashingMachine.h"
#include <iostream>

WashingMachine::WashingMachine(const std::string &manufacturer, const std::string &model, const unsigned weight, const unsigned short maxLoad, const unsigned short rpm):
	Appliances(manufacturer, model, weight),
	_maxLoad{ maxLoad },
	_rpm{ rpm } {}

void WashingMachine::ShowSpec() const {
	std::cout << "Appliance type: Washing machine" <<
		"\nModel name: " << _manufacturer << " " << _model <<
		"\nWeight, kg: " << _weight / 1000 <<
		"\nMaximum load, kg: " << _maxLoad <<
		"\nRotation speed, rpm: " << _rpm << std::endl;
}
