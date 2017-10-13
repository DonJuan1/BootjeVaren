
#include <stdlib.h>

#include "Game.h"



Game::Game()
{

	parser.parseCSV();


	// Csv objects to factories

	/*setState(new City());


	while (state != nullptr) {
		
		system("cls");
		

		cout << "Aantal goud: " << gold << endl;

		state->processState(this);
	}*/
}

Game::~Game()
{

}

void Game::setState(LocationState * s)
{
	state = s;
}

Ship* Game::getShip() const
{
	return ship;
}
