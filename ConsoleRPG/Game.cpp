
#include <stdlib.h>

#include "Game.h"
#include "CustomVector.h"

Game::Game()
{
	/*CustomVector vec;

	int temp;

	while (1)
	{
		cin >> temp;
		if (temp == 0)
		{
			break;
		}

		vec.push_back(temp);
	}

	cout << "You have entered " << vec.size() << " elements. These are:" << endl;

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	cout << endl;

	cin.clear();
	cin >> temp;*/


	ship = shipFactory.getRandomShip(true);
	
	//parser.parseCSV();
	

	setState(new City());


	while (state != nullptr) {
		
		system("cls");
		
		cout << "Amount of gold: " << gold << endl;
		cout << "Hitpoints of ship: " << ship->getHitPoints() << "/" << ship->getDamagePoints() << endl;
		cout << "Cannons of ship: " << ship->cannonCount << endl;
		cout << "" << endl;

		state->processState(this);

		if (ship->isDead()) {
			cout << "GAME OVER" << endl;
			cout << "Your ship breaks in two and everything sinks to the bottom of the sea..." << endl;
			cout << "" << endl;
			cin.get();
		}
	}
}

Game::~Game()
{
	//delete ship;
}

void Game::setState(LocationState * s)
{
	state = s;
}

Ship* Game::getShip() const
{
	return ship;
}
