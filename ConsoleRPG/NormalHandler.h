#pragma once

#include "WindHandler.h"

class NormalHandler : public WindHandler
{
public:
	int getSailTurns(Ship &ship) override { return 1; };
	char* getWindName() override { return "normal"; };

private:

};