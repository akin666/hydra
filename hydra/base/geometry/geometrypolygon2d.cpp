/*
 * geometrypolygon2d.cpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#include "geometrypolygon2d.hpp"

namespace geometry {

Polygon2D::Polygon2D()
{
}

Polygon2D::~Polygon2D()
{
}

void Polygon2D::clear()
{
	vertexes.clear();
	indices.clear();
}

bool Polygon2D::hitTest( const glm::vec2& point ) const
{
	// game coding complete 4th edition page 300.
	bool inside = false;
	size_t size = vertexes.size();

	if( size < 3 )
	{
		return false;
	}

	for( uint32 i = 0 ; i < size ; ++i )
	{
		const glm::vec2& curr = vertexes[ i ];
		const glm::vec2& prev = vertexes[ (size - 1 + i) % size  ];

		if( curr.x > prev.x )
		{
			if( (curr.x < point.x) == (point.x <= prev.x) &&
				(point.y - prev.y) * (curr.x-prev.x) < (curr.y-prev.y) * (point.x-prev.x) )
			{
				inside = !inside;
			}
			continue;
		}
		if( (curr.x < point.x) == (point.x <= prev.x) &&
			(point.y - curr.y) * (prev.x-curr.x) < (prev.y-curr.y) * (point.x-curr.x) )
		{
			inside = !inside;
		}
	}

	return inside;
}

Vertex2DSet& Polygon2D::getVertexes()
{
	return vertexes;
}

IndexSet& Polygon2D::getIndexes()
{
	return indices;
}

//// Triangulation!
//// I do not claim any copyright on this triangulation code
//// original taken from http://www.flipcode.com/archives/Efficient_Polygon_Triangulation.shtml
//// and modified to, be sane, and less leaky
//// Original (c) claim:
// COTD Entry submitted by John W. Ratcliff [jratcliff@verant.com]
// ** THIS IS A CODE SNIPPET WHICH WILL EFFICIEINTLY TRIANGULATE ANY
// ** POLYGON/CONTOUR (without holes) AS A STATIC CLASS.  THIS SNIPPET
// ** IS COMPRISED OF 3 FILES, TRIANGULATE.H, THE HEADER FILE FOR THE
// ** TRIANGULATE BASE CLASS, TRIANGULATE.CPP, THE IMPLEMENTATION OF
// ** THE TRIANGULATE BASE CLASS, AND TEST.CPP, A SMALL TEST PROGRAM
// ** DEMONSTRATING THE USAGE OF THE TRIANGULATOR.  THE TRIANGULATE
// ** BASE CLASS ALSO PROVIDES TWO USEFUL HELPER METHODS, ONE WHICH
// ** COMPUTES THE AREA OF A POLYGON, AND ANOTHER WHICH DOES AN EFFICENT
// ** POINT IN A TRIANGLE TEST.
// ** SUBMITTED BY JOHN W. RATCLIFF (jratcliff@verant.com) July 22, 2000
static const float EPSILON=0.0000000001f;

float area(const Vertex2DSet &contour)
{
	int n = contour.size();
	float A=0.0f;

	for( int p=n-1 , q=0 ; q<n ; p=q++ )
	{
		A += contour[p].x *contour[q].y - contour[q].x * contour[p].y;
	}
	return A * 0.5f;
}

// InsideTriangle decides if a point P is Inside of the triangle
// defined by A, B, C.
bool insideTriangle(
		float Ax, float Ay,
		float Bx, float By,
		float Cx, float Cy,
		float Px, float Py)
{
	float ax, ay, bx, by, cx, cy, apx, apy, bpx, bpy, cpx, cpy;
	float cCROSSap, bCROSScp, aCROSSbp;

	ax = Cx - Bx;  ay = Cy - By;
	bx = Ax - Cx;  by = Ay - Cy;
	cx = Bx - Ax;  cy = By - Ay;
	apx= Px - Ax;  apy= Py - Ay;
	bpx= Px - Bx;  bpy= Py - By;
	cpx= Px - Cx;  cpy= Py - Cy;

	aCROSSbp = ax*bpy - ay*bpx;
	cCROSSap = cx*apy - cy*apx;
	bCROSScp = bx*cpy - by*cpx;

	return ((aCROSSbp >= 0.0f) && (bCROSScp >= 0.0f) && (cCROSSap >= 0.0f));
}

bool snip(const Vertex2DSet& contour, int u , int v , int w , int n , IndexSet& V )
{
	int p;
	float Ax, Ay, Bx, By, Cx, Cy, Px, Py;

	Ax = contour[V[u]].x;
	Ay = contour[V[u]].y;

	Bx = contour[V[v]].x;
	By = contour[V[v]].y;

	Cx = contour[V[w]].x;
	Cy = contour[V[w]].y;

	if ( EPSILON > (((Bx-Ax)*(Cy-Ay)) - ((By-Ay)*(Cx-Ax))) )
	{
		return false;
	}

	for( p=0 ; p<n ; ++p )
	{
		if( (p == u) || (p == v) || (p == w) )
		{
			continue;
		}
		Px = contour[V[p]].x;
		Py = contour[V[p]].y;

		if( insideTriangle(Ax,Ay,Bx,By,Cx,Cy,Px,Py) )
		{
			return false;
		}
	}

	return true;
}

bool process(const Vertex2DSet &contour , IndexSet &result)
{
	result.clear();

	// allocate and initialize list of Vertices in polygon
	int n = contour.size();
	if( n < 3 )
	{
		return false;
	}

	IndexSet V;
	V.resize( n );

	// we want a counter-clockwise polygon in V
	if ( 0.0f < area(contour) )
	{
		for( int v=0 ; v<n ; v++ )
		{
			V[v] = v;
		}
	}
	else
	{
		for( int v=0 ; v<n ; v++ )
		{
			V[v] = (n-1)-v;
		}
	}
	int nv = n;

	//  remove nv-2 Vertices, creating 1 triangle every time
	int count = 2*nv;   // error detection
	for( int m=0, v=nv-1 ; nv>2 ; )
	{
		// if we loop, it is probably a non-simple polygon
		if( 0 >= (count--) )
		{
			//** Triangulate: ERROR - probable bad polygon!
			return false;
		}

		// three consecutive vertices in current polygon, <u,v,w>
		int u = v;
		if (nv <= u) u = 0;     // previous
		v = u+1;
		if (nv <= v) v = 0;     // new v
		int w = v+1;
		if (nv <= w) w = 0;     // next

		if( snip(contour,u,v,w,nv,V) )
		{
			int a,b,c,s,t;

			// true names of the vertices
			a = V[u]; b = V[v]; c = V[w];

			// output Triangle
			result.push_back( a );
			result.push_back( b );
			result.push_back( c );

			++m;

			// remove v from remaining polygon
			for(s=v,t=v+1;t<nv;s++,t++)
			{
				V[s] = V[t];
				--nv;
			}

			// resest error detection counter
			count = 2*nv;
		}
	}

	return true;
}

void Polygon2D::tesselate()
{
	if( !process( vertexes , indices ) )
	{
		LOG->error("%s:%i failed to process vertexes." , __FILE__ , __LINE__ );
		throw std::runtime_error("failed to tesselate vertexes.");
	}
}

void Polygon2D::createBox( glm::vec2 mid , float width , float height )
{
	vertexes.clear();

	float hw = width / 2.0f;
	float hh = height / 2.0f;

	// assuming origo to bottomleft
	vertexes.push_back( mid + glm::vec2( -hw ,  hh ) ); // top left
	vertexes.push_back( mid + glm::vec2(  hw ,  hh ) ); // top right
	vertexes.push_back( mid + glm::vec2(  hw , -hh ) ); // bottom right
	vertexes.push_back( mid + glm::vec2( -hw , -hh ) ); // bottom left
}

void Polygon2D::createEllipse( glm::vec2 mid , float width , float height , float count )
{
	vertexes.clear();

	if( count < 3 )
	{
		return;
	}

	float delta = PI2 / count;

	float hw = width / 2.0f;
	float hh = height / 2.0f;

	for( int i = 0 ; i < count ; ++i )
	{
		vertexes.push_back( mid + glm::vec2( glm::sin( i*delta ) * hw , glm::cos( i*delta ) * hh ) );
	}
}

void Polygon2D::createCircle( glm::vec2 mid , float radius , float count )
{
	createEllipse( mid , 2*radius , 2*radius , count );
}

void Polygon2D::createTriangle( glm::vec2 v1 , glm::vec2 v2 , glm::vec2 v3 )
{
	vertexes.clear();

	vertexes.push_back( v1 );
	vertexes.push_back( v2 );
	vertexes.push_back( v3 );
}

void Polygon2D::createLine( glm::vec2 start , glm::vec2 end , float width )
{
	vertexes.clear();

	glm::vec2 half( width / 2.0f , width / 2.0f );
	// ______________________
	// |                     |
	// *                     *
	// |_____________________|
	//
	// calculate normals for start and end points..
	glm::vec2 sn = glm::normalize( glm::vec2( start.y , -start.x ) );
	glm::vec2 en = glm::normalize( glm::vec2( end.y , -end.x ) );

	vertexes.push_back( start + ( sn * half ) );
	vertexes.push_back( end + ( en * half ) );
	vertexes.push_back( end + ( (-en) * half ) );
	vertexes.push_back( start + ( (-sn) * half ) );
}

} // namespace geometry
