#include "Smartphone.h"
#include <iostream>

Smartphone::Smartphone(const std::string &manufacturer, const std::string &model, const unsigned short batteryLife, 
  const OperatingSystem os, const unsigned short ramSize, const unsigned short storageSize) :
  Device(manufacturer, model, batteryLife),
  _os{ os },
  _ramSize{ ramSize },
  _storageSize{ storageSize } {}

void Smartphone::ShowSpec() const {
  std::cout << "Device type: Smartphone\nOS: " << getOs() <<
    "\nModel name: " << _manufacturer << " " << _model <<
    "\nRAM size, MB: " << _ramSize <<
    "\nStorage size, GB: " << _storageSize << std::endl;
}

std::string Smartphone::getOs() const {
  switch (_os) {
  case kAndroid:
    return "Android";
  case kiOS:
    return "iOS";
  case kBlackberry:
    return "Blackberry";
  default:
    return "Unknown";
  }
}
