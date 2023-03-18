#ifndef ANALOGUE_CLOCK_H
#define ANALOGUE_CLOCK_H

#include "system_time.h"
#include "shape.h"
#include "color.h"
#include "property_clock.h"

#include <algorithm>

/**
 * class AnalogueClock contains methods to make the clock appear
 * All properties of the class is defined in the header property_clock.h
 */
 
class AnalogueClock
{
	/**
	 * Fixes the correct drawing area
	 * Clears the background with PropertyClock::Main::bgcolor_window
	 */
	static void setup_draw_area(const int window_width, const int window_height);
	
	/**
	 * Draws the three circles of the clock, outer border, the clock, and the pin/ring
	 */
	static void draw_outer_circle();
	static void draw_inner_circle();
	static void draw_centre_ring();
	
	/**
	 * Draws the major and minor marks, which are radially distributed
	 */
	static void draw_clock_marks(const PropertyClock::Mark& property_mark);
	static void draw_minor_marks();
	static void draw_major_marks();
	
	/**
	 * Draws the hands of the clock
	 */
	static void draw_hand(const PropertyClock::Hand& property_hand, const int angle);
	static void draw_hand_hour(const int angle);
	static void draw_hand_min(const int angle);
	static void draw_hand_sec(const int angle);
	static void draw_hands();
	
	

public:
	/**
	 * This function can be given to the constructor of SDLWindow
	 * SDLWindow::SDLWindow(title, width, height, draw)
	 */
	static void draw(const int window_width, const int window_height);
};
#endif
