#include "Entity.h"
#include "HealthSystem.h"
#include "PositionSystem.h"
#include <iostream>

using namespace std;


int main(void*)
{
	Entity player;
	Entity dog;
	Entity cat;
	Entity alien;
	
	HealthComponent hc; 
	PositionComponent pc;

	HealthSystem hs;
	PositionSystem ps;

	player.addComponent(hc);
	player.addComponent(pc);

	dog.addComponent(hc);
	dog.addComponent(pc);

	cat.addComponent(hc);
	cat.addComponent(pc);

	alien.addComponent(hc);
	alien.addComponent(pc);

	hs.addEntity(player);
	ps.addEntity(player);

	hs.addEntity(dog);
	ps.addEntity(dog);

	hs.addEntity(cat);
	ps.addEntity(cat);

	hs.addEntity(alien);
	ps.addEntity(alien);

	while (true) 
	{
		hs.update(); 
		ps.update();
	}
	return 0;
}
