#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"

#define FPS_INTERVAL 1.0 //seconds.

Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
Uint32 fps_current; //the current FPS.
Uint32 fps_frames = 0; //frames passed since the last recorded fps.

void UpdateFps()
{
	//calculate frame rate.
	fps_frames++;
	if (SDL_GetTicks() > fps_lasttime + FPS_INTERVAL * 1000) {
		fps_lasttime = SDL_GetTicks();
		fps_current = fps_frames;
		fps_frames = 0;
		printf("fps_current: %d \n", fps_current);
	}
}


int main()
{
	Display display(800, 600, "Hello World!");
	
	Shader shader("./res/basicShader");

	Vertex verticies[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
					Vertex(glm::vec3(0, 0.5, 0)),
					Vertex(glm::vec3(0.5, -0.5, 0)) };
	
	Mesh mesh(verticies, sizeof(verticies) / sizeof(verticies[0]));

	while (!display.isClosed())	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.f);
		shader.Bind();

		mesh.Draw();
		display.Update();
		
		UpdateFps();

	}
	return 0;
}