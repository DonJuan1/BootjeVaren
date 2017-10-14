#include <iostream>

#include "Main.h"
#include "Game.h"

int main()
{
	Game* game = new Game();
	delete game;

	return _CrtDumpMemoryLeaks();
}
