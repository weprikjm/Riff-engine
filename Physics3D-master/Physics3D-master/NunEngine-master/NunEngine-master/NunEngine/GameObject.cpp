#include "GameObject.h"

#include "ComponentTransform.h"
#include "ComponentMesh.h"

#include "Component.h"

Component * GameObject::AddComponent(typeComponent type)
{
	Component* component;

	if (type == COMPONENTTRANSFORM) 
	{
		component = new ComponentTransform(COMPONENTTRANSFORM);
		components.push_back(component);
		return component;
	}

	if (type == COMPONENTMESH) 
	{
		component = new ComponentMesh();
		components.push_back(component);
		return component;
	}

	else
	{
		return NULL;
	}


	return nullptr;
}
 bool GameObject::FindComponent(typeComponent type, Component* comp)
{
	for(int i = 0; i < components.size(); i++)
	{
		if (components[i]->type == type) 
		{
				 comp = components[i];
				 return true;
		}
	}
		return false;
	
}
