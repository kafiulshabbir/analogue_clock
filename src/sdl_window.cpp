#include "sdl_window.h"

bool SDLWindow::quit_input_received()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	return event.type == SDL_QUIT;
}

std::pair<int, int> SDLWindow::get_window_size()
{
	int window_width;
	int window_height;
	SDL_GetWindowSize(p_window, &window_width, &window_height);
	
	return {window_width, window_height};
}


SDLWindow::SDLWindow(const std::string& title, int width,
	int height, const type_draw_function& draw):
	draw(draw)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
	p_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	gl_context = SDL_GL_CreateContext(p_window);
	gladLoadGLLoader(SDL_GL_GetProcAddress);
}

SDLWindow::~SDLWindow()
{
	SDL_DestroyWindow(p_window);
	SDL_Quit();
}
		
void SDLWindow::run()
{
	while(!quit_input_received())
	{
		const auto window_size = get_window_size();
		draw(window_size.first, window_size.second);
		SDL_GL_SwapWindow(p_window);
	}
}

