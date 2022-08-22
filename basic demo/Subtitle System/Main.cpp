#include "windower/Window.h"

#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

//create a window object
Window* hWindow;

int main(int argc, char* argv[])
{	
	SDL_Event sdlEvent;  // variable to detect SDL events

	//instantiate the window with W/H and a name
	hWindow = new Window(1200, 800, "simple window demo");

	bool running = true;
	while (running) {	// the event loop
		while (SDL_PollEvent(&sdlEvent)) {
			switch (sdlEvent.type) {
				case SDL_QUIT:
					running = false;
					break;
				case SDL_WINDOWEVENT:
					if (sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED) {
						hWindow->resize(sdlEvent);
					}
					break;
			};
		}
	}
	
	return 0;
}