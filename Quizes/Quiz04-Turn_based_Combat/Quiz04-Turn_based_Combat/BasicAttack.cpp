#include "BasicAttack.h"

BasicAttack::BasicAttack(string _name) : Action(_name, 1.0)
{
	SetManaCost(0);
}

void BasicAttack::PlayAction(vector<Unit*> _targets)
{
	Unit* target = _targets[rand() % _targets.size()];

	if (!CheckHit(target))
	{
		this->SetLastDamage(0);
		return;
	}

	int damage = CalculateDamage(target);

	if (CheckCrit())
	{
		damage *= 1.2;
		cout << "Crit!" << endl;
	}

	this->SetLastDamage(damage);
	target->SetHP(target->GetHP() - damage);
	this->SetTarget(target);
}

bool BasicAttack::CheckCrit()
{
	int roll = rand() % 5;

	if (roll == 0) { return true; }
	
	return false;
}

bool BasicAttack::CheckHit(Unit* _target)
{
	float hitRate = (this->GetSelfUnit()->GetDEX() / _target->GetAGI()) * 100;
	int roll = rand() % 100 + 1;

	if (hitRate < 20) { hitRate = 20; }
	if (hitRate > 80) { hitRate = 80; }

	if (roll <= hitRate) { return true; }

	return false;
}
