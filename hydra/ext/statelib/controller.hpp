/*
 * controller.hpp
 *
 *  Created on: 3.12.2012
 *      Author: akin
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <protothread>

namespace state {

class Controller
{
private:
	ProtothreadSet data;
public:
	Controller();
	~Controller();

	template <class ProtothreadClass>
	ProtothreadClass& add()
	{
		ProtothreadClass *proto = new ProtothreadClass;
		data.push_back( proto );

		return *proto;
	}

	void clear();
	void run();
};

} // namespace state
#endif // CONTROLLER_HPP_
