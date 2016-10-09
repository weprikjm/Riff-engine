#ifndef __COMPONENTMESH_H__
#define __COMPONENTMESH_H__

#include "Globals.h"
#include "Component.h"
#include "ModuleMeshExporter.h"


class ComponentMesh : public Component
{
public:
	ComponentMesh() : Component(COMPONENTMESH) {}

	void AddMesh(const char* meshPath, ModuleMeshExporter importer);

	riffMesh* mesh;
};
#endif