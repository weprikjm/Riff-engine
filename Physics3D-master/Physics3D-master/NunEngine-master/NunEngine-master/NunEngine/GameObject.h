#pragma once
#include <vector>
#include "Component.h"





class GameObject
{
public:
	GameObject(const char* name,typeComponent type) 
	{
		AddComponent(type);
	}
	Component* AddComponent(typeComponent type);

	std::vector<Component*> components;

	char* name;
};