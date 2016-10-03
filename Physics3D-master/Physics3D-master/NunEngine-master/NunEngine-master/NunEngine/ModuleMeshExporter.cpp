#include "ModuleMeshExporter.h"


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
			meshes.push_back(scene->mMeshes[i]);
		}
	}
	//LoadMesh
}

update_status ModuleMeshExporter::Update(float dt)
{
	return UPDATE_CONTINUE;
}

bool ModuleMeshExporter::Init()
{
	return true;
}

bool ModuleMeshExporter::CleanUp()
{
	return true;
}

