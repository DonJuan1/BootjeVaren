#pragma once

#include "WindHandler.h"

class StormHandler : public WindHandler
{
public:
	int getSailTurns(Ship* ship) override;
	const char* getWindName() const override { return "storm"; };

private:

};
