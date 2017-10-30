#pragma once

#include "WindHandler.h"
#include "LogShip.h"

class WeakHandler : public WindHandler
{
public:
	int getSailTurns(Ship* ship) override 
	{ 
		if (dynamic_cast<LogShip*>(ship))
		{
			NoneHandler wind;
			return wind.getSailTurns(ship);
		}
		else
		{
			NormalHandler wind;
			return wind.getSailTurns(ship);
		}
	};
	const char* getWindName() const override { return "weak"; };

private:

};
