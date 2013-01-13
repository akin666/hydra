/*
 * audiosystem.hpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#ifndef AUDIOSYSTEM_HPP_
#define AUDIOSYSTEM_HPP_

#include <json>

namespace audio {

class System
{
public:
	System();
	~System();

	void uninitialize();
	bool initialize( Json::ValuePtr& config );
};

} // namespace audio
#endif // AUDIOSYSTEM_HPP_
