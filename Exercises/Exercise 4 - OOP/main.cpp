#include <iostream>
#include <string>
#include <time.h>
#include "wizard.h"
#include "Spell.h"

using namespace std;

const int STARTHP = 250;
const int STARTMP = 0;
const int MINDMG = 10;
const int MAXDMG = 20;



void printStatus(wizard* target)
{
	cout << target->Name;
	cout << "\nHealth: " << target->HP;
	cout << "\nMana: " << target->MP;

	return;
}

void printLine()
{
	cout << "\n\n----------------------------------\n\n";
	return;
}

void turn(wizard* source, wizard* target)
{
	if (source->MP >= source->spell->MPcost)
	{
		source->activate(target);
	}
	else
	{
		source->attack(target);
	}

	system("pause");
}

int main()
{
	int move = 1;
	srand((unsigned)time(0));

	wizard* gandalf = new wizard();
	wizard* harry = new wizard();
	Spell* spell = new Spell();

	gandalf->Name = "gandalf";
	gandalf->HP = STARTHP;
	gandalf->MP = STARTMP;
	gandalf->MaxDamage = MAXDMG;
	gandalf->MinDamage = MINDMG;

	harry->Name = "harry";
	harry->HP = STARTHP;
	harry->MP = STARTMP;
	harry->MaxDamage = MAXDMG;
	harry->MinDamage = MINDMG;

	spell->MaxDamage = 60;
	spell->MinDamage = 40;
	spell->Name = "fireball";
	spell->MPcost = 50;

	gandalf->spell = spell;
	harry->spell = spell;

	while (gandalf->HP > 0 && harry->HP > 0)
	{
		if (move == 1)
		{
			printStatus(harry);
			printLine();
			printStatus(gandalf);
			turn(harry, gandalf);
			system("CLS");
			
		}
		else if (move == -1)
		{
			printStatus(harry);
			printLine();
			printStatus(gandalf);
			turn(gandalf, harry);
			system("CLS");
			
		}
		move = move * -1;
	}

	harry->checkAlive();
	gandalf->checkAlive();

	cout << "\n\n";

	if (harry->HP > 0)
	{
		cout << "harry wins!\n";
	}
	else if(gandalf->HP > 0)
	{
		cout << "gandalf wins!\n\n";
	}

	system("pause");
	system("CLS");
}

