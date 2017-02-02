#pragma once
#include "Entity.h"
#include "SDL.h"
#include <iostream>

class ControlSystem
{
private:
	vector<Entity *> entities;

public:
	ControlSystem();
	~ControlSystem();

	void addEntity(Entity & e);

	void update();
};