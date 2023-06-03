#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <ctime>

using namespace std;

struct item
{
	string name;
	int gold;
};

// Ex 3-1
item* generateItem(item* list)
{
	int selected = rand() % 5;
	return list + selected;
}

void printObtained(item* got)
{
	cout << "You obtained " << got->name << "!" << endl << endl;

	if (got->name == "Cursed Stone")
	{
		cout << "The stone kills you.. You lose all loot and go back to start." << endl << endl;
	}

	system("pause");
	system("CLS");
}

void printSold(int newG, int oldG, vector<item*> bag)
{
	cout << "Bag: ";

		for (int i = 0; i < bag.size(); i++)
    	{
        	cout << "[" << bag[i]->name << "] ";
    	}

    cout << endl;
	cout << "Sold for " << newG << " gold." << endl << endl;
	cout << "Current Gold: " << oldG << endl << endl;

	system("pause");
	system("CLS");
}

// Ex 3-2
void enterDungeon(int& g, vector<item*>& bag, item items[5])
{
	g -= 25;
	
	cout << "25 gold deducted for entrance." << endl << endl;
	cout << "Current Gold: " << g << endl << endl;
	system("pause");
	system("CLS");
	

	while (true)
	{
		item* temp = generateItem(&items[0]);
		bag.push_back(temp);

		printObtained(temp);

		if (temp->name == "Cursed Stone")
		{
			bag.clear();
			return;
		}

		cout << "Current Gold: " << g << endl;
		cout << "Bag: ";

		for (int i = 0; i < bag.size(); i++)
    	{
        	cout << "[" << bag[i]->name << "] ";
    	}

    	cout << endl;

		char ans;

		do
		{
			cout << "Continue..? y/n  ";
			cin >> ans;
		} while (ans != 'y' && ans != 'n');

		system("CLS");

		if (ans == 'n')
		{
			int tempG = 0;
			for (int i = 0; i < bag.size(); i++) 
			{
				tempG += bag[i]->gold * (i + 1);
				//cout << bag[i]->gold * (i + 1) << endl;
				//cout << tempG << endl;
			}

			g += tempG;		
			printSold(tempG, g, bag);
			bag.clear();
			return;
		}

	}
}

int main()
{
	srand(time(0));

	item items[5] = {};
	
	//Cursed Stone, Jellopy, Thick Leather, Sharp Talon, Mithril Ore
	items[0].name = "Cursed Stone";
	items[1].name = "Jellopy";
	items[2].name = "Thick Leather";
	items[3].name = "Sharp Talon";
	items[4].name = "Mithril Ore";

	items[0].gold = 0;
	items[1].gold = 5;
	items[2].gold = 25;
	items[3].gold = 50;
	items[4].gold = 100;

	vector<item*> bag;
	int gold = 50;

	system("CLS");

	// Ex 3-3
	while(gold > 24)
	{
		cout << "Entering dungeon..." << endl << endl;
		system("pause");
		system("CLS");

		enterDungeon(gold, bag, items);

		
		// Ex 3-3
		if (gold >= 500)
		{
			cout << "Current Gold: " << gold << endl;
			cout << "Congratz. You win!" << endl;
			system("pause");
			return 0;
		}
	}

	cout << "Current Gold: " << gold << endl;
	cout << "You lose brokey. GG" << endl;
	system("pause");
	return 0;
	
	/*item* temp = generateItem(&items[0]);
	bag.push_back(temp);

	temp = generateItem(&items[0]);
	bag.push_back(temp);

	cout << bag[0]->name << endl;
	cout << bag[1]->name << endl;*/
}
