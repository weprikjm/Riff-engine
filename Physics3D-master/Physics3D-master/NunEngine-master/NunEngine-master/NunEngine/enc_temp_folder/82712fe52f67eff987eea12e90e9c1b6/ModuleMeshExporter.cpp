
#include "ModuleMeshExporter.h"

using namespace std;

ModuleMeshExporter::ModuleMeshExporter(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	LOG("Exporter Initializing");
}




void ModuleMeshExporter::LoadMesh(const char* path)
{
	if (!path)
	{

		LOG("Error loading geometry");
	}

	const aiScene* scene = aiImportFile(path, 0);
	
	//Load Vertices
	if (scene->HasMeshes())
	{
		for (int i = 0; i < scene->mNumMeshes; i++)
		{
			meshes.push_back(new riffMesh(scene->mMeshes[0]));
		}

		//UnloadMesh
		aiReleaseImport(scene);
	}
	
	
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


	LoadMesh("Assets/warrior.FBX");





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

