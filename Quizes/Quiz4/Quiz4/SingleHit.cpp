#include "SingleHit.h"

SingleHit::SingleHit(Unit* caster) : SpecialAttack("SingleHit", caster)
{
}

int SingleHit::manaCost()
{
	return 4;
}

void SingleHit::activate(vector<Unit*> targetUnits)
{
	Unit* attackTarget = new Unit("dummy",999,0,0,0,0,0);
	for (int i = 1; i < targetUnits.size(); i++)
	{
		if (targetUnits[i]->getHP() < attackTarget->getHP() && targetUnits[i]->getFaction() != Caster->getFaction())
		{
			attackTarget = targetUnits[i];
		}
	}

	attackTarget->setHP((int)(-this->Caster->getPOW()*2.2));
}
