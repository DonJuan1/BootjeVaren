#include "Game.h"

Game::Game()
{
	ReadCSVFiles();

	setState(new City());

	ship = shipFactory.getRandomShip(true);
	City* city = new City(cityFactory.getCityWithName("Roatan"));

	delete city;

	cin.get();

	//while (state != nullptr) {
	//	
	//	system("cls");
	//	
	//	cout << "Amount of gold: " << gold << endl;
	//	cout << "Hitpoints of ship: " << ship->getHitPoints() << "/" << ship->getDamagePoints() << endl;
	//	//cout << "Cannons on ship: " << ship->cannonCount << "/" << ship->getCannonry() << endl;
	//	cout << "" << endl;

	//	state->processState(this);

	//	if (ship->isDead()) {
	//		cout << "GAME OVER" << endl;
	//		cout << "Your ship breaks in two and everything sinks to the bottom of the sea..." << endl;
	//		cout << "" << endl;
	//		cin.get();
	//	}
	//}
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
