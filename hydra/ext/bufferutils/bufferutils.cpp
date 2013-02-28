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
			return transformRGBA8( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::ARGB8 :
		{
			return transformARGB8( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::ALPHA8 :
		{
			return transformALPHA8( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::LUMINANCE :
		{
			return transformLUMINANCE( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::INTENSITY :
		{
			return transformINTENSITY( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::RGBA12 :
		{
			return transformRGBA12( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::RGBA16 :
		{
			return transformRGBA16( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::RGBA32 :
		{
			return transformRGBA32( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::RGBA32F :
		{
			return transformRGBA32F( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::DEPTH8 :
		{
			return transformDEPTH8( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::DEPTH16 :
		{
			return transformDEPTH16( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::DEPTH24 :
		{
			return transformDEPTH24( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::DEPTH32 :
		{
			return transformDEPTH32( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::RGB565 :
		{
			return transformRGB565( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::RGBA4 :
		{
			return transformRGBA4( (const unsigned char*)source , target , tformat , pixelcount );
		}
		case pixel::RGBA5551 :
		{
			return transformRGBA5551( (const unsigned char*)source , target , tformat , pixelcount );
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
