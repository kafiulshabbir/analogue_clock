#ifndef SHAPE_H
#define SHAPE_H
#include "color.h"

#include "glad/glad.h"
#include <cmath>

/**
 * Uses only OpenGL to draw some shapes
 */
class Shape
{
	static constexpr float pi = std::acos(-1);
	static constexpr int degrees_in_circle = 360;
	
	/**
	 * Local mathematical functions
	 */
	static float to_radians(const int degree);
	static float sin(const float degree);
	static float cos(const float degree);
	
public:
	static void set_color(const Color& color);
	static void clear_color(const Color& color);
	
	/**
	 * The circle is solid
	 */
	static void draw_circle(const float x, const float y,
		const float radius, const Color& color);
	
	/**
	 * Strip is a line
	 * It begins at (x, y)
	 * It makes an angle with the vertical clock-wise direction
	 * It extends from begin to end as proportion to the screen
	 * The the thickness is the length perpendicular to the direction
	 */
	static void draw_strip(const float x, const float y,
		const int angle, const float begin, const float end,
		const float thickness, const Color& color);
};

#endif
