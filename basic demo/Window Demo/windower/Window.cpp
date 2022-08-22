#include "Window.h"

void Window::setupRC()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialize video
		std::cout << "Unable to initialize SDL" << std::endl;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // double buffering on
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4); // Turn on x4 multisampling anti-aliasing (MSAA)

	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); // 8 bit alpha buffering
}

SDL_Window* Window::create_window()
{
	//Create window
	window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (!window) // Check window was created OK
		std::cout << "Unable to create window" << std::endl;

	glContext = SDL_GL_CreateContext(window); // Create opengl context and attach to window
	SDL_GL_SetSwapInterval(1); // set swap buffers to sync with monitor's vertical refresh rate
	return window;
}

void Window::createRenderer()
{
	renderTarget = nullptr;
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Required on Windows *only* init GLEW to access OpenGL beyond 1.1
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) { // glewInit failed, something is seriously wrong
		std::cout << "glewInit failed, aborting." << endl;
		exit(1);
	}
	cout << glGetString(GL_VERSION) << endl;
}

SDL_Window* Window::getWindow()
{
	return window;
}

SDL_Renderer* Window::getRenderTarget()
{
	return renderTarget;
}

void Window::cleanWindow()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
}

void Window::resize()
{
	SDL_RenderPresent(renderTarget); 
	setBackgroundColour();	//keeps the background colour consistent
}

void Window::setBackgroundColour(vector<int> colour)
{
	// ensure valid range
	if (colour.size() >= 3)
	{
		//update window colour
		SDL_SetRenderDrawColor(renderTarget, colour[0], colour[1], colour[2], 255);
		
		// Clear the entire screen
		SDL_RenderClear(renderTarget);

		// render changes
		SDL_RenderPresent(renderTarget);
	}
	else
		cout << "Please chose a valid colour range: {0-255, 0-255, 0-255}";
}
