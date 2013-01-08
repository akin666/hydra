/*
 * workpool.hpp
 *
 *  Created on: 18.12.2012
 *      Author: akin
 */

#ifndef WORKPOOL_HPP_
#define WORKPOOL_HPP_

#include "workworker.hpp"

namespace work {

class Pool
{
private:
	ProtoQueu queue;
	WorkerSet workers;
public:
	Pool();
	~Pool();


};

} // namespace work
#endif // WORKPOOL_HPP_
