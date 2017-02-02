#include "Entity.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "AiSystem.h"
#include <iostream>
#include "SDL.h"

using namespace std;


int main(int argc, char* argv[])
{
	SDL_Window *window;
	SDL_Point windowSize;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	windowSize.x = 800;
	windowSize.y = 600;
	

	window = SDL_CreateWindow(
		"ECM Desgin Pattern",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		windowSize.x,                      // width, in pixels
		windowSize.y,                      // height, in pixels
		SDL_WINDOW_SHOWN                   // flags 
	);

	// Check that the window was successfully created
	if (window == NULL)
	{
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Entity player(EntityTYPE::PLAYER);
	Entity dog(EntityTYPE::DOG);
	Entity cat(EntityTYPE::CAT);
	Entity alien(EntityTYPE::ALIEN);
	
	ControlSystem m_controlSys;
	RenderSystem m_renderSys;
	AiSystem m_aiSys;

	
	player.addComponent(new PositionComponent());
	player.addComponent(new HealthComponent());
	player.addComponent(new ControlComponent());
	player.addComponent(new ColourComponent());

	player.getComponent<PositionComponent>()->setX(50);
	player.getComponent<PositionComponent>()->setY(50);

	player.getComponent<ControlComponent>()->setSpeed(10);
	player.getComponent<ColourComponent>()->setColours(255, 0, 0, 255);

	dog.addComponent(new PositionComponent());
	dog.addComponent(new HealthComponent());
	dog.addComponent(new ColourComponent());

	dog.getComponent<PositionComponent>()->setX(100);
	dog.getComponent<PositionComponent>()->setY(200);

	dog.getComponent<ColourComponent>()->setColours(0, 0, 255, 255);

	dog.getComponent<HealthComponent>()->setHealth(20);

	cat.addComponent(new PositionComponent());

	cat.getComponent<PositionComponent>()->setX(500);
	cat.getComponent<PositionComponent>()->setY(100);

	alien.addComponent(new PositionComponent());
	alien.addComponent(new HealthComponent());
	alien.addComponent(new ColourComponent());

	alien.getComponent<PositionComponent>()->setX(100);
	alien.getComponent<PositionComponent>()->setY(500);
	alien.getComponent<ColourComponent>()->setColours(255, 0, 255, 255);

	m_controlSys.addEntity(player);

	m_renderSys.addEntity(player);
	m_renderSys.addEntity(dog);
	m_renderSys.addEntity(cat);
	m_renderSys.addEntity(alien);

	m_aiSys.addEntity(alien);
	m_aiSys.addEntity(dog);

	while (true) 
	{
		m_controlSys.update();
		m_aiSys.update();
		m_renderSys.update(renderer);	
	}

	SDL_Quit();
}
