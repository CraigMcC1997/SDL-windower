// ##########################################################
//
// This class handles the window data using the SDL2 library
//
// ##########################################################

#pragma once
#include "AbstractWindow.h"

class Window : public AbstractWindow
{
private:
	SDL_Window* window;
	int height;
	int width;
	const char* windowName;
	SDL_Renderer* renderTarget = nullptr;
	SDL_GLContext glContext; // OpenGL context handle

public:
	Window(int w, int h, const char* name) :
		width(w), height(h), windowName(name) 
	{
		setupRC();
		create_window();
		createRenderer();
	}

	virtual ~Window() {}
	void setupRC();
	SDL_Window* getWindow();
	SDL_Renderer* getRenderTarget();
	SDL_Window* create_window();
	void createRenderer();
	void cleanWindow();
};

