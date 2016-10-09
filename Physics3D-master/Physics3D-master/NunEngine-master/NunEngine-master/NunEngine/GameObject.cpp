#include "GameObject.h"

#include "ComponentTransform.h"
#include "ComponentMesh.h"

#include "Component.h"

Component * GameObject::AddComponent(typeComponent type)
{
	Component* component;

	if (type == COMPONENTTRANSFORM) 
	{
		component = new ComponentTransform();
		components.push_back(component);
		return component;
	}
	if (type == COMPONENTMESH) 
	{
		component = new ComponentMesh();
		components.push_back(component);
	}

	else
	{
		return NULL;
	}


	return nullptr;
}
