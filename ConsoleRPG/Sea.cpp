#include "Sea.h"

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

Sea::Sea(City* city)
{
	nextCity = city;
	turns = 5;
}

void Sea::processState(Game* game)
{

	if (turns <= 0) {
		game->setState(new City());
		delete this;
	}
	else if(!isInBattle){

		std::default_random_engine generator;
		generator.seed(time(0));
		std::uniform_int_distribution<int> distribution1(1, 20);
		
		int randomBattleChance = distribution1(generator);
		if (randomBattleChance <= 20 / (100 / 20)) {

			game->setState(new Battle(this));
			isInBattle = true;



		}



	}

	cout << "Your ship is on sea. Days left: "<< turns << endl;
	cout << "" << endl;
	cout << "0: Next day" << endl;
	cout << "1: Quit" << endl;

	int choice;
	cin >> choice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore char input

	if (choice == 1) {
		game->setState(nullptr);
		delete this;
	}

	turns--;

}
