#pragma once

#include "WindHandler.h"

class StrongHandler : public WindHandler
{
public:
	int getSailTurns(Ship* ship) override { return 2; };
	const char* getWindName() const override { return "strong"; };

private:

};
