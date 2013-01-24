/*
 * applicationmanager.hpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#ifndef APPLICATIONMANAGER_HPP_
#define APPLICATIONMANAGER_HPP_

#include <commontypes.h>
#include "applicationsource.hpp"

namespace application {

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
	void get( Source::Ptr& ptr );
	void clean();
};

} // namespace application 
#endif // APPLICATIONMANAGER_HPP_ 
