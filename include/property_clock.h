#ifndef PROPERTY_CLOCK_H
#define PROPERTY_CLOCK_H

#include "color.h"

/**
 * Defines the properties of the clock which changes its appearence
 */
 
struct PropertyClock
{
	/**
	 * The main properties which define the clock, such as
	 * what proportion of the window must the clock occupy
	 * thickness of the outer border
	 * how much distance must the marks be from the border
	 * size of centre pin/ring
	 * working radius, which is the maximum possible length of a hand
	 * various colors
	 */
	struct Main
	{
		static constexpr float proportion_of_window = 0.80;
		static constexpr float thickness_border = 0.05;
		static constexpr float gap_mark_from_border = 0.01;
		static constexpr float radius_center_pin = 0.05;
		static constexpr float working_radius = 1.0 - thickness_border - gap_mark_from_border;
		static constexpr Color bgcolor_window = Color::yellow_light;
		static constexpr Color bgcolor_clock = Color::white;
		static constexpr Color color_border = Color::black;
		static constexpr Color color_center_pin = Color::grey;
	};
	
	/**
	 * Here minor marks are used for a minute and major for every hour
	 */
	struct Mark
	{
		float width;
		float height;
		float number;
		Color color;
		
		static const Mark major;
		static const Mark minor;
	};
	
	struct Hand
	{
		float width;
		float height;
		Color color;
		
		static constexpr float hand_back_extend = 0.3;
		
		static const Hand sec;
		static const Hand min;
		static const Hand hour;
	};
};

/**
 * Major = 12
 * Minor = 60
 * This is the most standard configuration
 * If the user wants to have only major marks, due to low resolution screen
 * It can be made invisible by setting the Mark.number = 0
 */
constexpr PropertyClock::Mark PropertyClock::Mark::major
	{0.06, 0.15, 12, Color::grey};
	
constexpr PropertyClock::Mark PropertyClock::Mark::minor
	{0.03, 0.05, 60, Color::grey};

/**
 * note that the height is the length of the hand in proportion of the working_radius
 */	
constexpr PropertyClock::Hand PropertyClock::Hand::sec
	{0.02, 0.75, Color::red};
	
constexpr PropertyClock::Hand PropertyClock::Hand::min
	{0.04, 0.9, Color::black};
	
constexpr PropertyClock::Hand PropertyClock::Hand::hour
	{0.08, 0.6, Color::black};

#endif
