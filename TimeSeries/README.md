# Time Series - Reference Implementation (C++)

## What is it?
A reference implementation of a container that can map a time-string in 
the format `DD-MM-YYYY @ hh:mm:ss` with an arbitrary value of a given 
template argument type. Includes several additional structures which 
represent date and time (DateTime, Date, ClockTime) in explicit 
structures rather than by performing calculations on large integer 
timestamps.

## How to use?
### General Usage
1. Download all four *.h files.
2. Put them where you want in your project.
3. Add `#include "TimeSeries_struct.h"` to the files you want to use it 
in.
4. `TimeSeries<yourDataType> series;` to instantiate a time series 
object.
5. `series["01-01-1999 @ 00:00:01"] = someValue;` to set the value.
6. `series["01-01-1999 @ 00:00:01"]` to get that same value.
7. That's really all there is!

### Serialization & Deserialization
Special note should be made about serialization, converting a 
time-series to a string, which is in JSON format, and deserialization 
,loading from a string, in JSON format. Since this is a template, the 
user must provided a function pointer to serializing/deserializing 
functions when using the respective methods. For example,

**Serialization**
```
	std::string convertFloatToString(const float& value)
	{
		return std::to_string(value);
	};
	
	TimeSerieS<float> mySeries;
	// Some code that adds values goes here...
	std::cout << mySeries.toJSON(&convertFloatToString) << "\n";
	
```
**Deserialization**
```
	float convertStringToFloat(const std::string& str)
	{
		return std::stof(str);
	};
	
	TimeSeries<float> mySeries;
	// Load a JSON string of a dictionary of time-keyed floating 
point values.
	
	mySeries.fromJSON(json, &convertStringToFloat);
```

## To-Do
1. Implement deserialization methods to load a TimeSeries from JSON.
2. Look at the existing @todo in code.
3. Look into changing the interface so that fetching non-existant values 
returns the closest, past time-keyed value, while still allowing 
assignment to create new keys.

## License
See LICENSE.md

## Authors
Joseph M. Juma, ChatGPT
