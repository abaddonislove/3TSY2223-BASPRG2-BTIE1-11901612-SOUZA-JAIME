#pragma once
#include <string>
#include "Skill.h"
using namespace std;

class Heal : public Skill
{
public:
	Heal();

private:
	int amountChange;
};

