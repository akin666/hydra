/*
 * CompositeWork.hpp
 *
 *  Created on: 26.1.2012
 *      Author: akin
 */

#ifndef TPOOL_COMPOSITEWORK_HPP_
#define TPOOL_COMPOSITEWORK_HPP_

#include <work>
#include <tque>

namespace tpool
{

class CompositeWork: public Work
{
protected:
	std::mutex mutex;
	WorkQue work;
	bool running;

	void setRunning( bool state );
	bool getRunning();
public:
	CompositeWork();
	virtual ~CompositeWork();

	virtual bool begin();
	virtual void run();
	virtual void end();

	bool isRunning();
	void push( WorkPtr& work );
};

} // namespace tpool
#endif // TPOOL_COMPOSITEWORK_HPP_
