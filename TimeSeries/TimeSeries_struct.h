#pragma once

#ifndef TIME_SERIES_STRUCT__H
#define TIME_SERIES_STRUCT__H
/* Deps */
#include "DateTime_struct.h"
#include <map>

/* Structure */
template <typename V>
struct TimeSeries
{
	/*
		# Time Series (structure)

		## Description
		A template which can store a value with an associated date-time. Accessible 
		through a DateTime object, or a string with the correct DateTime format of 
		`DD-MM-YYYY @ HH:mm:SS`.

	*/

	/* Elements */
	std::map<DateTime, V> data;

	/* Methods */

	// Constructors & Destructor
	TimeSeries()
	{
		this->data.clear(); // Ensures things are clean.
	};
	virtual ~TimeSeries()
	{
		this->data.clear(); // Clean up after yourself!
	};

	// Access Operators
	inline V* getValue(const DateTime& key)
	{
		if (this->data.find(key) != this->data.end())
		{
			return &this->data[key];
		};
		return 0;
	};
	inline V& operator[](const DateTime& key)
	{
		return this->data[key];
	};
	inline V& operator[](const std::string& s)
	{
		return this->data[DateTime(s)];
	};

	// Serialization
	inline std::string toJSON(std::string(*convertValueToJSON)(const V& value)) const
	{
		std::string json = "{";
		for (auto itr = this->data.begin(); itr != this->data.end(); itr++)
		{
			if (itr != this->data.begin())
			{
				json += ",";
			};

			json += "\"" + itr->first.toString() + "\":" + convertValueToJSON(itr->second);
		};
		json += "}";
		return json;
	};

	// Deserialization
	void fromJSON(const std::string& json, const V(*parseValue)(const std::string& json))
	{
		/*
			Given JSON of the format, `{ 'DD-MM-YYYY @ HH:mm:SS`: value, ... }` and a 
			function for parsing the value's JSON, will parse it out into this structure.
		*/

		// @todo - a much bigger implementation than toJSON(), that's for sure.
		// Also...goodness, manually parsing JSON in raw C++ is a pain in the butt!
		return;
	};

};
#endif