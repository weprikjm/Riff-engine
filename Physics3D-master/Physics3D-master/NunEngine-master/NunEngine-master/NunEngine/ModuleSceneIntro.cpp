#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "ModuleMeshExporter.h"
#include "Glew\include\glew.h"
#include "Imgui\imgui.h"



#define CHECKERS_HEIGHT 1
#define CHECKERS_WIDTH 1



ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;


	for(int i = 0; i < App->importer->meshes.size(); i++)
	{
		
		glGenBuffers(1, (GLuint*) &(App->importer->meshes[i]->id_vertices));

		glBindBuffer(GL_ARRAY_BUFFER, App->importer->meshes[i]->id_vertices);

		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*App->importer->meshes[i]->numVertex * 3, App->importer->meshes[i]->vertices, GL_STATIC_DRAW);

		glGenBuffers(1, (GLuint*) &(App->importer->meshes[i]->id_indices));

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, App->importer->meshes[i]->id_indices);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint)*App->importer->meshes[i]->numFaces, App->importer->meshes[i]->indices, GL_STATIC_DRAW);

	
		glEnableClientState(GL_NORMAL_ARRAY);


		glGenBuffers(1, (GLuint*) &(App->importer->meshes[i]->id_normals));
		glBindBuffer(GL_ARRAY_BUFFER, App->importer->meshes[i]->id_normals);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) *App->importer->meshes[i]->numVertex * 3, App->importer->meshes[i]->normals, GL_STATIC_DRAW);
		glNormalPointer(GL_FLOAT, 0, NULL);
	}

	
	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	
	return true;
}

bool ModuleSceneIntro::DrawMesh(riffMesh* mesh)
{
	bool ret = true;
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);



	glBindBuffer(GL_ARRAY_BUFFER, mesh->id_vertices);
	glVertexPointer(3, GL_FLOAT, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->id_normals);
	glNormalPointer(GL_FLOAT, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->id_indices);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->id_indices);
	glDrawElements(GL_TRIANGLES, mesh->numFaces, GL_UNSIGNED_INT, NULL);



	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	
	return ret;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	for(int i = 0; i < App->importer->meshes.size(); i++)
	{
		DrawMesh(App->importer->meshes[i]);	
	}


	CreateCubeImmediateMode();



	return UPDATE_CONTINUE;
}


void ModuleSceneIntro::CreateCubeImmediateMode() 
{

	GLubyte checkImage[CHECKERS_HEIGHT][CHECKERS_WIDTH][4];
	for (int i = 0; i < CHECKERS_HEIGHT; i++) {
		for (int j = 0; j < CHECKERS_WIDTH; j++) {
			int c = ((((i & 0x8) == 0) ^ (((j & 0x8)) == 0))) * 255;
			checkImage[i][j][0] = (GLubyte)c;
			checkImage[i][j][1] = (GLubyte)c;
			checkImage[i][j][2] = (GLubyte)c;
			checkImage[i][j][3] = (GLubyte)255;
		}
	}

	GLuint ImageName;

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &ImageName);
	glBindTexture(GL_TEXTURE_2D, ImageName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, CHECKERS_WIDTH, CHECKERS_HEIGHT,
		0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);



	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ImageName);



	glBegin(GL_TRIANGLES);
	// front faces
	glNormal3f(0, 0, 1);
	// face v0-v1-v2
	glColor3f(1, 1, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1, -1, 1);
	// face v2-v3-v0
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);





	// right faces
	glNormal3f(1, 0, 0);
	// face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	// face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);






	// top faces
	glNormal3f(0, 1, 0);
	// face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);






	// left faces
	glNormal3f(-1, 0, 0);
	// face  v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	// face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	




	// bottom faces
	glNormal3f(0, -1, 0);
	// face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	// face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);






	// back faces
	glNormal3f(0, 0, -1);
	// face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, 0);



}

void ModuleSceneIntro::CreateCubeVertexArray()
{
	GLfloat vertices[] =
	{
	 1, 1, 1,

	-1, 1, 1,

	-1, -1, 1,

	-1, -1, 1,

	1, -1, 1,

	1, 1, 1,


	1, 1, 1,

	1, -1, 1,

	1, -1, -1,

	1, -1, -1,

	1, 1, -1,

	1, 1, 1,


	1, 1, 1,

	1, 1, -1,

	-1, 1, -1,

	-1, 1, -1,

	-1, 1, 1,

	1, 1, 1,



	-1, 1, 1,

	-1, 1, -1,

	-1, -1, -1,


	-1, -1, -1,

	-1, -1, 1,

	-1, 1, 1,


	-1, -1, -1,

	1, -1, -1,

	1, -1, 1,


	1, -1, 1,

	-1, -1, 1,

	-1, -1, -1,




	1, -1, -1,

	-1, -1, -1,

	-1, 1, -1,

	-1, 1, -1,

	1, 1, -1,

	1, -1, -1,

	};

	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableClientState(GL_VERTEX_ARRAY);
	
}

void ModuleSceneIntro::CreateCubeDrawElements()
{

	GLubyte indices[] = { 0, 1, 2,   2, 3, 0,      // front
						4, 5, 6,   6, 7, 4,      // right
						8, 9,10,  10,11, 8,      // top
						12,13,14,  14,15,12,      // left
						16,17,18,  18,19,16,      // bottom
						20,21,22,  22,23,20 };    // back

			
			GLfloat vertices[] =
			{
				1, 1, 1,

				-1, 1, 1,

				-1, -1, 1,

				-1, -1, 1,

				1, -1, 1,

				1, 1, 1,


				1, 1, 1,

				1, -1, 1,

				1, -1, -1,

				1, -1, -1,

				1, 1, -1,

				1, 1, 1,


				1, 1, 1,

				1, 1, -1,

				-1, 1, -1,

				-1, 1, -1,

				-1, 1, 1,

				1, 1, 1,



				-1, 1, 1,

				-1, 1, -1,

				-1, -1, -1,


				-1, -1, -1,

				-1, -1, 1,

				-1, 1, 1,


				-1, -1, -1,

				1, -1, -1,

				1, -1, 1,


				1, -1, 1,

				-1, -1, 1,

				-1, -1, -1,




				1, -1, -1,

				-1, -1, -1,

				-1, 1, -1,

				-1, 1, -1,

				1, 1, -1,

				1, -1, -1,

			};

			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, 0, vertices);

			// draw a cube
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);

			// deactivate vertex arrays after drawing
			glDisableClientState(GL_VERTEX_ARRAY);



}