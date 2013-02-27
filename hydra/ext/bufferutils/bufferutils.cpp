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

	size_t totalPixels = dimensions.x * dimensions.y;
	size_t sbypp = pixel::getByteSize( sformat );
	size_t tbypp = pixel::getByteSize( tformat );

	size_t ttotal = totalPixels * tbypp;
	size_t stotal = totalPixels * sbypp;

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
			const unsigned char *u8source = (const unsigned char*)source;
			switch( tformat )
			{
				case pixel::RGBA8 :
				{
					unsigned char *u8target = (unsigned char*)target;
					for( size_t i = 0 ; i < totalPixels ; ++i )
					{
						u8target[ i * 4 + 0 ] = u8source[ i * 3 + 0 ];
						u8target[ i * 4 + 1 ] = u8source[ i * 3 + 1 ];
						u8target[ i * 4 + 2 ] = u8source[ i * 3 + 2 ];
						u8target[ i * 4 + 3 ] = 0xFF;
					}
					return true;
				}
				case pixel::ARGB8 :
				{
					for( size_t i = 0 ; i < totalPixels ; ++i )
					{
						unsigned char *u8target = (unsigned char*)target;
						u8target[ i * 4 + 0 ] = 0xFF;
						u8target[ i * 4 + 1 ] = u8source[ i * 3 + 0 ];
						u8target[ i * 4 + 2 ] = u8source[ i * 3 + 1 ];
						u8target[ i * 4 + 3 ] = u8source[ i * 3 + 2 ];
					}
					return true;
				}
				case pixel::RGBA16 :
				{
					unsigned short *u16target = (unsigned short*)target;
					for( size_t i = 0 ; i < totalPixels ; ++i )
					{
						u16target[ i * 4 + 0 ] = ((unsigned int)u8source[ i * 3 + 0 ]) << 8;
						u16target[ i * 4 + 1 ] = ((unsigned int)u8source[ i * 3 + 1 ]) << 8;
						u16target[ i * 4 + 2 ] = ((unsigned int)u8source[ i * 3 + 2 ]) << 8;
						u16target[ i * 4 + 3 ] = 0xFF;
					}
					return true;
				}
				case pixel::RGBA32 :
				{
					unsigned int *u32target = (unsigned int*)target;
					for( size_t i = 0 ; i < totalPixels ; ++i )
					{
						u32target[ i * 4 + 0 ] = ((unsigned int)u8source[ i * 3 + 0 ]) << 24;
						u32target[ i * 4 + 1 ] = ((unsigned int)u8source[ i * 3 + 1 ]) << 24;
						u32target[ i * 4 + 2 ] = ((unsigned int)u8source[ i * 3 + 2 ]) << 24;
						u32target[ i * 4 + 3 ] = 0xFF;
					}
					return true;
				}
				case pixel::RGB565 :
				case pixel::RGBA4 :
				case pixel::RGBA5551 :
				case pixel::RGBA32F :
				case pixel::RGBA12 :
				case pixel::ALPHA8 :
				case pixel::LUMINANCE :
				case pixel::INTENSITY :
				case pixel::DEPTH8 :
				case pixel::DEPTH16 :
				case pixel::DEPTH24 :
				case pixel::DEPTH32 :
				default:
				{
					break;
				}
			}
			break;
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
