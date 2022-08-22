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
	vector<int> windowColour { 255, 255, 255 };	//used for tracking windowColour

public:
	Window(int w, int h, const char* name) :
		width(w), height(h), windowName(name) 
	{
		setupRC();
		create_window();
		createRenderer();
		setBackgroundColour(windowColour);
	}

	virtual ~Window() {}
	void setupRC();
	SDL_Window* getWindow();
	SDL_Renderer* getRenderTarget();
	SDL_Window* create_window();
	void createRenderer();
	void cleanWindow();	//allow window to be wiped clean
	void resize();	//allow the window to be resizable
	void setBackgroundColour(vector<int> colour = { 255, 255, 255 }); //set initial window colour, default white
};

