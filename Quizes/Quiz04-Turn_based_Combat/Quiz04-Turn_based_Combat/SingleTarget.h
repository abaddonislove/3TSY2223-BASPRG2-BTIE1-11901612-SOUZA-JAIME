#pragma once
#include <string>
#include "Action.h"

using namespace std;

class SingleTarget : public Action
{
public:
	SingleTarget(string _name);

	void PlayAction(vector<Unit*> _targets);

private:
	int m_manaCost = 6;
	int m_damage = 10;
	float m_damageCoefficient = 0.9;
};

