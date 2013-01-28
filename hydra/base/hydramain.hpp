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

#include <logic/logicscheduler.hpp>
#include <render/renderscheduler.hpp>

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
public:
	Main();
	~Main();

	template <class GameLogicSystem>
	void createThread()
	{
		ProtothreadPtr ptr( new GameLogicSystem );

		// add the thread to scheduler
		lscheduler->queue( ptr );
	}

	void uninitialize();

	bool initialize( String8 path = HYDRA_CONFIG );

	int run();
	bool shouldExit();
	bool shouldRestart();

	render::Scheduler::Ptr getRenderer();
	logic::Scheduler::Ptr getLogic();

	signal::Signal0<void> suspend;
	signal::Signal0<void> resume;
	signal::Signal0<void> exit;
	signal::Signal0<void> restart;
	signal::Signal0<void> minimize;
	signal::Signal0<void> maximize;

	signal::Signal0<void> windowed;
	signal::Signal0<void> fullscreened;
	signal::Signal0<void> lostFocus;

	signal::Signal1<int> memoryWarning;
	signal::Signal0<void> saveState;

	// App exception handling
	virtual void handleException( std::exception& e ) {}
	virtual void handleEllipsisException() {}
};

} // hydra

#endif // HYDRAMAIN_HPP_
