#include "Appliances.h"
#include "IElectronics.h"
#include <iostream>

Appliances::Appliances(const std::string &manufacturer, const std::string &model, const unsigned weight) : 
	_weight{ weight }
	 {
	_manufacturer = manufacturer;
	_model = model;
}
void Appliances::ShowSpec() const {
	std::cout << "Appliance model: " << _manufacturer << " " << _model <<
		"\nWeight, kg: " << _weight << std::endl;
}