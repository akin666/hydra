/*
 * geometrysphere2d.hpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#ifndef GEOMETRYSPHERE2D_HPP_
#define GEOMETRYSPHERE2D_HPP_

#include <commontypes.h>

namespace geometry {

template <class CType> class Rectangle2D;
template <class CType> class Sphere2D;

template <class CType>
class Line2D
{
public:
	CType x,y;
	CType x2,y2;
};

template <class CType>
class Sphere2D
{
public:
	CType x,y;
	CType radius;
public:
	Sphere2D();
	template <class OType> Sphere2D( const Sphere2D<OType>& other );
	template <class OType> Sphere2D( const Rectangle2D<OType>& other );
};

template <class CType>
class Rectangle2D
{
public:
	CType x,y;
	CType width,height;
public:
	Rectangle2D();
	template <class OType> Rectangle2D( const Rectangle2D<OType>& other );
	template <class OType> Rectangle2D( const Sphere2D<OType>& other );
};

//////
// Sphere2D Implementation

template <class CType> Sphere2D<CType>::Sphere2D()
: x( 0 )
, y( 0 )
, radius( 0 )
{
}

template <class CType,class OType> Sphere2D<CType>::Sphere2D<OType>( const Sphere2D<OType>& other )
{
	// Convert other to Sphere type.
	x = other.x;
	y = other.y;
	radius = other.radius;
}

template <class CType,class OType> Sphere2D<CType>::Sphere2D<OType>( const Rectangle2D<OType>& other )
{
	// Convert other to Sphere type.
	x = other.x + (other.width / 2);
	y = other.y + (other.height / 2);

	OType w = x - other.x;
	OType h = y - other.y;

	radius = glm::sqrt(w*w + h*h);
}


//////
// Rectangle2D Implementation

template <class CType> Rectangle2D<CType>::Rectangle2D()
: x( 0 )
, y( 0 )
, width( 0 )
, height( 0 )
{
}

template <class CType,class OType> Rectangle2D<CType>::Rectangle2D<OType>( const Rectangle2D<OType>& other )
{
	// Convert other to Rectanlge type.
	x = other.x;
	y = other.y;
	width = other.width;
	height = other.height;
}

template <class CType,class OType> Rectangle2D<CType>::Rectangle2D<OType>( const Sphere2D<OType>& other )
{
	// Convert other to Rectanlge type.
	x = other.x - other.radius;
	y = other.y - other.radius;
	width = 2 * other.radius;
	height = 2 * other.radius;
}

typedef Sphere2D<float32> Sphere2Df;
typedef Sphere2D<int32> Sphere2Di;

typedef Rectangle2D<float32> Rectangle2Df;
typedef Rectangle2D<int32> Rectangle2Di;

} // namespace geometry
#endif // GEOMETRYSPHERE2D_HPP_
