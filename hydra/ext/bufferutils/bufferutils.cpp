/*
 * bufferutils.cpp
 *
 *  Created on: 27.2.2013
 *      Author: akin
 */

#include "bufferutils.h"
#include <cstring>
#include <limits>

namespace buffer {
namespace utils {

template <typename TargetType>
bool transformRGB8toRGBA( const unsigned char *source , TargetType *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = source[ i * 3 + 0 ];
		target[ i * 4 + 1 ] = source[ i * 3 + 1 ];
		target[ i * 4 + 2 ] = source[ i * 3 + 2 ];
		target[ i * 4 + 3 ] = std::numeric_limits<TargetType>::max();
	}
	return true;
}
// float specialization
template <>
bool transformRGB8toRGBA<float>( const unsigned char *source , float *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = source[ i * 3 + 0 ] / 256.0f;
		target[ i * 4 + 1 ] = source[ i * 3 + 1 ] / 256.0f;
		target[ i * 4 + 2 ] = source[ i * 3 + 2 ] / 256.0f;
		target[ i * 4 + 3 ] = 1.0f;
	}
	return true;
}
// double specialization
template <>
bool transformRGB8toRGBA<double>( const unsigned char *source , double *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = source[ i * 3 + 0 ] / 256.0;
		target[ i * 4 + 1 ] = source[ i * 3 + 1 ] / 256.0;
		target[ i * 4 + 2 ] = source[ i * 3 + 2 ] / 256.0;
		target[ i * 4 + 3 ] = 1.0;
	}
	return true;
}
template <typename TargetType>
bool transformRGB8toARGB( const unsigned char *source , TargetType *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = std::numeric_limits<TargetType>::max();
		target[ i * 4 + 1 ] = source[ i * 3 + 0 ];
		target[ i * 4 + 2 ] = source[ i * 3 + 1 ];
		target[ i * 4 + 3 ] = source[ i * 3 + 2 ];
	}
	return true;
}
bool transformRGB8toRGB565( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i ] =
				(((unsigned int)source[ i * 3 + 0 ] << 8 ) & 0xF800 ) |
				(((unsigned int)source[ i * 3 + 1 ] << 3 ) & 0x7E0 ) |
				(((unsigned int)source[ i * 3 + 2 ] >> 3 ) & 0x1F );
	}
	return true;
}
bool transformRGB8toRGBA4( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i ] =
				(((unsigned int)source[ i * 3 + 0 ] << 8 ) & 0xF000 ) |
				(((unsigned int)source[ i * 3 + 1 ] << 4 ) & 0x0F00 ) |
				(((unsigned int)source[ i * 3 + 1 ] ) & 0x00F0 ) |
				0x000F;
	}
	return true;
}
bool transformRGB8toRGBA5551( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i ] =
				(((unsigned int)source[ i * 3 + 0 ] << 8 ) & 0xF800 ) |
				(((unsigned int)source[ i * 3 + 1 ] << 3 ) & 0x7E0 ) |
				(((unsigned int)source[ i * 3 + 2 ] >> 2 ) & 0x1F ) |
				(((unsigned int)source[ i * 3 + 2 ] >> 7 ) & 0x1 );
	}
	return true;
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
			return transformRGB8toRGBA( source , (unsigned char *)target , pixelcount );
		}
		case pixel::ARGB8 :
		{
			return transformRGB8toARGB( source , (unsigned char *)target , pixelcount );
		}
		case pixel::RGBA16 :
		{
			return transformRGB8toRGBA( source , (unsigned short *)target , pixelcount );
		}
		case pixel::RGBA32 :
		{
			return transformRGB8toRGBA( source , (unsigned int *)target , pixelcount );
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
			return transformRGB8toRGBA( source , (float *)target , pixelcount );
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
