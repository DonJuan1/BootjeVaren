#pragma once

#include "WindHandler.h"

class NoneHandler : public WindHandler
{
public:
	int getSailTurns(Ship &ship) override { return 0; };
	char* getWindName() override { return "none"; };

private:

};