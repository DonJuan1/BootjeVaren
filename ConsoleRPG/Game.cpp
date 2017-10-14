
#include <stdlib.h>

#include "Game.h"



Game::Game()
{

	//parser.parseCSV();

	


	ship = new Ship("ship",20,20,20,100,false);
	ship->addCannon(new HeavyCannon());
	ship->addCannon(new HeavyCannon());
	

	setState(new City());


	while (state != nullptr) {
		
		system("cls");
		

		cout << "Aantal goud: " << gold << endl;

		state->processState(this);
	}
}

Game::~Game()
{
	delete ship;
}

void Game::setState(LocationState * s)
{
	state = s;
}

Ship* Game::getShip() const
{
	return ship;
}
