#pragma once

#ifndef DATE_TIME_STRUCT__H
#define DATE_TIME_STRUCT__H
/* Deps */
#include "ClockTime_struct.h"
#include "Date_struct.h"
#include <algorithm>

struct DateTime
{
	/* Elements */
	Date date;
	ClockTime time;

	/* Methods */

	// ConstructorS & Destructor
	DateTime()
	{
		return;
	};
	DateTime(const DateTime& src)
	{
		this->time = src.time;
		this->date = src.date;
	};
	DateTime(const std::string& str)
	{
		this->fromString(str);
	};
	virtual ~DateTime()
	{
		return;
	};

	// Comparison Operators
	inline bool compare(const DateTime& that) const
	{
		/*
			Returns true if this is less than that.
		*/

		if (this->date.year == that.date.year)
		{
			if (this->date.month == that.date.month)
			{
				if (this->date.day == that.date.day)
				{
					if (this->time.hours == that.time.hours)
					{
						if (this->time.minutes == that.time.minutes)
						{
							return (this->time.seconds < that.time.seconds);
						};
						return (this->time.minutes < that.time.minutes);
					};
					return (this->time.hours < that.time.hours);
				};
				return (this->date.day < that.date.day);
			};
			return (this->date.month < that.date.month);
		};
		return (this->date.year < that.date.year);
	};
	inline bool operator<(const DateTime& that) const
	{
		return this->compare(that);
	};
	inline bool operator>(const DateTime& that) const
	{
		return that.compare(*this);
	};
	inline bool operator==(const DateTime& that) const
	{
		return (!this->compare(that) && !that.compare(*this));
	};

	// Serialization
	inline std::string toString() const
	{
		return (this->date.toString() + "@" + this->time.toString());
	};

	// Deserialization
	void fromString(const std::string& str)
	{
		/*
			Parses a string of the format, 'DD-MM-YYYY @ HH:mm:SS`.
		*/

		// @todo - add a string check somehow. I don't like how fragile this is.

		// Strip whitepsace, GPT code.
		std::string s = str;
		s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end()); // Interesting algorithm trick.

		// Find the @ to split on,
		size_t atPosition = s.find("@");
		
		// If `@` found, load up!
		if (atPosition != std::string::npos)
		{
			this->date.fromString(s.substr(0, atPosition));
			this->time.fromString(s.substr(atPosition+1));
		};
		
		// Otherwise, malformed - do nothing.
	};
};
#endif