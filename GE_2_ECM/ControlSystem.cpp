#include "ControlSystem.h"

ControlSystem::ControlSystem()
{
}

ControlSystem::~ControlSystem()
{
}


void ControlSystem::addEntity(Entity & e)
{
	entities.push_back(&e);
}

void ControlSystem::update()
{
	SDL_Event evt;

	for (size_t i = 0; i < entities.size(); i++)
	{
		int speed = entities[i]->getComponent<ControlComponent>()->getSpeed();
		while (SDL_PollEvent(&evt))
		{

			if (evt.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (evt.key.keysym.sym)
				{
				case SDLK_UP:
					entities[i]->getComponent<PositionComponent>()->setY(entities[i]->getComponent<PositionComponent>()->getY() - speed);
					break;

				case SDLK_DOWN:
					entities[i]->getComponent<PositionComponent>()->setY(entities[i]->getComponent<PositionComponent>()->getY() + speed);
					break;

				case SDLK_LEFT:
					entities[i]->getComponent<PositionComponent>()->setX(entities[i]->getComponent<PositionComponent>()->getX() - speed);
					break;

				case SDLK_RIGHT:
					entities[i]->getComponent<PositionComponent>()->setX(entities[i]->getComponent<PositionComponent>()->getX() + speed);
					break;

				default:

					break;
				}
			}
		}
	}
}
