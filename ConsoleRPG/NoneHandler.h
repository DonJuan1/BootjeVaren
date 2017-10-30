#pragma once

#include "WindHandler.h"

class NoneHandler : public WindHandler
{
public:
	int getSailTurns(Ship* ship) override { return 0; };
	const char* getWindName() const override { return "none"; };

private:

};
