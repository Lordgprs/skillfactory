#pragma once
#include "IElectronics.h"
#include <string>

class Appliances : virtual public IElectronics {	// Бытовая электроника
public:
	Appliances() = default;
	Appliances(const std::string &manufacturer, const std::string &model, unsigned weight);
	void ShowSpec() const override;
protected:
	unsigned _weight;
};