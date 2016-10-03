#ifndef __ModuleMeshExporter_H__
#define __ModuleMeshExporter_H__



#include "Assimp/include/cimport.h"

#include "Assimp/include/scene.h"

#include "Assimp/include/postprocess.h"

#include "Assimp/include/cfileio.h"

#include "Globals.h"

#include <vector>


#include "Module.h"

#pragma comment (lib, "Assimp/libx86/assimp.lib")



class ModuleMeshExporter : public Module 
{

public:

	ModuleMeshExporter(Application* app, bool start_enabled = true);


	void LoadMesh(const char* path);


	update_status Update(float dt);
	bool Init();
	bool CleanUp();






	std::vector<aiMesh*> meshes;
	
};
#endif