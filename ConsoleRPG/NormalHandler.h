#pragma once

#include "WindHandler.h"

class NormalHandler : public WindHandler
{
public:
	int getSailTurns(Ship* ship) override { return 1; };
	const char* getWindName() const override { return "normal"; };

private:

};
