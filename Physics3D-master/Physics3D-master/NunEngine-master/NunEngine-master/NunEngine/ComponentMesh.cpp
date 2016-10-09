#include "Globals.h"
#include "Application.h"
#include "ComponentMesh.h"
#include "ModuleMeshExporter.h"
#include "ModuleMeshExporter.h"

void ComponentMesh::AddMesh(const char* meshPath, ModuleMeshExporter importer)
{
	importer.LoadMesh(meshPath);
}
