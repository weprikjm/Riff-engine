#pragma once
#include <vector>
#include "Component.h"
class GameObject
{
public:
	GameObject(const char* name) 
	{
		strcpy(this->name,name);
	}

	std::vector<Component*> components;

	char* name;
};