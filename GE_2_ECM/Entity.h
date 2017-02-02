#pragma once
#include "Component.h"
#include <vector>
#include <unordered_map>
#include <typeinfo>
using namespace std;

enum class EntityTYPE
{
	PLAYER,
	DOG,
	CAT,
	ALIEN
};

class Entity
{
private:
	EntityTYPE m_id;
	std::unordered_map<const std::type_info*, Component *> m_components;
public:
	Entity() 
	{
	
	}

	Entity(EntityTYPE id)
	{
		m_id = id;
	}

	~Entity()
	{

	}

	void addComponent(Component * c) 
	{ 
		m_components[&(typeid(*c))] = c; 
	}

	void removeComponent(Component c)
	{ 
		/* TBI */
	}

	template <typename T>
	T * getComponent()
	{
		if (m_components.count(&typeid(T)) != 0) 
		{
			return static_cast<T *>(m_components[&typeid(T)]);
		}
		else 
		{
			return nullptr;
		}
	}
};
