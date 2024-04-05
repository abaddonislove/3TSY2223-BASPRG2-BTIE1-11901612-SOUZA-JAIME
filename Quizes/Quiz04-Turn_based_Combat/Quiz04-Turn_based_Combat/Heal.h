#include <string>
#include "Action.h"

using namespace std;

class Heal : public Action
{
public:
	Heal(string _name);

	void PlayAction(vector<Unit*> _targets);

private:
	int m_manaCost = 6;
	int m_damage = 10;
};