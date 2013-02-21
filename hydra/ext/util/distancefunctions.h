/*
 * distancefunctions.h
 *
 *  Created on: 21.2.2013
 *      Author: akin
 *
 *
 *      source of the functions:
 *      http://www.iquilezles.org/www/articles/distfunctions/distfunctions.htm
 */

#ifndef DISTANCEFUNCTIONS_H_
#define DISTANCEFUNCTIONS_H_

#include <glm/glm.hpp>

// Sphere - signed
float sdSphere( glm::vec3 p, float s );

// Box - unsigned
float udBox( glm::vec3 p, glm::vec3 b );

// Round Box - unsigned
float udRoundBox( glm::vec3 p, glm::vec3 b, float r );

// Box - signed
float sdBox( glm::vec3 p, glm::vec3 b );

// Torus - signed
float sdTorus( glm::vec3 p, glm::vec2 t );

// Cylinder - signed
float sdCylinder( glm::vec3 p, glm::vec3 c );

// Cone - signed
float sdCone( glm::vec3 p, glm::vec2 c );

// Plane - signed
float sdPlane( glm::vec3 p, glm::vec4 n );

// Hexagonal Prism - signed
float sdHexPrism( glm::vec3 p, glm::vec2 h );

// Triangular Prism - signed
float sdTriPrism( glm::vec3 p, glm::vec2 n );

#endif // DISTANCEFUNCTIONS_H_
