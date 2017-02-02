#pragma once
#include "Entity.h"

class AiSystem
{
private:
	vector<Entity *> entities;

public:
	AiSystem();
	~AiSystem();

	void addEntity(Entity & e);

	void update();
};