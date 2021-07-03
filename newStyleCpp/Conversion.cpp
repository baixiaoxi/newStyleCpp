#include "Conversion.h"

bool Conversion::test() {
	double d = 1.58947;
	int i = d;  // warning C4244 possible loss of data
	int j = static_cast<int>(d);       // No warning.
	// std::string s = static_cast<std::string>(d); // Error C2440:cannot convert from
	// double to std:string

	const char* str = "hello";
	// int i = static_cast<int>(str);//error C2440: 'static_cast' : cannot
	// convert from 'const char *' to 'int'
	int m = (int)str; // C-style cast. Did the programmer really intend
	// to do this?
	int k = reinterpret_cast<int>(str);// Programming intent is clear.
	// However, it is not 64-bit safe.

	return true;
}