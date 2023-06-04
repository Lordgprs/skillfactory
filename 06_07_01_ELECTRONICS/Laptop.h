#pragma once
#include "Device.h"
#include "Appliances.h"
#include <string>

class Laptop final:
  public Device,
  public Appliances {
public:
  Laptop() = default;
  Laptop(const std::string &manufacturer, const std::string &model, unsigned short batteryLife, unsigned weight, 
    double displaySize, unsigned short ramSize, unsigned short storageSize);
  virtual void ShowSpec() const override;
private:
  double _displaySize;
  unsigned short _ramSize;
  unsigned short _storageSize;
};

