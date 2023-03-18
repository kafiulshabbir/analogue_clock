#include "shape.h"

float Shape::to_radians(const int degree)
{
	return pi / degrees_in_circle * 2 * (degree % degrees_in_circle);
}

float Shape::sin(const float degree)
{
	return std::sin(to_radians(degree));
}

float Shape::cos(const float degree)
{
	return std::cos(to_radians(degree));
}

void Shape::set_color(const Color& color)
{
	glColor3f(color.r, color.g, color.b);
}

void Shape::clear_color(const Color& color)
{
	glClearColor(color.r, color.g, color.b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Shape::draw_circle(const float x, const float y,
	const float radius, const Color& color)
{
	set_color(color);
	glBegin(GL_POLYGON);
	for(int angle = 0; angle < degrees_in_circle; ++ angle)
	{
		const float x_circle = x + radius * cos(angle);
		const float y_circle = y + radius * sin(angle);
		glVertex2f(x_circle, y_circle);
	}
	
	glEnd();
}

void Shape::draw_strip(const float x, const float y,
	const int angle, const float begin, const float end,
	const float thickness, const Color& color)
{
	set_color(color);
	const float x_disp = thickness * cos(angle) / 2;
	const float y_disp = thickness * sin(angle) / 2;
	
	const float x_begin = x + begin * sin(angle);
	const float y_begin = y + begin * cos(angle);
	const float x_end= x + end * sin(angle);
	const float y_end = y + end * cos(angle);
	
	glBegin(GL_POLYGON);
		glVertex2f(x_begin + x_disp, y_begin - y_disp);
		glVertex2f(x_begin - x_disp, y_begin + y_disp);
		glVertex2f(x_end - x_disp, y_end + y_disp);
		glVertex2f(x_end + x_disp, y_end - y_disp);
	glEnd();
}
