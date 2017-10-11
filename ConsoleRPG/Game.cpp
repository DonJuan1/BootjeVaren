#include "Game.h"


Game::Game()
{
	choice = 0;
	playing = true;

	parser.parseCSV();

	cin.get();

}

Game::~Game()
{

}

void Game::mainMenu()
{
	cout << "MAIN MENU" << endl << endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level up" << endl;
	cout << "0: Rest" << endl;

	cout << endl << "Choice: " ;

	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore char input

	switch (choice)
	{
		case 0:
			playing = false;
			break;
		default:
			break;
	}
}

bool Game::getPlaying() const
{
	return this->playing;
}
