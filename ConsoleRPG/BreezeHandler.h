#pragma once

#include "WindHandler.h"
#include "NormalHandler.h"
#include "LightShip.h"

class BreezeHandler : public WindHandler
{
public:
	int getSailTurns(Ship &ship) override { NoneHandler wind; return wind.getSailTurns(ship); };
	int getSailTurns(LightShip &ship) { NormalHandler wind; return wind.getSailTurns(ship); };
	char* getWindName() override { return "breeze"; };

private:

};