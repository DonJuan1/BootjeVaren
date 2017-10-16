#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Game.h"
#include "LocationState.h"
#include "Sea.h"
#include "goods.h"

class Game;

class City : public LocationState
{
public:
	City() {};
	City(char* pName) { strcpy(name, pName); };
	~City() {};

	void processState(Game* game) override;
	char* getName() { return name; };

private:
	char name[32];

	
};
