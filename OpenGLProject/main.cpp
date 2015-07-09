#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"

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
	Vertex verticies[] = {
		Vertex(glm::vec3(-0.5, -0.5, 0.0),		glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3( 0.0,  0.5, 0.0),		glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3( 0.5, -0.5, 0.0),		glm::vec2(1.0, 0.0)) };
	Display display(1200, 800, "Hello World!");
	Mesh mesh(verticies, sizeof(verticies) / sizeof(verticies[0]));
	Shader shader("./res/basicShader");//load shaders
	Texture texture("./res/bricks.jpg");
    Transform transform;

    float counter = 0.0f;

	while (!display.isClosed())	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.f);

        float sincounter = sinf(counter);
        float coscounter = cosf(counter);


        transform.GetPos().x = sincounter;
        transform.GetRot().z = counter * 200;
        transform.SetScale(glm::vec3(coscounter, coscounter, coscounter));

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform);//all verticies are multiplied by transform matrix
		mesh.Draw();
		display.Update();
        counter +=0.01f;
		UpdateFps();
	}
	return 0;
}
