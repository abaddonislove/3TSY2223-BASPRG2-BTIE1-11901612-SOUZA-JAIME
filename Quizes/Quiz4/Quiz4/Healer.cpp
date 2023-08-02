#include "Healer.h"
#include "Heal.h"

Healer::Healer(string name, int hp, int pow, int vit, int agi, int dex, int mp) : Unit(name, hp, pow, vit, agi, dex, mp)
{
	special = new Heal(this);
}

void Healer::specialAttack(vector<Unit*> targetUnits)
{
	special->activate(targetUnits);
	this->setMP(-3);
}

