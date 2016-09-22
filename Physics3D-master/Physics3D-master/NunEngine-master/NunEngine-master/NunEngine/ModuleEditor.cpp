﻿#include "Globals.h"
#include "Application.h"
#include "ModuleEditor.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "Glew\include\glew.h"
#include "SDL\include\SDL_opengl.h"
#include <gl/GL.h>
#include <gl/GLU.h>


#include "Imgui\imgui.h"

#pragma comment (lib, "Glew/libx86/glew32.lib")


ModuleEditor::ModuleEditor(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleEditor::~ModuleEditor()
{}

// Load assets
bool ModuleEditor::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;



	return ret;
}

// Load assets
bool ModuleEditor::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleEditor::Update(float dt)
{
	//Create the menu bar
	ImGui::BeginMainMenuBar();

	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("Quit"))
			return UPDATE_STOP;

		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Help"))
	{
		if (ImGui::MenuItem("Demo"))
			demo = !demo;

		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("View"))
	{
		if (ImGui::MenuItem("HardWare"))
			configuration = !configuration;

		ImGui::EndMenu();
	}

	ImGui::EndMainMenuBar();

	if(demo)
		ImGui::ShowTestWindow();


	//Configuration Menu box
	if (configuration)
	{
		ImGui::Begin("HardWare");




		if (ImGui::CollapsingHeader("System")) 
		{

			if (ImGui::Checkbox("Active", &active))
			{

			}

			SDL_version ver;
			SDL_GetVersion(&ver);

			ImGui::Text("SDL version: %d.%d", ver.major,ver.minor);
			ImGui::Separator();
			ImGui::Text("CPUs: ");

			ImGui::SameLine();
			int i = SDL_GetCPUCount();
			ImGui::Text("%d cores", i);
			

			ImGui::Text("System RAM: ");
			i = SDL_GetSystemRAM();
			ImGui::SameLine();
			ImGui::Text("%d mb/s", i);

			ImGui::Text("Caps: ");
			bool isTrue = SDL_HasSSE();
			ImGui::SameLine();
			
			if(isTrue)
				ImGui::Text("SSE,");
			
			isTrue = SDL_HasSSE2();
			
			ImGui::SameLine();
			
			if (isTrue)
				ImGui::Text("SSE2,");

			isTrue = SDL_HasSSE3();
			
			ImGui::SameLine();
			
			if (isTrue)
				ImGui::Text("SSE3,");
			isTrue = SDL_HasSSE41();
			
			ImGui::SameLine();
			
			if (isTrue)
				ImGui::Text("SSE41,");
			isTrue = SDL_HasSSE42();
			
			ImGui::SameLine();
			
			if (isTrue)
				ImGui::Text("SSE42,");
			
			isTrue = SDL_HasAVX();
			
			
			
			if (isTrue)
				ImGui::Text("AVX");

			

			ImGui::Separator();

			ImGui::Text("GPU:");
			ImGui::SameLine();
			const char* s = (const char*)glewGetString(GL_VENDOR);
			ImGui::Text("%s",s);

		}
		char title[25];

		if (ImGui::CollapsingHeader("Application"))
		{
			ImGui::PlotHistogram("##Framerate", &fps_plot_values.front(), fps_plot_values.size(), 0,title, 0.0f, 100.0f, ImVec2(310,100));

		}
		
		
		
		ImGui::End();
	}





	return UPDATE_CONTINUE;
}