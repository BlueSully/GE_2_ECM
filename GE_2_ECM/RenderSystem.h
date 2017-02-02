#pragma once
#include "Entity.h"
#include "SDL.h"
#include <iostream>

class RenderSystem
{
private:
	vector<Entity *> entities;
	vector<SDL_Rect> entitiesDrawable;

	void render(SDL_Renderer * render);
public:
	RenderSystem();
	~RenderSystem();

	void addEntity(Entity & e);

	void update(SDL_Renderer * render);
};