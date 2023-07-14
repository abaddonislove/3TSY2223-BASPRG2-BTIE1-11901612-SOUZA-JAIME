#include <iostream>
#include <stdlib.h> 
#include "Unit.h"
#include<cstdlib>
using namespace std;

int main()
{
	srand(time(0));
	Unit* player = new Unit("jack", 10, 10, 10, 10, 100);

	while (true)
	{
		player->useRandomSkill();
		player->checkStats();
		system("pause");
	}

	
	

	
	return 0;
}