
#include "GameObjectFactory.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleEditor.h"


GameObject* GameObjectFactory::CreateGameObject(typeComponent type, const char* name)
{

	GameObject* gameObject;
	
		if (type == COMPONENTTRANSFORM)
		{
			LOG("GameObject created with transform component.");
			gameObject = new GameObject(name,type);
			return gameObject;
		}

		if (type == COMPONENTMESH)
		{
			LOG("GameObject created with mesh component");
			gameObject = new GameObject(name, type);
		}
	
}


GameObject* GameObjectFactory::FindId(int num) 
{
	for (int i = 0; i < allSceneObjects.size(); i++) 
	{
		if (allSceneObjects[i]->GetID() == num)
		{
			return allSceneObjects[i];
		}
	}
}