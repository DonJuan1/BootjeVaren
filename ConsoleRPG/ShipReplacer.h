#pragma once
#include "Ship.h"

class ShipReplacer
{
public:
	ShipReplacer(Ship* newShip, Ship* oldShip);
	~ShipReplacer();

	inline Ship* getNewShip() const { return newShip; }
	inline void clearReplacer() { newShip = nullptr;}

private:
	Ship* newShip;
};

