#pragma once
#include "Module.h"
#include "Globals.h"
#include "Primitive.h"

#include <deque>



class ModuleEditor : public Module
{
public:
	ModuleEditor(Application* app, bool start_enabled = true);
	~ModuleEditor();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();



public:
	deque<float> fps_plot_values;
private:
	bool demo = false;
	bool configuration = false;
	bool active = false;
	

};
