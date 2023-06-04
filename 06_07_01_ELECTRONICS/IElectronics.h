#pragma once
#include <string>

class IElectronics {
public:
	virtual void ShowSpec() const = 0;
	virtual ~IElectronics() = default;
protected:
	std::string _manufacturer;
	std::string _model;
};