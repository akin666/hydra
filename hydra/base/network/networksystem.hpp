/*
 * networksystem.hpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#ifndef NETWORKSYSTEM_HPP_
#define NETWORKSYSTEM_HPP_

#include <json>

namespace network {

class System
{
public:
	System();
	~System();

	void uninitialize();
	bool initialize( Json::ValuePtr& config );
};

} // namespace network
#endif // NETWORKSYSTEM_HPP_
