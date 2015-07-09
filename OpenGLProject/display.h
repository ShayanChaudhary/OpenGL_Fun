#ifndef DISPLAY_H
#define DISPLAY_H


#include <SDL2/SDL.h>
#undef main
#include <string>

class Display
{
public:
	//constructor
	Display(int width, int height, const std::string& title);
	//methods
	void Clear(float r, float g, float b, float a);
	void Update();
	bool isClosed();
	//deconstructor
	virtual ~Display();
protected:
private:
	Display(const Display& other) {}
	Display& operator=(const Display& other) {}
	SDL_Window* m_window;
	//OS has direct co""ntroll over window, this context allows the
	//gpu to access and draw to window.
	SDL_GLContext m_glContext;
	bool m_isClosed;

};

#endif //DISPLAY_H
