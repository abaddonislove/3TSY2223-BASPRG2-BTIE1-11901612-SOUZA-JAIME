#include "wizard.h"
#include "Spell.h"

void wizard::attack(wizard* targetWizard)
{
	int damage = rand() % (MaxDamage - MinDamage + 1) + MinDamage;
	targetWizard->HP -= damage;
	MP += rand() % (11) + 10;

	cout << "\n\n\n";
	cout << Name << " attacks!\n";
	//cout << "Dealt " << damage << " to " << targetWizard->Name << ".\n";
	//cout << Name << "'s hp: " << targetWizard->HP;
	cout << "\n\n\n";
}

void wizard::activate(wizard* targetWizard)
{
	MP -= spell->MPcost;
	int damage = rand() % (spell->MaxDamage - spell->MinDamage + 1) + spell->MinDamage;
	targetWizard->HP -= damage;

	cout << "\n\n\n";
	cout << Name << " uses " << spell->Name << "!\n";
	cout << "Dealt " << damage << " to " << targetWizard->Name << ".\n";
	cout << Name << "'s hp: " << targetWizard->HP;
	cout << "\n\n\n";
}

void wizard::checkAlive()
{
	if (HP <= 0)
	{
		delete this;
	}
}
