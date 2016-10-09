#ifndef __MODULEEDITOR_H__
#define __MODULEEDITOR_H__

#include "Module.h"
#include "Globals.h"
#include "Primitive.h"
#include "Imgui\imgui.h"
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

	void DrawConsole();
	void LogConsole(const char* text);

public:
	vector<float> fps_plot_values;
	ImGuiTextBuffer consoleText;
	bool ScrollToBottom = true;
private:
	bool demo = false;
	bool configuration = false;
	bool active = false;
};

#endif

