#pragma once
#include <string>
#include "Skill.h"
using namespace std;

class Might : public Skill
{
public:
	Might();

private:
	int amountChange;
};

