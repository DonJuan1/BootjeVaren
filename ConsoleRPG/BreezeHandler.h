#pragma once

#include "WindHandler.h"
#include "NormalHandler.h"
#include "LightShip.h"

class BreezeHandler : public WindHandler
{
public:
	int getSailTurns(Ship* ship) override { 
		if (dynamic_cast<LightShip*>(ship))
		{
			NormalHandler wind; 
			return wind.getSailTurns(ship);
		}
		else
		{
			NoneHandler wind;
			return wind.getSailTurns(ship);
		}
	};
	const char* getWindName() const override { return "breeze"; };

private:

};
