#ifndef COLOR_H
#define COLOR_H

/**
 * Defines some basic colors which our program uses
 */
struct Color
{	float r;
	float g;
	float b;
	
	static const Color black;
	static const Color white;
	static const Color red;
	static const Color grey;
	static const Color yellow_light;
};

constexpr Color Color::black{0, 0, 0};
constexpr Color Color::white{1, 1, 1};
constexpr Color Color::red{1, 0, 0};
constexpr Color Color::grey{0.5, 0.5, 0.5};
constexpr Color Color::yellow_light{1, 1, 0.6};

#endif
