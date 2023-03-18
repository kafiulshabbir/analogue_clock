#include "system_time.h"

SystemTime::SystemTime()
{
	const auto time_point_system = std::chrono::system_clock::now();
	const auto time_t_system = std::chrono::system_clock::to_time_t(time_point_system);
	t = std::localtime(&time_t_system);
}

int SystemTime::sec() const
{
	return t->tm_sec;
}

int SystemTime::min() const
{
	return t->tm_min;
}

int SystemTime::hour() const
{
	return t->tm_hour;
}

int SystemTime::angle_sec() const
{
	return 6 * sec();
}

int SystemTime::angle_min() const
{
	return (360 * (min() * sec_per_min + sec())) / sec_per_min / min_per_hour;
}

int SystemTime::angle_hour() const
{
	return (360 * ((hour() % hour_per_clock) * min_per_hour + min())) / min_per_hour / hour_per_clock;
}		
