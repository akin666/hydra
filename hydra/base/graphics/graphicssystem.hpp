/*
 * graphicssystem.hpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#ifndef GRAPHICSSYSTEM_HPP_
#define GRAPHICSSYSTEM_HPP_

#include <json>
#include <commontypes.h>

namespace graphics {

class System
{
public:
	System();
	~System();

	void uninitialize();
	bool initialize( Json::ValuePtr& config );

	void print() const;
};

} // namespace graphics
#endif // GRAPHICSSYSTEM_HPP_
