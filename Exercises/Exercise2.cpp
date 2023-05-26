// Ex 2-1 (Inventory Fill)
// Create a function which fills an inventory of 10 random items. Items in the inventory can be duplicated. 

// This function must return a vector of string. Each element in the vector represents an item in the inventory.

// Here are the items that can be included in the vector.
// RedPotion
// Elixir
// EmptyBottle
// BluePotion

// Note that you shouldn’t populate the vector inside the main() function.

// Ex 2-2 (Display Inventory)
// Create a function which prints the items in the inventory. After creating the vector in Ex 2-1, display the items by calling this function. 

// Pass the inventory to this function. This function does not need write access to the vector.
// Ex 2-3 (Count Item)
// Create a function which counts the number of instances an item has appeared in the inventory (vector).

// Pass the inventory vector to this function and return an integer which represents the item count. This function does not need write access to the vector.

// Ex 2-4 (Remove Item)
// Create a function which removes a specific item in the inventory.

// Pass the inventory vector to this function. Make sure the reference allows read and write access to the vector. 

#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

string objs[] = {"RedPotion", "Elixir", "EmptyBottle", "BluePotion"};

void fillInventory(vector<string>& bag)
{
    for (int i = 0; i < 10; i++)
	{
		bag.push_back( objs[ rand() % 4]);
	}
    
}

void displayInventory(vector<string> bag)
{
    
    cout << "Inventory : ";

    for (int i = 0; i < bag.size(); i++)
    {
        cout << bag[i] << " ";
    }

    cout << "\n";
}

int countItem(vector<string> bag, int objIndex)
{

    int objCount = 0;

    for (int i = 0; i < bag.size(); i++)
    {
        if (bag[i] == objs[objIndex])
        {
            objCount++;
        }
    }

    return objCount;
}

void removeItem(vector<string>& bag, int index)
{
    bag.erase(bag.begin() + index);
}

int main()
{
    vector<string> inventory;

    fillInventory(inventory);

    while (true)
    {

        displayInventory(inventory);

        int objCount[4] = {};

        //string objs[] = {"RedPotion", "Elixir", "EmptyBottle", "BluePotion"};
        for (int i = 0; i < 4; i++)
        {
            objCount[i] = countItem(inventory, i);

            if (i == 0)
            {
                cout << "Red Potions: ";
            }
            if (i == 1)
            {
                cout << "Elixir: ";
            }
            if (i == 2)
            {
                cout << "Empty Bottle: ";
            }
            if (i == 3)
            {
                cout << "Blue Potion: ";
            }
            
            cout << objCount[i] << endl;
        }

        int ind;
        cout << "\n\nRemove item with Index: ";
        cin >> ind;
        removeItem(inventory, ind);

        cin.ignore();
    }
    


}