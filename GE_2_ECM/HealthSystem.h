#pragma once
#include "Entity.h"
#include <vector>
#include <iostream>
using namespace std;

class HealthSystem
{
	vector<Entity> entities;

public:
	void addEntity(Entity e) 
	{ 	
		entities.push_back(e);	
	}
	void update()
	{
		//cout << "HealthSystem Update" << endl;
		/* Loop through Entities with */
		/* HealthComponents and Update */
		/* TBI */
	}
};
