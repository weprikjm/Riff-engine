#ifndef __COMPONENTMESH_H__
#define __COMPONENTMESH_H__
#include "Globals.h"
#include "Component.h"
#include "ModuleMeshExporter.h"


class ComponentMesh : public Component
{
public:
	ComponentMesh() {}

	void AddMesh(const char* meshPath, ModuleMeshExporter importer);

};
#endif