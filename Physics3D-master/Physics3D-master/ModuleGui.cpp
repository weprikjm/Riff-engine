#include "ModuleGui.h"
#include "Application.h"



#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include "imgui_impl_sdl_gl3.h"
#include "imgui_internal.h"
#include "imconfig.h"

#pragma comment (lib, "Glew/libx86/glew32s.lib")




ModuleGui::ModuleGui(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

ModuleGui::~ModuleGui()
{
}

bool ModuleGui::Init()
{
	//LOG("Init editor gui with imgui lib version %s", ImGui::GetVersion());

	//ImGui_ImplSdlGL3_Init(App->window->GetWindow());

	ImGuiIO& io = ImGui::GetIO();
	//io.DisplaySize.x = SCREEN_WIDTH;
	//io.DisplaySize.y = SCREEN_HEIGHT;
	//io.IniFilename = "imgui.ini";
	//io.RenderDrawListsFn = NULL;
	
	return true;
}

bool ModuleGui::CleanUp()
{
	return false;
}

update_status ModuleGui::Update()
{
	return UPDATE_CONTINUE;
}
