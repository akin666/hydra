/*
 * workworker.hpp
 *
 *  Created on: 18.12.2012
 *      Author: akin
 */

#ifndef WORKWORKER_HPP_
#define WORKWORKER_HPP_

#include <TQue>

namespace work {

typedef TQue<Protothread*> ProtoQueu;

class Worker
{
private:
	ProtoQueu queue;
public:
	Worker( ProtoQueu& que );
	~Worker();

	void kill();
};

typedef std::vector<Worker*> WorkerSet;

} // namespace work
#endif // WORKWORKER_HPP_
