
#ifndef GEOMETRY_RECTANGLE_H_
#define GEOMETRY_RECTANGLE_H_

#include <commontypes.h>

namespace geometry {

template <class CType>
class Rectangle
{
public:
	CType x,y;
	CType width,height;
};

typedef Rectangle<float32> Rectanglef;
typedef Rectangle<int32> Rectanglei;

} // namespace geometry

#endif // GEOMETRY_RECTANGLE_H_