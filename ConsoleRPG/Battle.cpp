#include "Battle.h"

Battle::Battle(Sea * sea)
{
	seaState = sea;
}

void Battle::processState(Game * game)
{

	cout << "You are in battle with a pirate." << endl;
	cout << "The pirate says arrr to you." << endl;
	cout << "" << endl;
	cout << "0: Shoot" << endl;
	cout << "1: Flight" << endl;
	cout << "2: Surrender" << endl;
	cout << "3: Quit" << endl;
	cout << "" << endl;

	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (choice) {
	case 0:
		cout << game->getShip()->shootCannons();
		cin >> choice;

		break;
	case 1:


		break;
	case 2:


		game->setState(seaState);
		delete this;
		break;
	case 3:
		game->setState(nullptr);
		delete this;
		break;
	default:
		cout << "This is not a valid command.";
		break;
	}

	game->setState(seaState);
	delete this;

}

