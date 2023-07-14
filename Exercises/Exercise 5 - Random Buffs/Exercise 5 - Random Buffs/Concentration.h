#pragma once
#include <string>
#include "Skill.h"
using namespace std;

class Concentration : public Skill
{
public:
	Concentration();

private:
	int amountChange;
};

