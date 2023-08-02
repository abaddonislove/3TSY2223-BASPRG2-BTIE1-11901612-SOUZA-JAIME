#include "SingleTarget.h"
#include "SingleHit.h"

SingleTarget::SingleTarget(string name, int hp, int pow, int vit, int agi, int dex, int mp) : Unit(name, hp, pow, vit, agi, dex, mp)
{
	special = new SingleHit(this);
}

void SingleTarget::specialAttack(vector<Unit*> targetUnits)
{
	special->activate(targetUnits);
	this->setMP(-4);
}

