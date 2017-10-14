#pragma once

#include "Ship.h"

class LogShip : public Ship
{
public:
	LogShip(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall) : Ship(pType, pPrice, pLoadSpace, pCannory, pDamagePoint, pIsSmall) {};

	int getBaseFlightChance() override { return 5; };
	int getModifierFlightChance() override { return 15; };

private:

};