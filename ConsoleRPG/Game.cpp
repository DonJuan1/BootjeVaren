#include "Game.h"

Game::Game()
{
	parser = new CSVParser();

	ship = nullptr;

	CustomVector<Ship*>* shipVector = new CustomVector<Ship*>();
	CustomVector<City*>* cityVector = new CustomVector<City*>();

	parser->parseCSVCities(*cityVector);

	cout << cityVector->at(4)->getGoodsVector().at(1).getMaxAmount() << endl;

	for (size_t i = 0; i < cityVector->size(); i++)
	{
		delete cityVector->at(i);
	}

	delete shipVector;
	delete cityVector;
	
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
	delete parser;
}

void Game::setState(LocationState * s)
{
	state = s;
}

Ship* Game::getShip() const
{
	return ship;
}
