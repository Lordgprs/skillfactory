#pragma once
#include "Appliances.h"
#include <string>

class WashingMachine final :
    public Appliances {
public:
  WashingMachine() = default;
  WashingMachine(const std::string &manufacturer, const std::string &model, unsigned weight, unsigned short maxLoad, unsigned short rpm);
  void ShowSpec() const override;
private:
  unsigned short _maxLoad{ 8000 };
  unsigned short _rpm{ 1000 };
};

