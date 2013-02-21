/*
 * distancefunctions.cpp
 *
 *  Created on: 21.2.2013
 *      Author: akin
 */

#include "distancefunctions.h"

float sdSphere( glm::vec3 p, float s )
{
	return glm::length( p ) - s;
}
