#include "City.h"
#include "Game.h"
#include "Sea.h"

City::City()
{

}

City::City(char* pName)
{
	strcpy(name, pName);
}

City::City(City& otherCity)
{
	if (this != &otherCity)
	{
		strcpy(name, otherCity.getName());

		goodsVector = otherCity.getGoodsVector();
		cityDestinationVector = otherCity.getCityDestinationVector();
	}
}

City::~City()
{
	
}

void City::processState(Game* game)
{
	for (int i = 0; i < goodsVector.size(); i++)
	{
		goodsVector.at(i).randomGoods();
	}

	while (true)
	{
		system("cls");

		game->getShip()->printStats();

		cout << endl;
		cout << "You are in the city " << name << endl;
		cout << "" << endl;
		cout << "1: Buy goods" << endl;
		cout << "2: Sell goods" << endl;
		cout << "3: Buy cannons" << endl;
		cout << "4: Sell cannons" << endl;
		cout << "5: Sail to next city" << endl;
		cout << "6: Repare ship" << endl;
		cout << "7: Quit" << endl;
		cout << "" << endl;
		cout << "Option: ";
		
		int choice = 0;
		cin >> choice;

		while (!cin && cin.fail())
		{
			cout << "No valid input! Option: ";
			std::cin.clear();
			std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> choice;
		}

		switch (choice)
		{
			case 1:
				buyGoods(game);
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				game->setState(new Sea(new City()));
				delete this;
				return;
			case 6:
				break;
			case 7:
				game->setState(nullptr);
				delete this;
				return;
		}
	}
}

void City::buyGoods(Game* game)
{
	while (true)
	{
		system("cls");

		game->getShip()->printStats();

		cout << "You are in the shop of " << name << endl;
		cout << endl;
		cout << "Here are the goods you can buy:" << endl;
		cout << endl;

		printf("%-2s %-12s %-12s %-12s\n", "#", "Name", "Price (G)", "Amount (Ton)");

		for (int i = 1; i < goodsVector.size() + 1; i++)
		{
			Goods& goods = goodsVector.at(i - 1);
			printf("%-2i %-12s %-12i %-12i\n", i, goods.getName(), goods.getPrice(), goods.getAmount());
		}

		cout << "" << endl;
		cout << "Select a number to select a product or 0 to quit the shop: ";

		int choice;
		cin >> choice;

		while (cin.fail())
		{
			cout << "No number selected! Select a number to select a product or 0 to quit the shop: ";
			std::cin.clear();
			std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> choice;
		}

		if (choice == 0)
		{
			return;
		}
		else if (choice > 0 && choice < goodsVector.size() + 1)
		{
			Goods& goods = goodsVector.at(choice - 1);
			
			while (true)
			{
				cout << "You selected: " << goods.getName() << ", selected the amount you want to buy: ";
				cin >> choice;

				while (cin.fail())
				{
					cout << "No number selected! Selected the amount you want to buy: ";
					std::cin.clear();
					std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> choice;
				}

				if (game->getShip()->getUnusedLoadSpace() > choice)
				{
					int totalPrice = choice * goods.getPrice();
					if (game->getShip()->getGold() > totalPrice)
					{
						game->getShip()->changeGold(-totalPrice);
						game->getShip()->addGoods(goods, choice);
						break;
					}
					else
					{
						cout << "The total price is too much" << endl;
					}
				}
				else
				{
					cout << "The amount is too much to carry" << endl;
				}
			}
		}
	}
}

