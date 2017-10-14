#pragma once

#include "Ship.h"

class WindHandler
{
public:
	virtual int getSailTurns(Ship &ship) = 0;
	virtual char* getWindName() = 0;

private:

};