/*
 * bufferutils.cpp
 *
 *  Created on: 27.2.2013
 *      Author: akin
 */

#include "bufferutils.h"
#include <cstring>

namespace buffer {
namespace utils {

bool transformRGB8toRGBA8( const unsigned char *source , unsigned char *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = source[ i * 3 + 0 ];
		target[ i * 4 + 1 ] = source[ i * 3 + 1 ];
		target[ i * 4 + 2 ] = source[ i * 3 + 2 ];
		target[ i * 4 + 3 ] = 0xFF;
	}
	return true;
}
bool transformRGB8toARGB8( const unsigned char *source , unsigned char *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = 0xFF;
		target[ i * 4 + 1 ] = source[ i * 3 + 0 ];
		target[ i * 4 + 2 ] = source[ i * 3 + 1 ];
		target[ i * 4 + 3 ] = source[ i * 3 + 2 ];
	}
	return true;
}
bool transformRGB8toRGB565( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	// TODO
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = 0xFF;
		target[ i * 4 + 1 ] = source[ i * 3 + 0 ];
		target[ i * 4 + 2 ] = source[ i * 3 + 1 ];
		target[ i * 4 + 3 ] = source[ i * 3 + 2 ];
	}
	return false;
}
bool transformRGB8toRGBA4( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	// TODO
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = 0xFF;
		target[ i * 4 + 1 ] = source[ i * 3 + 0 ];
		target[ i * 4 + 2 ] = source[ i * 3 + 1 ];
		target[ i * 4 + 3 ] = source[ i * 3 + 2 ];
	}
	return false;
}
bool transformRGB8toRGBA5551( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	// TODO
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = 0xFF;
		target[ i * 4 + 1 ] = source[ i * 3 + 0 ];
		target[ i * 4 + 2 ] = source[ i * 3 + 1 ];
		target[ i * 4 + 3 ] = source[ i * 3 + 2 ];
	}
	return false;
}
bool transformRGB8toRGBA12( const unsigned char *source , unsigned char *target , size_t pixelcount )
{
	// TODO
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = 0xFF;
		target[ i * 4 + 1 ] = source[ i * 3 + 0 ];
		target[ i * 4 + 2 ] = source[ i * 3 + 1 ];
		target[ i * 4 + 3 ] = source[ i * 3 + 2 ];
	}
	return false;
}
bool transformRGB8toRGBA16( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = ((unsigned int)source[ i * 3 + 0 ]) << 8;
		target[ i * 4 + 1 ] = ((unsigned int)source[ i * 3 + 1 ]) << 8;
		target[ i * 4 + 2 ] = ((unsigned int)source[ i * 3 + 2 ]) << 8;
		target[ i * 4 + 3 ] = 0xFFFF;
	}
	return true;
}
bool transformRGB8toRGBA32( const unsigned char *source , unsigned int *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = ((unsigned int)source[ i * 3 + 0 ]) << 24;
		target[ i * 4 + 1 ] = ((unsigned int)source[ i * 3 + 1 ]) << 24;
		target[ i * 4 + 2 ] = ((unsigned int)source[ i * 3 + 2 ]) << 24;
		target[ i * 4 + 3 ] = 0xFFFFFFFF;
	}
	return true;
}
bool transformRGB8toRGBA32F( const unsigned char *source , float *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = source[ i * 3 + 0 ] / 256.0f;
		target[ i * 4 + 1 ] = source[ i * 3 + 1 ] / 256.0f;
		target[ i * 4 + 2 ] = source[ i * 3 + 2 ] / 256.0f;
		target[ i * 4 + 3 ] = 1.0f;
	}
	return false;
}

bool transformRGB8(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	switch( tformat )
	{
		case pixel::RGBA8 :
		{
			return transformRGB8toRGBA8( source , (unsigned char *)target , pixelcount );
		}
		case pixel::ARGB8 :
		{
			return transformRGB8toARGB8( source , (unsigned char *)target , pixelcount );
		}
		case pixel::RGBA16 :
		{
			return transformRGB8toRGBA16( source , (unsigned short *)target , pixelcount );
		}
		case pixel::RGBA32 :
		{
			return transformRGB8toRGBA32( source , (unsigned int *)target , pixelcount );
		}
		case pixel::RGB565 :
		{
			return transformRGB8toRGB565( source , (unsigned short *)target , pixelcount );
		}
		case pixel::RGBA4 :
		{
			return transformRGB8toRGBA4( source , (unsigned short *)target , pixelcount );
		}
		case pixel::RGBA5551 :
		{
			return transformRGB8toRGBA5551( source , (unsigned short *)target , pixelcount );
		}
		case pixel::RGBA32F :
		{
			return transformRGB8toRGBA32F( source , (float *)target , pixelcount );
		}
		case pixel::RGBA12 :
		{
			return transformRGB8toRGBA12( source , (unsigned char *)target , pixelcount );
		}
		default:
		{
			break;
		}
	}
	return false;
}

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
