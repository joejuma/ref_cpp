#pragma once

#ifndef CLOCK_TIME_STRUCT__H
#define CLOCK_TIME_STRUCT__H
/* Deps */
#include <stdint.h>
#include <string>

/* Structure */
struct ClockTime
{
	/*
		# Clock-Time (structure)

		## Description
		A simple structure representing time in hours, minutes and seconds.
	*/

	/* Elements */
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;

	/* Methods */

	// Constructors & Destructor
	ClockTime()
	{
		this->seconds = 0;
		this->minutes = 0;
		this->hours = 0;
	};
	ClockTime(const uint8_t& s, const uint8_t& m, const uint8_t& h )
	{
		this->seconds = s;
		this->minutes = m;
		this->hours = h;
	};
	ClockTime(const ClockTime& src)
	{
		this->seconds = src.seconds;
		this->minutes = src.minutes;
		this->hours = src.hours;
	};
	virtual ~ClockTime()
	{
		this->seconds = 0;
		this->minutes = 0;
		this->hours = 0;
	};

	// Comparison
	inline bool compare(const ClockTime& that) const
	{
		if (this->hours == that.hours)
		{
			if (this->minutes == that.minutes)
			{
				return (this->seconds < that.seconds);
			};
			return (this->minutes < that.minutes);
		};
		return (this->hours < that.hours);
	};
	inline bool operator<(const ClockTime& that) const
	{
		return this->compare(that);
	};
	inline bool operator>(const ClockTime& that) const
	{
		return that.compare(*this);
	};
	inline bool operator==(const ClockTime& that) const
	{
		return (!this->compare(that) && !that.compare(*this));
	};

	// Serialization
	inline std::string toString() const
	{
		return (
			((this->hours < 10) ? "0" + std::to_string(this->hours) : std::to_string(this->hours)) + ":" +
			((this->minutes < 10) ? "0" + std::to_string(this->minutes) : std::to_string(this->minutes)) + ":" +
			((this->seconds < 10) ? "0" + std::to_string(this->seconds) : std::to_string(this->seconds))
		);
		// @note - a strange bug. When I made this more elegant by doing check?"0":"" + std::to_string(value), it broke. I should figure out why and make it better again.
	};

	// Deserialization
	inline void fromString(const std::string& str)
	{
		/*
			Parses a string of format `HH:MM:SS`
		*/

		// @todo: add some kind of string validation here, as this is too fragile for my liking.

		this->hours = std::stoi(str.substr(0, 2));
		this->minutes = std::stoi(str.substr(3, 2));
		this->seconds = std::stoi(str.substr(6, 2));
	};
};
#endif