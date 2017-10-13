
#include <stdlib.h>

#include "Game.h"
#include <ctime>



Game::Game()
{

	parser.parseCSV();

	std::default_random_engine generator;
	generator.seed(time(0));

	ship = new Ship();
	ship->addCannon(new HeavyCannon(generator));
	ship->addCannon(new HeavyCannon(generator));
	


	// Csv objects to factories

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
