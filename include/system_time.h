#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <chrono>
#include <ctime>

class SystemTime
{
	static constexpr int sec_per_min = 60;
	static constexpr int min_per_hour = 60;
	static constexpr int hour_per_clock = 12;
	
	/**
	 * tm
	 * Structure holding a calendar date and time broken down into its components
	 * Contains:
	 * 	tm_sec
	 * 	...
	 * 	tm_year
	 * 
	 * For details, see:
	 * https://en.cppreference.com/w/cpp/chrono/c/tm
	 */
	std::tm* t;
	
public:
	/**
	 * The constructor of the class injects the current computer time into tm
	 */
	SystemTime();
	
	/**
	 * methods to output the hour, min, and sec as integers
	 */
	int sec() const;
	int min() const;
	int hour() const;
	
	/**
	 * The angle is given in degrees as integers
	 * Example:
	 * 	0	sec	= 0		deg
	 *  30	sec	= 180 	deg
	 * 	45	sec	= 270 	deg
	 * 	30	min	= 180 	deg
	 * 	1	hour = 30 	deg
	 * 	11	hour = 330 	deg
	 *  13	hour = 30 	deg
	 */
	int angle_sec() const;
	int angle_min() const;
	int angle_hour() const;
};

#endif
