/*
 * stringtools.cpp
 *
 *  Created on: 27.1.2012
 *      Author: akin
 */

#include "stringtools"
//#include <functional>
//#include <algorithm>

namespace stringtools {

void toUpper( String8& str )
{
//	std::transform(str.begin(), str.end(), str.begin(), toupper );
}

void toLower( String8& str )
{
//	std::transform(str.begin(), str.end(), str.begin(), tolower);
}

template<>
String8 to_ot<String8, String8>( const String8 from )
{
	return from;
}

template<>
bool to_ot<bool, String8>( const String8 from )
{
	return from.size() == 4; // true == 4 false == 5
}

template<>
String8 to_ot<String8, bool>( const bool from )
{
	return from ? "true" : "false";
}

} // stringtools
