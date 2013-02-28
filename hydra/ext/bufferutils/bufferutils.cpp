/*
 * bufferutils.cpp
 *
 *  Created on: 27.2.2013
 *      Author: akin
 */

#include "bufferutils.h"
#include <cstring>

#include "buffertransform.hpp"

namespace buffer {
namespace utils {

bool transformColor(
		const void *source ,
		size_t slen ,
		pixel::Format sformat ,
		void *target ,
		size_t tlen ,
		pixel::Format tformat ,
		const glm::ivec2& dimensions )
{
	/*
	 * pixel::Format :
	NONE = 0,
	RGB8 = 1,
	RGBA8 = 2,
	ARGB8 = 3,
	ALPHA8 = 4,
	LUMINANCE = 5,
	INTENSITY = 6,
	RGBA12 = 7,
	RGBA16 = 8,
	RGBA32 = 9,
	RGBA32F = 10,
	DEPTH8 = 11,
	DEPTH16 = 12,
	DEPTH24 = 13,
	DEPTH32 = 14,
	RGB565 = 15,
	RGBA4 = 16,
	RGBA5551 = 17,
	*/

	size_t pixelcount = dimensions.x * dimensions.y;
	size_t sbypp = pixel::getByteSize( sformat );
	size_t tbypp = pixel::getByteSize( tformat );

	size_t ttotal = pixelcount * tbypp;
	size_t stotal = pixelcount * sbypp;

	// will it fit?
	// is there anything there?
	if( (stotal <= slen && ttotal <= tlen) || stotal < 1 || ttotal < 1 )
	{
		return false;
	}

	// 1:1 copy
	if( sformat == tformat )
	{
		::memcpy( target , source , ttotal );
		return true;
	}

	switch( sformat )
	{
		case pixel::RGB8 :
		{
			return transformRGB8( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::RGBA8 :
		{
			break;
		}
		default:
		{
			break;
		}
	}
	return false;
}

} // namespace utils
} // namespace buffer
