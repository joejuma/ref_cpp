#pragma once

#ifndef DATE_STRUCT__H
#define DATE_STRUCT__H
/* Deps */
#include <stdint.h>
#include <string>

/* Structure */
struct Date
{
	/*
		# Date (structure)

		## Description
		A simple class for tracking the date. Allocated in discrete integers for ease 
		of use.
	*/

	/* Elements */
	uint8_t day;
	uint8_t month;
	uint32_t year;

	/* Methods */

	// Constructors & Destructor
	Date()
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;
	};
	Date(const uint8_t& d, const uint8_t& m, const uint32_t& y)
	{
		this->day = d;
		this->month = m;
		this->year = y;
	};
	Date(const Date& src)
	{
		this->day = src.day;
		this->month = src.month;
		this->year = src.year;
	};
	virtual ~Date()
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;
	};

	// Comparison
	inline bool compare(const Date& that) const
	{
		/*
			Returns true if this is less than that.
		*/

		if (this->year == that.year)
		{
			if (this->month == that.month)
			{
				return (this->day < that.day);
			};
			return (this->month < that.month);
		};
		return (this->year < that.year);
	};
	inline bool operator<(const Date& that) const
	{
		return this->compare(that);
	};
	inline bool operator>(const Date& that) const
	{
		return that.compare(*this);
	};
	inline bool operator==(const Date& that) const
	{
		return (!this->compare(that) && !that.compare(*this));
	};

	// Serialization
	inline std::string toString() const
	{
		return (
			((this->day < 10) ? "0" + std::to_string(this->day) : std::to_string(this->day)) + "-" +
			((this->month < 10) ? "0" + std::to_string(this->month) : std::to_string(this->month)) + "-" +
			std::to_string(this->year)
		);
		// @note - a strange bug. When I made this more elegant by doing check?"0":"" + std::to_string(value), it broke. I should figure out why and make it better again.
	};

	// Deserialization
	inline void fromString(const std::string& str)
	{
		/*
			Parses a string of format `DD-MM-YYYY`
		*/

		// @todo: add some kind of string validation here, as this is too fragile for my liking.

		this->day = std::stoi(str.substr(0, 2));
		this->month = std::stoi(str.substr(3, 2));
		this->year = std::stoi(str.substr(6, 4));
	};
};

#endif