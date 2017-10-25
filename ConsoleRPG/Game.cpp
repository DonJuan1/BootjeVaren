#include "Game.h"

Game::Game()
{
	ReadCSVFiles();

	ship = new Ship(shipFactory.getShipWithType("Pinnace"));
	ship->changeGold(100000);

	state = new City(cityFactory.getCityWithName("Roatan"));
	
	while (state != nullptr) {
		
		state->processState(this);

		if (ship->isDead()) {

			system("cls");

			ship->printStats();

			cout << endl;
			cout << "GAME OVER" << endl;
			cout << "Your ship breaks in two and everything sinks to the bottom of the sea..." << endl;
			cout << endl;
			cin.get();
			return;
		}
	}
}

Game::~Game()
{
	delete ship;
	delete state;
}

void Game::setState(LocationState * s)
{
	state = s;
}

Ship* Game::getShip() const
{
	return ship;
}

void Game::ReadCSVFiles() {
	CSVParser parser;

	parser.parseCSVShips(shipFactory.getShipVector());
	parser.parseCSVCities(cityFactory.getCityVector());
}
