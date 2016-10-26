#pragma once
#include <vector>
#include "Component.h"
#include "ComponentMesh.h"
#include "Globals.h"



class GameObject
{
public:
	GameObject(const char* name, typeComponent type = COMPONENTEMPTY) 
	{
		id++;
		this->name = new char(strlen(name));
		strcpy(this->name,name);
		AddComponent(type);
		
	}
	Component* AddComponent(typeComponent type);
	GameObject* AddChild(GameObject* go);
	bool FindComponent(typeComponent type, Component** comp);

	int GetID();


	std::vector<Component*> components;
	std::vector<GameObject*> children;

protected:
	static int id;

public:
	char* name;
};

