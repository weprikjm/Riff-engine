#ifndef __ModuleMeshExporter_H__
#define __ModuleMeshExporter_H__



#include "Assimp/include/cimport.h"

#include "Assimp/include/scene.h"

#include "Assimp/include/postprocess.h"

#include "Assimp/include/cfileio.h"

#include "Globals.h"

#include <vector>


#include "Module.h"


#include "glmath.h"

#pragma comment (lib, "Assimp/libx86/assimp.lib")


struct riffMesh
{
	riffMesh(aiMesh* m) 
	{
		if (m->mNumVertices > 0)
		{
			for(int i = 0; i < m->mNumVertices; i++)
			{

				vec3 tmp;
				tmp.x = m->mVertices[i].x;
				tmp.y = m->mVertices[i].y;
				tmp.z = m->mVertices[i].z;

				vertices.push_back(tmp);
			}

		}
	}

	std::vector<vec3> vertices;
	uint id_vertices = 1;

};




class ModuleMeshExporter : public Module 
{

public:

	ModuleMeshExporter(Application* app, bool start_enabled = true);


	void LoadMesh(const char* path);


	update_status Update(float dt);
	bool Init();
	bool CleanUp();






	std::vector<riffMesh*> meshes;
	
};
#endif