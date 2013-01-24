/*
 * inputsource.hpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#ifndef INPUTSOURCE_HPP_
#define INPUTSOURCE_HPP_

#include "inputcommon.hpp"
#include "inputhandler.hpp"

namespace input {

class Source
{
public:
	typedef std::shared_ptr<Source> Ptr;
	typedef std::weak_ptr<Source> WeakPtr;
protected:
	Type type;
	Mode mode;
	String8 name;

	std::vector<Handler::WeakPtr> items;
public:
	Source( const String8& name , Type type , Mode mode );
	virtual ~Source();

	void attach( Handler::Ptr ptr );
	String8 getName() const;
	Type getType() const;
	Mode getMode() const;
};

} // namespace input 
#endif // INPUTSOURCE_HPP_ 
