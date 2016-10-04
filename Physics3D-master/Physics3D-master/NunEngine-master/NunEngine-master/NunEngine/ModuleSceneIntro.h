#pragma once
#include "Module.h"
#include "Globals.h"
#include "Primitive.h"
#include "ModuleMeshExporter.h"


class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	bool DrawMesh(riffMesh* mesh);


public:
	void CreateCubeImmediateMode();
	void CreateCubeVertexArray();
	void CreateCubeDrawElements();

};
