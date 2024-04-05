#include "BasicTarget.h"
#include <iostream>

BasicTarget::BasicTarget(string _name) : Action(_name, this->m_MPCost, this->m_damageCoefficient)
{
}

void BasicTarget::UseAction(Unit* _target)
{
	int damage = CalculateDamage(_target, m_damageCoefficient);
	//if (rand() % 100 > CalculateHitRate(_target)) { return; }
	//if (rand() % 100 < 20) { damage *= 1.2; }
	cout << "test2" << endl;
	//_target->SetCurrentHP(_target->GetCurrentHP() - damage);
}

void BasicTarget::test()
{
}

