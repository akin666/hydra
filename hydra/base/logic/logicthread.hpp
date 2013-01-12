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
#include "../render/renderscheduler.hpp"
#include <vector>

namespace logic {

class Scheduler;
class Thread : public Protothread
{
private:
	entity::Context context;

	render::Scheduler *renderScheduler;
	Scheduler *scheduler;
protected:
	render::Scheduler *getRenderScheduler();
	Scheduler *getLogicScheduler();
	entity::Context *getEntityContext();
public:
	Thread();
	virtual ~Thread();

	void set( render::Scheduler& targets );
	void set( Scheduler& scheduler );
};

typedef std::shared_ptr<Thread> ThreadPtr;
typedef std::vector<ThreadPtr> ThreadSet;

} // namespace logic
#endif // LOGICTHREAD_HPP_
