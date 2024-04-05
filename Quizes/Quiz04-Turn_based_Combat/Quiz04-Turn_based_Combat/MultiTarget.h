#include <string>
#include "Action.h"

using namespace std;

class MultiTarget : public Action
{
public:
	MultiTarget(string _name);

	void PlayAction(vector<Unit*> _targets);

private:
	int m_manaCost = 8;
	int m_damage = 10;
};

