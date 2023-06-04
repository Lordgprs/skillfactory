#pragma once
#include "Device.h"
#include <string>

class Player : public Device {
public:
	Player() = default;
	Player(const std::string &manufacturer, const std::string &model, unsigned short batteryLife,
		unsigned short totalTracks);
	void ShowSpec() const override;
	void ShowTotalTracks() const;
private:
	unsigned short _totalTracks{ 100 };
};