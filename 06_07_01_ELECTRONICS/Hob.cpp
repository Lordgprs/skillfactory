#include "Hob.h"
#include <iostream>

Hob::Hob(const std::string manufacturer, const std::string &model, unsigned weight,
	const BurnerType type, const unsigned short burnerCount, const unsigned short wattage):
	Appliances(manufacturer, model, weight),
	_type{ type },
	_burnerCount{ burnerCount },
	_wattage{ wattage } {}

std::string Hob::getHobType() const {
	switch (_type) {
	case kGas:
		return "Gas";
	case kElectrical:
		return "Electrical";
	case kInduction:
		return "Induction";
	default:
		return "Unknown";
	}
}

void Hob::ShowSpec() const {
	std::cout << "Appliance type: Hob\nModel name: " << _manufacturer << " " << _model <<
		"\nHob weight, g: " << _weight <<
		"\nHob type: " << getHobType() <<
		"\nBurner count: " << _burnerCount <<
		"\nMaximum wattage, W: " << _wattage << std::endl;
}
