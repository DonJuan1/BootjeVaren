#pragma once

#include "Ship.h"

class NormalShip : public Ship
{
public:
	NormalShip(const char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall) : Ship(pType, pPrice, pLoadSpace, pCannory, pDamagePoint, pIsSmall) {};

	Ship* clone() const { return new NormalShip(*this); };
	int getBaseFlightChance() const override { return 30; };
	int getModifierFlightChance() const override { return 10; };

private:

};
