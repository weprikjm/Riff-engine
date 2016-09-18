#pragma once


#ifndef __ModuleGui_H__
#define __ModuleGui_H__

#include "Module.h"
#include <imgui.h>

class ModuleGui : public Module
{
public:

	ModuleGui(Application* app, bool start_enabled);
	~ModuleGui();

	bool Init();
	bool CleanUp();
	update_status Update();

};

#endif // __ModuleGui_H__