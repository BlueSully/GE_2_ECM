#pragma once
enum class ComponentType
{
	DEFAULT,
	HEALTH,
	POSITION,
	CONTROL,
	COLOUR
};

class Component
{
private:
	ComponentType m_id;
public:
	Component() : m_id(ComponentType::DEFAULT)
	{

	}

	~Component()
	{

	}

	virtual ComponentType getID() const
	{
		return m_id;
	}

	virtual void setID(ComponentType value)
	{
		m_id = value;
	}
};

class HealthComponent : public Component
{
public:
	HealthComponent() : health(100)
	{
		Component::setID(ComponentType::HEALTH);
	}

	int getHealth()
	{ 
		return health; 
	}
	void setHealth(int health) 
	{ 
		this->health = health; 
	}

private:
	int health;
};

class PositionComponent : public Component
{
public:
	PositionComponent() : x(0), y(0)
	{
		Component::setID(ComponentType::POSITION);
	}

	float getX()
	{
		return x;
	}

	float getY()
	{
		return y;
	}

	void setX(float xvalue)
	{
		this->x = xvalue;
	}

	void setY(float xvalue)
	{
		this->y = xvalue;
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
		Component::setID(ComponentType::CONTROL);
	}

	int getSpeed()
	{
		return m_speed;
	}

	void setSpeed(int value)
	{
		this->m_speed = value;
	}

private:
	
	int m_speed;
};

class ColourComponent : public Component
{
public:
	ColourComponent(): red(255), green(255), blue(255), alpha(255)
	{
		Component::setID(ComponentType::COLOUR);
	}

	int getRed()
	{
		return red;
	}

	int getGreen()
	{
		return green;
	}

	int getBlue()
	{
		return blue;
	}

	int getAlpha()
	{
		return alpha;
	}

	void setColours(int r = 0, int g = 0, int b = 0, int a = 255)
	{
		this->red = r;
		this->green = g;
		this->blue = b;
		this->alpha = a;
	}


	void setRed(int value)
	{
		this->red = value;
	}

	void setGreen(int value)
	{
		this->green = value;
	}

	void setBlue(int value)
	{
		this->blue = value;
	}

	void setAlpha(int value)
	{
		this->alpha = value;
	}

private:
	int red;
	int green;
	int blue;
	int alpha;
};



