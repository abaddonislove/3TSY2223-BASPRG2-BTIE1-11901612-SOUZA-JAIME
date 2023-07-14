#pragma once
#include <string>
#include "Skill.h"
using namespace std;

class Haste : public Skill
{
public:
	Haste();

private:
	int amountChange;
};

