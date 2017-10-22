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
				break;
			case 2:
				sellGoods(game);
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

				if (choice == 0)
				{
					break;
				}

				if (goods.getAmount() >= choice)
				{
					if (game->getShip()->getUnusedLoadSpace() > choice)
					{
						int totalPrice = choice * goods.getPrice();
						if (game->getShip()->getGold() > totalPrice)
						{
							goods.setAmount(goods.getAmount() - choice);
							game->getShip()->changeGold(-totalPrice);
							game->getShip()->addGoods(goods, choice);
							break;
						}
						else
						{
							cout << "You dont have that much cash, you poor bastard!" << endl;
						}
					}
					else
					{
						cout << "Your ship cannot carry that many goods!" << endl;
					}
				}
				else
				{
					cout << "Whooo, we dont have that many! " << goods.getName() <<  endl;
				}
				
			}
		}
	}
}

void City::sellGoods(Game* game)
{
	while (true)
	{
		system("cls");

		game->getShip()->printStats();

		cout << "You are in the shop of " << name << endl;
		cout << endl;
		cout << "Here are the goods you can sell:" << endl;
		cout << endl;

		printf("%-2s %-12s %-12s %-12s\n", "#", "Name", "Price (G)", "Amount (Ton)");

		for (int i = 1; i < game->getShip()->getGoodsOnShip().size() + 1; i++)
		{
			Goods& goods = game->getShip()->getGoodsOnShip().at(i - 1);

			for (int i = 0; i < goodsVector.size(); i++)
			{
				if (strcmp(goods.getName(), goodsVector.at(i).getName()) == 0)
				{
					goods.setPrice(goodsVector.at(i).getPrice());
				}
			}
			
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
		else if (choice > 0 && choice <  game->getShip()->getGoodsOnShip().size() + 1)
		{
			Goods& goods = game->getShip()->getGoodsOnShip().at(choice - 1);

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

				if (choice == 0)
				{
					break;
				}

				if (goods.getAmount() >= choice)
				{
					int totalPrice = choice * goods.getPrice();
					
					for (int i = 0; i < goodsVector.size(); i++)
					{
						if (strcmp(goods.getName(), goodsVector.at(i).getName()) == 0)
						{
							goodsVector.at(i).setAmount(goodsVector.at(i).getAmount() + choice);
						}
					}

					game->getShip()->changeGold(totalPrice);
					game->getShip()->deleteGoods(goods, choice);
					
					break;
				}
				else
				{
					cout << "Whooo, you dont have that many! " << goods.getName() << endl;
				}
			}
		}
	}
}

