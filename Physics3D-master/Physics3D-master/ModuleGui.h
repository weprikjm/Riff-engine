#pragma once


#ifndef __ModuleGui_H__
#define __ModuleGui_H__

#include "Module.h"
#include "Imgui\imgui.h"

class ModuleGui : public Module
{
public:

	ModuleGui(Application* app, bool start_enabled);
	~ModuleGui();

	bool Init();
	bool CleanUp();
	update_status Update(float dt);
	update_status ModuleGui::PostUpdate(float dt);


	bool capture_mouse = false;
	bool capture_keyboard = false;


};

#endif // __ModuleGui_H__