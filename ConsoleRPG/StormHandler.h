#pragma once

#include "WindHandler.h"

class StormHandler : public WindHandler
{
public:
	int getSailTurns(Ship &ship) override;
	char* getWindName() override { return "storm"; };

private:

};