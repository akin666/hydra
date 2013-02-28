/*
 * buffertransform.hhh
 *
 *  Created on: 28.2.2013
 *      Author: akin
 */

#ifndef BUFFERTRANSFORMUTILS_H_
#define BUFFERTRANSFORMUTILS_H_

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

} // namespace utils
} // namespace buffer

#endif
