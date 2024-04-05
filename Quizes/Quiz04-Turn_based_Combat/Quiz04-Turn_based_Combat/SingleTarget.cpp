#include "SingleTarget.h"

SingleTarget::SingleTarget(string _name) : Action(_name, 2.2)
{
	SetManaCost(5);
}

void SingleTarget::PlayAction(vector<Unit*> _targets)
{
	Unit* target = _targets[rand() % _targets.size()];

	int damage = CalculateDamage(target);
	this->SetLastDamage(damage);
	target->SetHP(target->GetHP() - damage);
	this->SetTarget(target);
	this->GetSelfUnit()->SetMP(this->GetSelfUnit()->GetMP() - m_manaCost);
}
