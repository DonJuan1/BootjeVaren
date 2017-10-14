#pragma once

#include "Ship.h"

class LightShip : public Ship
{
public:
	LightShip(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall) : Ship(pType, pPrice, pLoadSpace, pCannory, pDamagePoint, pIsSmall) {};

	int getBaseFlightChance() override { return 50; };
	int getModifierFlightChance() override { return 0; };

private:

};