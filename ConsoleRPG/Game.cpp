#include "Game.h"
#include "Vector.h"

Game::Game()
{
	CSVParser parser;

	ship = nullptr;

	CustomVector<Ship>* shipVector = new CustomVector<Ship>();

	//CustomVector<City*>* cityVector = new CustomVector<City*>();

	parser.parseCSVShips(*shipVector);

	////parser.parseCSVCities(*cityVector);

	////cout << cityVector->at(4)->getGoodsVector().at(1).getMaxAmount() << endl;

	for (size_t i = 0; i < shipVector->size(); i++)
	{
		 cout << shipVector->at(i).getType() << " - " << shipVector->at(i).getPrice() << endl;;
	}

	cin.get();

	///*for (size_t i = 0; i < cityVector->size(); i++)
	//{
	//	delete cityVector->at(i);
	//}*/

	////cin.get();

	delete shipVector;

	//delete shipVector;
	//delete cityVector;

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
