/*
 * audioalcontext.hpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#ifndef OPENALCONTEXT_HPP_
#define OPENALCONTEXT_HPP_

#include <audio/audiocontext.hpp>

namespace openal {

class Context : public audio::Context
{
public:
	Context();
	virtual ~Context();

	virtual bool initialize( Json::ValuePtr& config );
};

} // namespace openal
#endif // AUDIOALCONTEXT_HPP_ 
