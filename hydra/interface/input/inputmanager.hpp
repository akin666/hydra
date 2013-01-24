/*
 * inputmanager.hpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#ifndef INPUTMANAGER_HPP_
#define INPUTMANAGER_HPP_

#include <commontypes.h>
#include "inputsource.hpp"

namespace input {

class Manager
{
public:
	typedef std::shared_ptr<Manager> Ptr;
	typedef std::weak_ptr<Manager> WeakPtr;
private:
	typedef std::vector< Source::WeakPtr > WeakSourceSet;
	WeakSourceSet set;
public:
	Manager();
	~Manager();

	void attach( Source::Ptr& ptr );

	void get( const String8& name , Source::Ptr& ptr );
	void get( Mode mode , Source::Ptr& ptr );
	void get( Type type , Source::Ptr& ptr );
	void clean();

	void get( Mode& mode ) const;
	void get( Type& mode ) const;
	void get( StringSet& names ) const;
};

} // namespace input 
#endif // INPUTMANAGER_HPP_ 
