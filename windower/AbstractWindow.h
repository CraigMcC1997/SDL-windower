// ##########################################
//
// This is the abstract class for the window
//
// ##########################################

#pragma once
#include "SDL.h"
#include <GL/glew.h>
#include <iostream>
#include <vector>

using namespace std;

class AbstractWindow
{
public:
	virtual void setupRC() = 0;
	virtual SDL_Window* getWindow() = 0;
};