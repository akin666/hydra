/*
 * graphicssystem.hpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#ifndef GRAPHICSSYSTEM_HPP_
#define GRAPHICSSYSTEM_HPP_

#include <config/config.hpp>

namespace graphics {

class System
{
public:
	System();
	~System();

	void uninitialize();
	bool initialize( cfg::Config& config );
};

} // namespace graphics
#endif // GRAPHICSSYSTEM_HPP_
