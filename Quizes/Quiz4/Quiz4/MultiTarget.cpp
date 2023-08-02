#include "MultiTarget.h"
#include "MultiHit.h"

MultiTarget::MultiTarget(string name, int hp, int pow, int vit, int agi, int dex, int mp) : Unit(name, hp, pow, vit, agi, dex, mp)
{
	special = new MultiHit(this);
}

void MultiTarget::specialAttack(vector<Unit*> targetUnits)
{
	special->activate(targetUnits);
	this->setMP(-5);
}

