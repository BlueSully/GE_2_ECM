#include "RenderSystem.h"

RenderSystem::RenderSystem()
{

}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::addEntity(Entity & e)
{
	entities.push_back(&e);
}

void RenderSystem::update(SDL_Renderer * render)
{
	//Clear screen
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);

	for (size_t i = 0; i < entities.size(); i++)
	{
		SDL_Rect srcrect;
		if (entities[i]->getComponent<ColourComponent>() != nullptr) 
		{
			SDL_SetRenderDrawColor(render, entities[i]->getComponent<ColourComponent>()->getRed(),
				entities[i]->getComponent<ColourComponent>()->getGreen(),
				entities[i]->getComponent<ColourComponent>()->getBlue(),
				entities[i]->getComponent<ColourComponent>()->getAlpha());
		}
		else 
		{
			SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
		}

		srcrect.x = static_cast<int>(entities[i]->getComponent<PositionComponent>()->getX());
		srcrect.y = static_cast<int>(entities[i]->getComponent<PositionComponent>()->getY());
		srcrect.w = 32;
		srcrect.h = 32;

		SDL_RenderDrawRect(render, &srcrect);
	}

	//Update screen
	SDL_RenderPresent(render);
}

void RenderSystem::render(SDL_Renderer * render)
{

}
