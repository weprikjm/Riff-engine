#pragma once
#include <vector>
#include "Component.h"
#include "ComponentMesh.h"




class GameObject
{
public:
	GameObject(const char* name, typeComponent type = COMPONENTEMPTY) 
	{
		this->name = new char(strlen(name));
		strcpy(this->name,name);
		AddComponent(type);
	}
	Component* AddComponent(typeComponent type);

	bool FindComponent(typeComponent type, Component* comp);

	std::vector<Component*> components;
	std::vector<GameObject*> children;

	char* name;
};