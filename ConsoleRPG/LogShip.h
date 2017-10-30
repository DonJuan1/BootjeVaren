#pragma once

#include "Ship.h"

class LogShip : public Ship
{
public:
	LogShip(const char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall) : Ship(pType, pPrice, pLoadSpace, pCannory, pDamagePoint, pIsSmall) {};

	Ship* clone() const { return new LogShip(*this); };
	int getBaseFlightChance() const override { return 5; };
	int getModifierFlightChance() const override { return 25; };

private:

};
