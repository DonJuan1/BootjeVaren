#pragma once

#include "WindHandler.h"
#include "LogShip.h"

class WeakHandler : public WindHandler
{
public:
	int getSailTurns(Ship &ship) override { NormalHandler wind; return wind.getSailTurns(ship); };
	int getSailTurns(LogShip &ship) { NoneHandler wind; return wind.getSailTurns(ship); };
	char* getWindName() override { return "weak"; };

private:

};