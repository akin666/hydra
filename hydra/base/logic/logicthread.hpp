/*
 * logicthread.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef LOGICTHREAD_HPP_
#define LOGICTHREAD_HPP_

#include <protothread>
#include <entitylib/entitycontext.hpp>
#include <vector>

namespace logic {

class Scheduler;
class Thread : public Protothread
{
private:
	entity::Context::Ptr context;

	Scheduler *scheduler;
protected:
	Scheduler *getLogicScheduler();
	entity::Context::Ptr getEntityContext();
public:
	Thread();
	virtual ~Thread();

	void set( Scheduler *scheduler );
};

} // namespace logic
#endif // LOGICTHREAD_HPP_
