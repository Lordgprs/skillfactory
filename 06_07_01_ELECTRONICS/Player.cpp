#include "Player.h"
#include <iostream>

Player::Player(const std::string &manufacturer, const std::string &model, const unsigned short batteryLife,
	const unsigned short totalTracks) :
	Device(manufacturer, model, batteryLife),
	_totalTracks{ totalTracks } {}
void Player::ShowSpec() const {
	std::cout << "Device type: Player" <<
		"\nModel name: " << _manufacturer << " " << _model <<
		"\nBattery life, h: " << _batteryLife <<
		"\nTracks count: " << _totalTracks << std::endl;
}
void Player::ShowTotalTracks() const {
	std::cout << "Total tracks: " << _totalTracks << std::endl;
}