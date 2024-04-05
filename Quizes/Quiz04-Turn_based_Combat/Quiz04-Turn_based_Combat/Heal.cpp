#include "Heal.h"

Heal::Heal(string _name) : Action(_name, 0)
{
	this->SetManaCost(this->m_manaCost);
}

void Heal::PlayAction(vector<Unit*> _targets)
{
	int lowestHP = 999;
	Unit* lowestHPUnit = nullptr;

	for (Unit* t : _targets)
	{
		if (t->GetHP() < lowestHP)
		{
			lowestHP = t->GetHP();
			lowestHPUnit = t;
		}
	}

	int healValue = lowestHPUnit->GetMaxHP() * 0.3;
	lowestHPUnit->SetHP(lowestHPUnit->GetHP() + healValue);

	this->SetTarget(lowestHPUnit);
	this->SetLastDamage(healValue);
	this->GetSelfUnit()->SetMP(this->GetSelfUnit()->GetMP() - m_manaCost);

	if (lowestHPUnit->GetHP() > lowestHPUnit->GetMaxHP()) { lowestHPUnit->SetHP(lowestHPUnit->GetMaxHP()); }
	cout << lowestHPUnit->GetName() << " " << lowestHPUnit->GetHP() << endl;
}

