#include "ModuleGui.h"
#include "Application.h"


#include "Imgui\imgui.h"
#include "Imgui\imgui_impl_sdl_gl3.h"
#include "Imgui\imgui_internal.h"


#pragma comment (lib, "Glew/libx86/glew32.lib")




ModuleGui::ModuleGui(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

ModuleGui::~ModuleGui()
{
}

bool ModuleGui::Init()
{
	//LOG("Init editor gui with imgui lib version %s", ImGui::GetVersion());
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = "imgui.ini";

	ImGui_ImplSdlGL3_Init(App->window->GetWindow());
	
	io.DisplaySize.x = SCREEN_WIDTH;
	io.DisplaySize.y = SCREEN_HEIGHT;
	io.IniFilename = "imgui.ini";
	io.RenderDrawListsFn = NULL;
	
	//unsigned char** pixels;
	//int width, height;
	//io.Fonts->GetTexDataAsRGBA32(pixels, &width, &height);



	return true;
}

bool ModuleGui::CleanUp()
{
	return false;
}

update_status ModuleGui::Update(float dt)
{
	ImGui_ImplSdlGL3_NewFrame(App->window->GetWindow());
	ImGuiIO& io = ImGui::GetIO();
	ImGui::Begin("My window");
	ImGui::Text("Hello, world.");
	capture_keyboard = io.WantCaptureKeyboard;

	return UPDATE_CONTINUE;
	ImGui::End();





	return UPDATE_CONTINUE;
}

update_status ModuleGui::PostUpdate(float dt)
{
	ImGui::Render();

	return UPDATE_CONTINUE;
}