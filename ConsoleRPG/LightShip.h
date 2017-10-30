#pragma once

#include "Ship.h"

class LightShip : public Ship
{
public:
	LightShip(const char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall) : Ship(pType, pPrice, pLoadSpace, pCannory, pDamagePoint, pIsSmall) {};

	Ship* clone() const { return new LightShip(*this); };
	int getBaseFlightChance() const override { return 50; };
	int getModifierFlightChance() const override { return 0; };

private:

};
