/*
 * inputmanager.hpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#ifndef INPUTMANAGER_HPP_
#define INPUTMANAGER_HPP_

#include "inputsource.hpp"

namespace input {

class Manager
{
private:
	static std::vector<Source::WeakPtr> sources;
public:
	static void attach( Source::Ptr ptr );
	static void get( const String8& name , Source::Ptr ptr );
	static void get( Mode mode , Source::Ptr ptr );
	static void get( Type type , Source::Ptr ptr );
	static void clean();
};

} // namespace input 
#endif // INPUTMANAGER_HPP_ 
