#include "Game.h"

Game::Game()
{
	ship = nullptr;

	CustomVector<Ship*>* shipVector = new CustomVector<Ship*>();

	parser.parseCSVShips(*shipVector);

	for (size_t i = 0; i < shipVector->size(); i++)
	{
		cout << shipVector->at(i)->getType() << endl;
	}

	for (size_t i = 0; i < shipVector->size(); i++)
	{
		delete shipVector->at(i);
	}

	delete shipVector;

	cin.get();

	/*setState(new City());

	while (state != nullptr) {
		
		system("cls");
		
		cout << "Amount of gold: " << gold << endl;
		cout << "Hitpoints of ship: " << ship->getHitPoints() << "/" << ship->getDamagePoints() << endl;
		cout << "Cannons on ship: " << ship->cannonCount << "/" << ship->getCannonry() << endl;
		cout << "" << endl;

		state->processState(this);

		if (ship->isDead()) {
			cout << "GAME OVER" << endl;
			cout << "Your ship breaks in two and everything sinks to the bottom of the sea..." << endl;
			cout << "" << endl;
			cin.get();
		}
	}*/
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
