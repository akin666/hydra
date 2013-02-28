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

/////////
// RGB8
/////////
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
bool transformRGBA8toRGB565( const unsigned char *source , unsigned short *target , int mul , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i ] =
				(((unsigned int)source[ i * mul + 0 ] << 8 ) & 0xF800 ) |
				(((unsigned int)source[ i * mul + 1 ] << 3 ) & 0x7E0 ) |
				(((unsigned int)source[ i * mul + 2 ] >> 3 ) & 0x1F );
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
				0x1;
	}
	return true;
}
bool transformRGB8toRGBA12( const unsigned char *source , unsigned char *target , size_t pixelcount )
{
	// TODO
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
			return transformRGBA8toRGB565( source , (unsigned short *)target , 3 , pixelcount );
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

/////////
// RGBA8
/////////
template <typename TargetType>
bool transformRGBA8toRGBA( const unsigned char *source , TargetType *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = source[ i * 4 + 0 ];
		target[ i * 4 + 1 ] = source[ i * 4 + 1 ];
		target[ i * 4 + 2 ] = source[ i * 4 + 2 ];
		target[ i * 4 + 3 ] = source[ i * 4 + 3 ];
	}
	return true;
}
// float specialization
template <>
bool transformRGBA8toRGBA<float>( const unsigned char *source , float *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = source[ i * 4 + 0 ] / 256.0f;
		target[ i * 4 + 1 ] = source[ i * 4 + 1 ] / 256.0f;
		target[ i * 4 + 2 ] = source[ i * 4 + 2 ] / 256.0f;
		target[ i * 4 + 3 ] = source[ i * 4 + 3 ] / 256.0f;
	}
	return true;
}
// double specialization
template <>
bool transformRGBA8toRGBA<double>( const unsigned char *source , double *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 4 + 0 ] = source[ i * 4 + 0 ] / 256.0;
		target[ i * 4 + 1 ] = source[ i * 4 + 1 ] / 256.0;
		target[ i * 4 + 2 ] = source[ i * 4 + 2 ] / 256.0;
		target[ i * 4 + 3 ] = source[ i * 4 + 3 ] / 256.0;
	}
	return true;
}
template <typename TargetType>
bool transformRGBA8toRGB( const unsigned char *source , TargetType *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i * 3 + 0 ] = source[ i * 4 + 0 ];
		target[ i * 3 + 1 ] = source[ i * 4 + 1 ];
		target[ i * 3 + 2 ] = source[ i * 4 + 2 ];
	}
	return true;
}
template <typename TargetType>
bool transformRGBA8toARGB( const unsigned char *source , TargetType *target , size_t pixelcount )
{
	unsigned char alpha;
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		alpha = source[ i * 4 + 3 ];

		target[ i * 4 + 3 ] = source[ i * 4 + 2 ];
		target[ i * 4 + 2 ] = source[ i * 4 + 1 ];
		target[ i * 4 + 1 ] = source[ i * 4 + 0 ];
		target[ i * 4 + 0 ] = alpha;
	}
	return true;
}
bool transformRGBA8toRGBA4( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i ] =
				(((unsigned int)source[ i * 4 + 0 ] << 8 ) & 0xF000 ) |
				(((unsigned int)source[ i * 4 + 1 ] << 4 ) & 0x0F00 ) |
				(((unsigned int)source[ i * 4 + 2 ] )      & 0x00F0 ) |
				(((unsigned int)source[ i * 4 + 3 ] >> 4 ) & 0x000F );
	}
	return true;
}
bool transformRGBA8toRGBA5551( const unsigned char *source , unsigned short *target , size_t pixelcount )
{
	for( size_t i = 0 ; i < pixelcount ; ++i )
	{
		target[ i ] =
				(((unsigned int)source[ i * 4 + 0 ] << 8 ) & 0xF800 ) |
				(((unsigned int)source[ i * 4 + 1 ] << 3 ) & 0x7E0 ) |
				(((unsigned int)source[ i * 4 + 2 ] >> 2 ) & 0x1F ) |
				(((unsigned int)source[ i * 4 + 3 ] >> 7 ) & 0x1 );
	}
	return true;
}
bool transformRGBA8toRGBA12( const unsigned char *source , unsigned char *target , size_t pixelcount )
{
	// TODO
	return false;
}
bool transformRGBA8(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	switch( tformat )
	{
		case pixel::RGB8 :
		{
			return transformRGBA8toRGB( source , (unsigned char *)target , pixelcount );
		}
		case pixel::ARGB8 :
		{
			return transformRGBA8toARGB( source , (unsigned char *)target , pixelcount );
		}
		case pixel::RGBA16 :
		{
			return transformRGBA8toRGBA( source , (unsigned short *)target , pixelcount );
		}
		case pixel::RGBA32 :
		{
			return transformRGBA8toRGBA( source , (unsigned int *)target , pixelcount );
		}
		case pixel::RGB565 :
		{
			return transformRGBA8toRGB565( source , (unsigned short *)target , 4 , pixelcount );
		}
		case pixel::RGBA4 :
		{
			return transformRGBA8toRGBA4( source , (unsigned short *)target , pixelcount );
		}
		case pixel::RGBA5551 :
		{
			return transformRGBA8toRGBA5551( source , (unsigned short *)target , pixelcount );
		}
		case pixel::RGBA32F :
		{
			return transformRGBA8toRGBA( source , (float *)target , pixelcount );
		}
		case pixel::RGBA12 :
		{
			return transformRGBA8toRGBA12( source , (unsigned char *)target , pixelcount );
		}
		default:
		{
			break;
		}
	}
	return false;
}

/////////
// ARGB8
/////////
bool transformARGB8(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// ALPHA8
/////////
bool transformALPHA8(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// LUMINANCE
/////////
bool transformLUMINANCE(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// INTENSITY
/////////
bool transformINTENSITY(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// RGBA12
/////////
bool transformRGBA12(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// RGBA16
/////////
bool transformRGBA16(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// RGBA32
/////////
bool transformRGBA32(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// RGBA32F
/////////
bool transformRGBA32F(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// DEPTH8
/////////
bool transformDEPTH8(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// DEPTH16
/////////
bool transformDEPTH16(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// DEPTH24
/////////
bool transformDEPTH24(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// DEPTH32
/////////
bool transformDEPTH32(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// RGB565
/////////
bool transformRGB565(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// RGBA4
/////////
bool transformRGBA4(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

/////////
// RGBA5551
/////////
bool transformRGBA5551(
		const unsigned char *source ,
		void *target ,
		pixel::Format tformat ,
		size_t pixelcount )
{
	return false;
}

} // namespace utils
} // namespace buffer

#endif
