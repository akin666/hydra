/*
 * hydraengine.hpp
 *
 *  Created on: 11.1.2013
 *      Author: akin
 */

#ifndef HYDRAMAIN_HPP_
#define HYDRAMAIN_HPP_

#include <commontypes.h>
#include <signal.h>

#include <scheduler/logicscheduler.hpp>
#include <scheduler/renderscheduler.hpp>

#include <resource/resourcecache.hpp>
#include <core/corecontext.hpp>
#include <audio/audiocontext.hpp>

#ifndef HYDRA_CONFIG
# define HYDRA_CONFIG "config.json"
#endif

namespace hydra {

class Main
{
private:
	render::Scheduler::Ptr rscheduler;
	logic::Scheduler::Ptr lscheduler;

	resource::Cache::Ptr cache;
	core::Context::Ptr core;
	audio::Context::Ptr audio;

	Main( const Main& o ) {}
public:
	Main();
	~Main();

	void schedule( Protothread::Ptr& ptr );

	void uninitialize();

	bool initialize( String8 path = HYDRA_CONFIG );

	int run();
	bool shouldExit();
	bool shouldRestart();

	void get( render::Scheduler::Ptr& ptr );
	void get( logic::Scheduler::Ptr& ptr );
};

} // hydra

#endif // HYDRAMAIN_HPP_
