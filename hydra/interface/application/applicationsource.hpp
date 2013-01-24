/*
 * applicationsource.hpp
 *
 *  Created on: 24.1.2013
 *      Author: akin
 */

#ifndef APPLICATIONSOURCE_HPP_
#define APPLICATIONSOURCE_HPP_

#include "applicationhandler.hpp"

namespace application {

class Source
{
public:
	typedef std::shared_ptr<Source> Ptr;
	typedef std::weak_ptr<Source> WeakPtr;
protected:
	std::vector<Handler::WeakPtr> items;
public:
	Source();
	virtual ~Source();

	void attach( Handler::Ptr ptr );
};

} // namespace application 
#endif // APPLICATIONSOURCE_HPP_ 
