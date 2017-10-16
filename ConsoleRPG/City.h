#pragma once

#include "Game.h"
#include "LocationState.h"
#include "Sea.h"

class City : public LocationState
{
public:
	City() : name("Example") { } ;
	~City() {};

	void processState(Game* game) override;

private:
	char name[20];

};
