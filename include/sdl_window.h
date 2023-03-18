#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H



#include <SDL2/SDL.h>
#include "glad/glad.h"

#include <functional>
#include <string>
#include <utility>

/**
 * Opens a window using the SDL library
 * For window operating system, it may be required to change #include <SDL2/SDL.h>
 * to #include <SDL.h>
 * Drawing is done by OpenGL
 */
class SDLWindow
{
	SDL_Window*	 p_window;
	SDL_GLContext gl_context;
	typedef std::function<void(int, int)> type_draw_function;
	const type_draw_function draw;
	
	bool quit_input_received();
	std::pair<int, int> get_window_size();
	
public:
	/**
	 * The window is resizeable therefore, the draw function must take 
	 * int width, int height as the parameters
	 */
	SDLWindow(const std::string& title, int width,
		int height, const type_draw_function& draw);
		
	~SDLWindow();
	
	/**
	 * Runs until quit command is received
	 * It can be until it ctrl+C is pressed on the command line, or the 'x' button is pressed
	 * 
	 */
	void run();
};
#endif
