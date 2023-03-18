#include "analogue_clock.h"

void AnalogueClock::setup_draw_area(const int window_width, const int window_height)
{
	const int window_length =
		PropertyClock::Main::proportion_of_window *
		std::min(window_width, window_height);
		
	const int window_x_begin = (window_width - window_length) / 2;
	const int window_y_begin = (window_height - window_length) / 2;
	
	glViewport(window_x_begin, window_y_begin,
		window_length, window_length);
	
	Shape::clear_color(PropertyClock::Main::bgcolor_window);
}

void AnalogueClock::draw_outer_circle()
{
	Shape::draw_circle(0, 0, 1, PropertyClock::Main::color_border);
}

void AnalogueClock::draw_inner_circle()
{
	
	Shape::draw_circle(0, 0,
		1.0 - PropertyClock::Main::thickness_border,
		PropertyClock::Main::bgcolor_clock);
}

void AnalogueClock::draw_clock_marks(const PropertyClock::Mark& property_mark)
{
	const float begin = PropertyClock::Main::working_radius - property_mark.height;
	const float end = PropertyClock::Main::working_radius;
	for(int i = 0; i < property_mark.number; ++ i)
	{
		const int angle = 360 * i / property_mark.number;
		Shape::draw_strip(0, 0, angle, begin, end,
			property_mark.width, property_mark.color);
	}
}

void AnalogueClock::draw_minor_marks()
{
	draw_clock_marks(PropertyClock::Mark::minor);
}

void AnalogueClock::draw_major_marks()
{
	draw_clock_marks(PropertyClock::Mark::major);
}

void AnalogueClock::draw_hand(const PropertyClock::Hand& property_hand, const int angle)
{
	const float effective_length =
		PropertyClock::Main::working_radius * property_hand.height;
	
	const float begin =
		-PropertyClock::Hand::hand_back_extend * effective_length;
	
	Shape::draw_strip(0, 0, angle, begin, effective_length,
		property_hand.width, property_hand.color);
}

void AnalogueClock::draw_hand_hour(const int angle)
{
	draw_hand(PropertyClock::Hand::hour, angle);
}

void AnalogueClock::draw_hand_min(const int angle)
{
	draw_hand(PropertyClock::Hand::min, angle);
}

void AnalogueClock::draw_hand_sec(const int angle)
{
	draw_hand(PropertyClock::Hand::sec, angle);
}

void AnalogueClock::draw_hands()
{
	const SystemTime system_time;
	draw_hand_hour(system_time.angle_hour());
	draw_hand_min(system_time.angle_min());
	draw_hand_sec(system_time.angle_sec());
}

void AnalogueClock::draw_centre_ring()
{
	Shape::draw_circle(0, 0, PropertyClock::Main::radius_center_pin,
		PropertyClock::Main::color_center_pin);
}

void AnalogueClock::draw(const int window_width, const int window_height)
{
	setup_draw_area(window_width, window_height);
	draw_outer_circle();
	draw_inner_circle();
	draw_minor_marks();
	draw_major_marks();
	draw_hands();
	draw_centre_ring();
}

