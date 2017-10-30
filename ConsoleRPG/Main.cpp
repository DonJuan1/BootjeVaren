#include <iostream>

#include "Main.h"
#include "Game.h"

int main()
{
	const Game* game = nullptr;

	try
	{
		game = new Game();
	}
	catch (...)
	{
		cout << "An unknown error has occurred!";
		cin.get();
	}
	
	delete game;

	return _CrtDumpMemoryLeaks();
}
