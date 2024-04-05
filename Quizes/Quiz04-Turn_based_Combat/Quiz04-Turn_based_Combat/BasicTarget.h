#pragma once
#include <string>
#include "Action.h"

using namespace std;

class BasicTarget : public Action
{
public:
	BasicTarget(string _name);

	virtual void UseAction(Unit* _target);

	void test();

private:
	int m_MPCost = 0;
	float m_damageCoefficient = 1.0;
};

