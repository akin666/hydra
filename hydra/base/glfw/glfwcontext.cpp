/*
 * glfwcontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "glfwcontext.hpp"
#include "glfwrendertarget.hpp"
#include <stdgl>

#define GCORECONTEXT_NONE		0x0000
#define GCORECONTEXT_GLINIT		0x0001
#define GCORECONTEXT_GLFWINIT	0x0002

namespace glfw {

Context::Context()
: state( GCORECONTEXT_NONE )
{
}

Context::~Context()
{
	glfwTerminate();
}

bool Context::initialize( Json::ValuePtr& config )
{
	// init GLFW
	if( (state & GCORECONTEXT_GLFWINIT) == 0 )
	{
		if( glfwInit() == GL_FALSE )
		{
			LOG->error("%s:%i failed to init GLFW!" , __FILE__ , __LINE__ );
			return false;
		}
		state |= GCORECONTEXT_GLFWINIT;

		glfwOpenWindowHint( GLFW_OPENGL_VERSION_MAJOR , 3 );
		glfwOpenWindowHint( GLFW_OPENGL_VERSION_MINOR , 3 );
	}

	// Load rendertarget
	{
		RenderTarget *rtarget = new RenderTarget;

		if( !rtarget->initialize( config ) )
		{
			LOG->error("%s:%i failed to init GLFW Rendertarget!" , __FILE__ , __LINE__ );
			delete rtarget;
			return false;
		}

		rendertarget = graphics::RenderTarget::Ptr( rtarget );
	}

	// Init GLEW/GLEE/WhaTEva
	if( (state & GCORECONTEXT_GLINIT) == 0 )
	{
#ifdef USE_GLEW
		GLenum err = glewInit();
		if( GLEW_OK != err )
		{
			LOG->error( "Glewinit failed %s " , glewGetErrorString(err) );
			LOG->error("%s:%i failed to init GL!" , __FILE__ , __LINE__ );
			return false;
		}

		std::string ver("none");
		if( GLEW_VERSION_1_1 ) ver = "1.1";
		if( GLEW_VERSION_1_2 ) ver = "1.2";
		if( GLEW_VERSION_1_3 ) ver = "1.3";
		if( GLEW_VERSION_1_4 ) ver = "1.4";
		if( GLEW_VERSION_1_5 ) ver = "1.5";
		if( GLEW_VERSION_2_0 ) ver = "2.0";
		if( GLEW_VERSION_2_1 ) ver = "2.1";
		if( GLEW_VERSION_3_0 ) ver = "3.0";
		if( GLEW_VERSION_3_1 ) ver = "3.1";
		if( GLEW_VERSION_3_2 ) ver = "3.2";
		if( GLEW_VERSION_3_3 ) ver = "3.3";
		if( GLEW_VERSION_4_0 ) ver = "4.0";
		if( GLEW_VERSION_4_1 ) ver = "4.1";
		if( GLEW_VERSION_4_2 ) ver = "4.2";
		LOG->message("OpenGL Support for %s" , ver.c_str() );
#endif
		state |= GCORECONTEXT_GLINIT;
	}

	return true;
}

void Context::getRenderTarget( graphics::RenderTarget::Ptr& ptr )
{
	ptr = rendertarget;
}

} // namespace core 
