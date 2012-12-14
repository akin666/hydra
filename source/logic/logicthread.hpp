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
#include "../render/renderqueue.hpp"

namespace logic {

class Thread : public Protothread
{
private:
	entity::Context context;

	render::Queue *renderqueue;
protected:
	render::Queue *getRenderQueue();
public:
	Thread();
	virtual ~Thread();

	void setRenderQueue( render::Queue *rqueue );
};

} // namespace logic
#endif // LOGICTHREAD_HPP_
