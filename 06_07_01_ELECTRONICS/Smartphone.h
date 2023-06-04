#pragma once
#include "Device.h"
#include <string>

enum OperatingSystem {
  kAndroid,
  kiOS,
  kBlackberry
};

class Smartphone final: public Device {
public:
  Smartphone(const std::string &manufacturer, const std::string &model, unsigned short batteryLife, OperatingSystem os, unsigned short ramSize, unsigned short storageSize);
  void ShowSpec() const override;
  std::string getOs() const;
private:
  OperatingSystem _os{ kAndroid };
  unsigned short _ramSize{ 2 };       // RAM size, GB
  unsigned short _storageSize{ 64 };  // Storage (NAND) size, GB
};

