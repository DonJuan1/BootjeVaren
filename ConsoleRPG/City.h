#pragma once

#include "Game.h"
#include "LocationState.h"
#include "Sea.h"

class City : public LocationState
{
public:
	City() {};
	~City() {};

	void processState(Game* game) override;

private:
	char name[20] = "ExampleCity";


};