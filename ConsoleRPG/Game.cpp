
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


	//parser.parseCSV();

	/*ship = new Ship("ship",20,20,20,100,false);
	ship->addCannon(new HeavyCannon());
	ship->addCannon(new HeavyCannon());
	

	setState(new City());


	while (state != nullptr) {
		
		system("cls");
		

		cout << "Aantal goud: " << gold << endl;

		state->processState(this);
	}*/
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
