/*
 * workdestroyer.hpp
 *
 *  Created on: 26.1.2012
 *      Author: akin
 *
 *  if you have work that does not normally destroy itself,
 *  this helps you.. instead of:
 *  Work *hey = new MyWork();
 *  doWork( hey );
 *  // LEAKS!
 *
 *  do:
 *  Work *hey = new WorkDestroyer<MyWork>();
 *  doWork( hey );
 *  // Kills itself! No leaks!
 */

#ifndef TPOOL_WORKDESTROYER_HPP_
#define TPOOL_WORKDESTROYER_HPP_

namespace tpool {

template <class cwork>
class WorkDestroyer : public cwork
{
public:
	WorkDestroyer() {}
	virtual ~WorkDestroyer() {}

	virtual void end()
	{
		cwork::end();
		delete this;
	}
};

} // tpool
#endif // TPOOL_WORKDESTROYER_HPP_
