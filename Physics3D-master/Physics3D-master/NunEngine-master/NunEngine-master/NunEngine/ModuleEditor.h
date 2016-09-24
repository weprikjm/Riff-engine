#pragma once
#include "Module.h"
#include "Globals.h"
#include "Primitive.h"

#include <vector>



class ModuleEditor : public Module
{
public:
	ModuleEditor(Application* app, bool start_enabled = true);
	~ModuleEditor();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void AddFPS(float fps);

public:
	vector<float> fps_plot_values;
private:
	bool demo = false;
	bool configuration = false;
	bool active = false;
	

};
