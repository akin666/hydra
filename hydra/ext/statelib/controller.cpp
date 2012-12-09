/*
 * controller.cpp
 *
 *  Created on: 3.12.2012
 *      Author: akin
 */

#include "controller.hpp"

namespace state {

Controller::Controller()
{
}

Controller::~Controller()
{
	clear();
}

void Controller::clear()
{
	for( auto iter : data )
	{
		delete iter;
	}
	data.clear();
}

void Controller::run()
{
	for( auto iter = data.begin() ; iter != data.end() ; ++iter )
	{
		while( iter != data.end() && !(*iter)->run() )
		{
			delete (*iter); // kill the protothread ptr
			iter = data.erase( iter );
		}
	}
}

} // namespace state
