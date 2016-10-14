#ifndef __GAMEOBJECTFACTORY_H__
#define __GAMEOBJECTFACTORY_H__

#include "GameObject.h"
#include <vector>

class GameObjectFactory
{
public:
	GameObjectFactory()
	{
		
	}

	GameObject* CreateGameObject(typeComponent type, const char* name);


	GameObject* FindId(int num);
	std::vector<GameObject*> allSceneObjects;

	GameObject* root;
};




#endif