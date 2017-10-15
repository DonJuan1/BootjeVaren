#pragma once

#include "Ship.h"
#include "HeavyCannon.h"

class Pirate
{
public:
	Pirate();
	Pirate(Ship* ship);
	~Pirate();

	Ship * getShip() const;
	void getHit(int damage) { ship->getHit(damage); };

private:
	Ship* ship;



};
