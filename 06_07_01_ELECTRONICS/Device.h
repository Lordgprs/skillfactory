#pragma once
#include "IElectronics.h"
#include <string>

class Device : virtual public IElectronics {	// Портативная электроника
public:
	Device() = default;
	Device(const std::string &manufacturer, const std::string &model, unsigned short batteryLife);
	void ShowSpec() const override;
protected:
	unsigned short _batteryLife;
};