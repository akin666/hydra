/*
 * networksystem.hpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#ifndef NETWORKSYSTEM_HPP_
#define NETWORKSYSTEM_HPP_

#include <config/config.hpp>

namespace network {

class System
{
public:
	System();
	~System();

	void uninitialize();
	bool initialize( cfg::Config& config );
};

} // namespace network
#endif // NETWORKSYSTEM_HPP_
