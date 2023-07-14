#pragma once
#include <string>
#include "Skill.h"
using namespace std;

class IronSkin : public Skill
{
public:
	IronSkin();

private:
	int amountChange;
};

