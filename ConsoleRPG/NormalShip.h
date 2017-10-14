#pragma once

#include "Ship.h"

class NormalShip : public Ship
{
public:
	NormalShip(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall) : Ship(pType, pPrice, pLoadSpace, pCannory, pDamagePoint, pIsSmall) {};

	int getBaseFlightChance() override { return 30; };
	int getModifierFlightChance() override { return 10; };

private:

};