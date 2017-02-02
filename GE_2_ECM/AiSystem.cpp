#include "AiSystem.h"

AiSystem::AiSystem()
{

}

AiSystem::~AiSystem()
{

}

void AiSystem::addEntity(Entity & e)
{
	entities.push_back(&e);
}

void AiSystem::update()
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getComponent<HealthComponent>()->getHealth() > 50)
		{
			entities[i]->getComponent<PositionComponent>()->setY(entities[i]->getComponent<PositionComponent>()->getY() - 0.001f);
		}
		else if (entities[i]->getComponent<HealthComponent>()->getHealth() > 50)
		{
			entities[i]->getComponent<PositionComponent>()->setX(entities[i]->getComponent<PositionComponent>()->getX() + 0.001f);
		}
	}
}
