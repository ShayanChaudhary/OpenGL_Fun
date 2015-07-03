#include "display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string& title)
{
	std::cout << "Constructor!" << std::endl;
	//init 
	SDL_Init(SDL_INIT_EVERYTHING);

	//SET ATTRIBUTES
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);//GARRANTTES ATLEAST 8 BITS
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);//ALLOCATE SPACE FOR 2 WINDOWS
	

	//create window
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	//GL context
	m_glContext = SDL_GL_CreateContext(m_window);

	//glewInit finds all OpenGL functions which we support
	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to init!" << std::endl;
	}
	m_isClosed = false;
}

Display::~Display()
{
	std::cout << "Deconstructor!" << std::endl;
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	
}

void Display::Update()
{
	/*As we have double buffers, OpenGL updates one and OS draws on the other and then
	the buffer pointers swaped. This way we avoid weird updating and flickering issues.*/
	SDL_GL_SwapWindow(m_window);

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			m_isClosed = true;
	}
	
}

bool Display::isClosed()
{
	return m_isClosed;
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);//set preset colour
	glClear(GL_COLOR_BUFFER_BIT);//clear buffers to preset values

}