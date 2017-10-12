#include "Sea.h"

Sea::Sea()
{
	turns = 5;
}

void Sea::processState(Game* game)
{

	cout << "Het schip bevind zich op zee. Het is beurt "<< turns << endl;
	cout << "Volgende beurt?" << endl;

	int choice;
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore char input

	turns--;

	if (turns <= 0) {
		game->setState(game->nextCity);
		game->nextCity = nullptr;
		delete this;
	}

}
