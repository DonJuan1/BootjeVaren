#pragma once

class Game;

class LocationState
{
public:
	LocationState() {};
	virtual ~LocationState() {};

	virtual void processState(Game* game) = 0;

private:


protected:
	char buf[128] = { 0 };

};
