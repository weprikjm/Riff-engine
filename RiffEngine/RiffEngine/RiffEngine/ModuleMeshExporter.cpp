
#include "ModuleMeshExporter.h"
#include "GameObject.h"
#include "Globals.h"
#include "Application.h"
#include "Component.h"

#pragma comment (lib, "Devil/libx86/DevIL.lib")
#pragma comment (lib, "Devil/libx86/ILU.lib")
#pragma comment (lib, "Devil/libx86/ILUT.lib")

#include "Devil/include/il.h"
#include "Devil/include/ilu.h"
#include "Devil/include/ilut.h"


using namespace std;

ModuleMeshExporter::ModuleMeshExporter(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	LOG("Exporter Initializing");
}




riffMesh* ModuleMeshExporter::LoadMesh(const char* path,riffMesh* mesh)
{

	static int id_Mesh = 0;

	if (!path)
	{

		LOG("Error loading geometry");
	}

	const aiScene* scene = aiImportFile(path, 0);
	
	riffMesh* tmpMesh;

	if (scene->HasMeshes())
	{
		for (int i = 0; i < scene->mNumMeshes; i++)
		{
			tmpMesh = new riffMesh(scene->mMeshes[i], "object_", i);
			meshes.push_back(tmpMesh);
			App->scene_intro->oFactory.allSceneObjects.push_back(new GameObject(tmpMesh->name, COMPONENTMESH));
			ComponentMesh* tmp = nullptr;
			App->scene_intro->oFactory.allSceneObjects[i]->FindComponent(COMPONENTMESH, (Component**)tmp);
			
			tmp->AddMesh(tmpMesh);
		}

		//UnloadMesh
		aiReleaseImport(scene);
	}
	return tmpMesh;
}

update_status ModuleMeshExporter::Update(float dt)
{
	return UPDATE_CONTINUE;
}

bool ModuleMeshExporter::Init()
{

	struct aiLogStream stream;
	stream = aiGetPredefinedLogStream(aiDefaultLogStream_DEBUGGER, nullptr); 
	aiAttachLogStream(&stream);

	riffMesh* mesh = nullptr;
	LoadMesh("Assets/Streetenvironment_V01.FBX",mesh);


	return true;
}

bool ModuleMeshExporter::CleanUp()
{
/*
	for (vector<riffMesh*>::iterator it = meshes.begin(); it != meshes.end(); it++)
	{
		delete it._Ptr;
	}
	*/
	meshes.clear();

	aiDetachAllLogStreams();
	return true;
}

