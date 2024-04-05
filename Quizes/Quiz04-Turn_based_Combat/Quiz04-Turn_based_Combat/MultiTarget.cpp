#include "MultiTarget.h"

MultiTarget::MultiTarget(string _name) : Action(_name, 0.9)
{
	SetManaCost(8);
}

void MultiTarget::PlayAction(vector<Unit*> _targets)
{
	this->SetTarget(this->GetSelfUnit());
	Action::ResetLastDamages();
	for (int i = 0; i < _targets.size(); i++) 
	{ 
		Action::PlayAction(_targets[i]);
		
		Action::SetLastDamages(this->GetLastDamage(), i);
	}
	this->GetSelfUnit()->SetMP(this->GetSelfUnit()->GetMP() - m_manaCost);
}
