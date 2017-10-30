#pragma once

#include "Ship.h"

class WindHandler
{
public:
	virtual int getSailTurns(Ship* ship) = 0;
	virtual const char* getWindName() const = 0;

private:

};
