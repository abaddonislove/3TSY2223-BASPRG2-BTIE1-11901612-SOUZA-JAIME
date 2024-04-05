#pragma once
#include <string>
#include "Action.h"

using namespace std;

class BasicAttack : public Action
{
public:
	BasicAttack(string _name);

	void PlayAction(vector<Unit*> _targets);

private:
	int m_damage = 10;
	float m_damageCoefficient = 1.0;

	bool CheckCrit();
	bool CheckHit(Unit* _target);
};

