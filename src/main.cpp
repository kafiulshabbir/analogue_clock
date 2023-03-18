#include "sdl_window.h"
#include "analogue_clock.h"

const std::string WINDOW_TITLE = "Analouge Clock";
const int WINDOW_WIDTH_INITIAL = 400;
const int WINDOW_HEIGHT_INITIAL = 400;

int main()
{
	//!< AnalogueClock::draw() is a static function which runs OpenGL commands
	SDLWindow window_of_clock(WINDOW_TITLE, WINDOW_WIDTH_INITIAL,
		WINDOW_HEIGHT_INITIAL, AnalogueClock::draw);
	window_of_clock.run();
	return 0;
}

