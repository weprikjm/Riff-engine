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
		 numVertex = m->mNumVertices;

		if (m->mNumVertices > 0)
		{

			vertices = new float[(m->mNumVertices*3)];
			
			memcpy(vertices,m->mVertices,sizeof(float) * m->mNumVertices * 3);
			
			/*
			for(int i = 0; i < m->mNumVertices; i+=3)
			{
				vertices[i] = m->mVertices[i].x;
				vertices[(i+1)] = m->mVertices[i].y;
				vertices[(i+2)] = m->mVertices[i].z;

			}*/

			if (m->HasFaces())

			{
				numFaces = m->mNumFaces * 3;

				indices = new uint[numFaces];

				for (uint i = 0; i < m->mNumFaces; ++i)
				{
					 
					if (m->mFaces[i].mNumIndices != 3)
					{
						LOG("WARNING, geometry face with != 3 indices!");
					}
					else 
					{
						memcpy(&indices[i * 3], m->mFaces[i].mIndices, 3 * sizeof(uint));
					}

				}

			}



		}

		numFaces = m->mNumFaces;
	}


	uint* indices = nullptr;
	uint id_indices;
	float* vertices = nullptr;
	uint id_vertices;
	uint numFaces;
	uint numVertex;
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