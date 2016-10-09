#pragma once
#include <vector>
#include "Component.h"
#include "ComponentMesh.h"




class GameObject
{
public:
	GameObject(const char* name,typeComponent type) 
	{
		AddComponent(type);
	}
	Component* AddComponent(typeComponent type);

	ComponentMesh* GetComponentMesh();

	std::vector<Component*> components;

	char* name;
};