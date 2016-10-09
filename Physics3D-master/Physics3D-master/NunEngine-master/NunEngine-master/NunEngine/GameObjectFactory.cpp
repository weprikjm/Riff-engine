
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
