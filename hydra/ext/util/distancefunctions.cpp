/*
 * distancefunctions.cpp
 *
 *  Created on: 21.2.2013
 *      Author: akin
 */

#include "distancefunctions.h"

// Sphere - signed
float sdSphere( glm::vec3 p, float s )
{
	return glm::length( p ) - s;
}

// Box - unsigned
float udBox( glm::vec3 p, glm::vec3 b )
{
	return glm::length( glm::max( glm::abs( p ) - b , 0.0f ) );
}

// Round Box - unsigned
float udRoundBox( glm::vec3 p, glm::vec3 b, float r )
{
	return glm::length( glm::max( glm::abs( p ) - b , 0.0 ) ) - r;
}

// Box - signed
float sdBox( glm::vec3 p, glm::vec3 b )
{
	glm::vec3 d = glm::abs(p) - b;
	return glm::min( glm::max( d.x , glm::max( d.y , d.z ) ) , 0.0f ) + glm::length( glm::max( d , 0.0f ) );
}

// Torus - signed
float sdTorus( glm::vec3 p, glm::vec2 t )
{
	glm::vec2 q = glm::vec2( glm::length( glm::vec2(p.x , p.z) ) - t.x , p.y );
	return glm::length( q ) - t.y;
}

// Cylinder - signed
float sdCylinder( glm::vec3 p, glm::vec3 c )
{
	return glm::length( glm::vec2(p.x , p.z) - glm::vec2(c.x , c.y) ) - c.z;
}

// Cone - signed
float sdCone( glm::vec3 p, glm::vec2 c )
{
    // c must be normalized
    float q = glm::length( glm::vec2(p.x , p.y) );
    return glm::dot( c , glm::vec2( q , p.z ) );
}

// Plane - signed
float sdPlane( glm::vec3 p, glm::vec4 n )
{
	// n must be normalized
	return glm::dot( p , glm::vec3(n.x , n.y , n.z) ) + n.w;
}

// Hexagonal Prism - signed
float sdHexPrism( glm::vec3 p, glm::vec2 h )
{
	glm::vec3 q = glm::abs( p );
    return glm::max( q.z - h.y , glm::max( q.x + q.y * 0.57735f , q.y * 1.1547f ) - h.x );
}

// Triangular Prism - signed
float sdTriPrism( glm::vec3 p, glm::vec2 n )
{
	// in here theres a bug in original code.. there is no 'h'
	glm::vec3 q = glm::abs( p );
    return glm::max( q.z - n.y , glm::max( q.x * 0.866025f + p.y * 0.5f , -p.y ) - n.x * 0.5f );
}
