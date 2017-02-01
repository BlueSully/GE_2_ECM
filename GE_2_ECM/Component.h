#pragma once
class Component
{
public:
	Component()
	{

	}

	~Component()
	{

	}
};

class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) 
	{

	}

private:
	int health;
};

class PositionComponent : public Component
{
public:
	PositionComponent() : x(0), y(0)
	{

	}

private:
	float x;
	float y;
};

class ControlComponent : public Component
{
public:
	ControlComponent() 
	{

	}

private:

};


