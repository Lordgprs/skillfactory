#pragma once
#include "Appliances.h"
#include <string>

enum BurnerType {
  kGas,
  kElectrical,
  kInduction
};
class Hob final: public Appliances {
public:
  Hob(const std::string manufacturer, const std::string &model, unsigned weight,
    BurnerType type, unsigned short burnerCount, unsigned short wattage);
  std::string getHobType() const;
  void ShowSpec() const override;
private:
  BurnerType _type{ kElectrical };  // Burner type
  unsigned short _burnerCount{ 2 }; // Burner count
  unsigned short _wattage{ 6000 };  // Maximum wattage
};

