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

namespace InputHandling
{
	core::Joystick::Map joystickMap;
	core::Keyboard::Ptr keyboard;
	core::Mouse::Ptr mouse;
	core::Touch::Map touchMap;

	Context *singleton = nullptr;

	int mouseX = 0;
	int mouseY = 0;
	int mouseWheel = 0;

	void keyboardCharCallback(int key, int action)
	{
		if( keyboard )
		{
			keyboard->character( key , (action == GLFW_PRESS ? core::DOWN : core::UP ) );
		}
	}

	void keyboardCallback(int key, int action)
	{
		if( keyboard )
		{
			keyboard->key( key , (action == GLFW_PRESS ? core::DOWN : core::UP ) );
		}
	}

	void mouseWheelCallback(int wheel)
	{
		float diff;

		diff = wheel - mouseWheel;
		mouseWheel = wheel;

		if( mouse )
		{
			mouse->wheel( diff );
			return;
		}
	}

	void mouseButtonCallback(int button, int action)
	{
		if( mouse )
		{
			int key;
			switch( button )
			{
				case GLFW_MOUSE_BUTTON_LEFT :
					key = core::LEFT;
					break;
				case GLFW_MOUSE_BUTTON_RIGHT :
					key = core::RIGHT;
					break;
				case GLFW_MOUSE_BUTTON_MIDDLE :
					key = core::MIDDLE;
					break;
				case GLFW_MOUSE_BUTTON_4 :
					key = core::EXTRA;
					break;
				case GLFW_MOUSE_BUTTON_5 :
					key = core::EXTRA + 1;
					break;
				case GLFW_MOUSE_BUTTON_6 :
					key = core::EXTRA + 2;
					break;
				case GLFW_MOUSE_BUTTON_7 :
					key = core::EXTRA + 3;
					break;
				case GLFW_MOUSE_BUTTON_8 :
					key = core::EXTRA + 4;
					break;
				default:
					key = core::EXTRA + 5;
					break;
			}

			mouse->button( key , (action == GLFW_PRESS ? core::DOWN : core::UP ) );
		}
	}

	void mouseMoveCallback(int x, int y)
	{
		float diffX, diffY;

		diffX = x - mouseX;
		diffY = y - mouseY;

		mouseX = x;
		mouseY = y;

		if( mouse )
		{
			mouse->move( diffX , -diffY );
		}
	}

	int windowCloseCallback()
	{
		/*
		OSInput* osinput = getSingleton<OSInput>();

		if( osinput == NULL )
		{
			return GL_TRUE;
		}

		return osinput->handleClose() ? GL_TRUE : GL_FALSE;
		*/

		singleton->exit();

		return GL_TRUE;
	}

	void windowSizeCallback( int w , int h )
	{
		/*
		OSInput* osinput = getSingleton<OSInput>();

		if( osinput == NULL )
		{
			return;
		}

		osinput->handleResize( w , h );
		*/
		singleton->resize( w , h );
	}

	void windowRefreshCallback()
	{
		/*
		OSInput* osinput = getSingleton<OSInput>();

		if( osinput == NULL )
		{
			return;
		}

		osinput->handleRefresh();
		*/
	}

	void setup()
	{
		glfwGetMousePos( &mouseX , &mouseY );
		mouseWheel = glfwGetMouseWheel();

		glfwSetKeyCallback( keyboardCallback );
		glfwSetCharCallback( keyboardCharCallback );
		glfwSetMousePosCallback( mouseMoveCallback );
		glfwSetMouseButtonCallback( mouseButtonCallback );
		glfwSetMouseWheelCallback( mouseWheelCallback );
		glfwSetWindowCloseCallback( windowCloseCallback );
		glfwSetWindowSizeCallback( windowSizeCallback );
	//	glfwSetWindowRefreshCallback( windowRefreshCallback );
	}

	void construct( Context *ptr )
	{
		singleton = ptr;

		joystickMap.clear();
		touchMap.clear();

		keyboard.reset();
		mouse.reset();
		keyboard = core::Keyboard::Ptr( new core::Keyboard );
		mouse = core::Mouse::Ptr( new core::Mouse );
	}

	void destruct()
	{
		singleton = nullptr;

		joystickMap.clear();
		touchMap.clear();

		keyboard.reset();
		mouse.reset();
	}
}
// GLFW INPUT HANDLING


Context::Context()
: state( GCORECONTEXT_NONE )
{
	InputHandling::construct( this );
}

Context::~Context()
{
	glfwTerminate();
	InputHandling::destruct();
}

bool Context::initialize( Json::ValuePtr& config )
{
	// init GLFW
	if( (state & GCORECONTEXT_GLFWINIT) == 0 )
	{
		if( glfwInit() != GL_TRUE )
		{
			LOG->error("%s:%i failed to init GLFW!" , __FILE__ , __LINE__ );
			return false;
		}
		state |= GCORECONTEXT_GLFWINIT;
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

	GL_TEST_START();
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
#endif
		GL_FLUSH_ERRORS(); // flush glew errors from gl state
		state |= GCORECONTEXT_GLINIT;
	}

	// populate extension list.
	String8 extensionlist;
	GLint n, i;
	glGetIntegerv(GL_NUM_EXTENSIONS, &n);
	for (i = 0; i < n; i++)
	{
		extensionlist += String8( (const char*)glGetStringi(GL_EXTENSIONS, i) );
		if( i+1 < n ) extensionlist += ",";
	}

	LOG->message( "Core context data: ");
	LOG->message( " Vendor: %s " , glGetString(GL_VENDOR) );
	LOG->message( " Hardware: %s " , glGetString(GL_RENDERER) );
	LOG->message( " OpenGL version: %s " , glGetString(GL_VERSION) );
//	LOG->message( " Extensions: %s" , extensionlist.c_str() );

	// Disable/Enable mouse cursor
	glfwDisable( GLFW_MOUSE_CURSOR );

	InputHandling::setup();

	GL_TEST_END();
	// Init peripherals
	return true;
}

void Context::getRenderTarget( graphics::RenderTarget::Ptr& ptr )
{
	ptr = rendertarget;
}

void Context::get( core::Joystick::Ptr& ptr , int number )
{
	if( number < 0  || number >= getJoystickCount() )
	{
		return;
	}

	ptr.reset();

	if( glfwGetJoystickParam( GLFW_JOYSTICK_1 + number , GLFW_PRESENT ) != GL_TRUE )
	{
		return;
	}

	ptr = InputHandling::joystickMap[ number ];
	if( !ptr )
	{
		ptr = core::Joystick::Ptr( new core::Joystick );
		InputHandling::joystickMap[ number ] = ptr;
	}
}

void Context::get( core::Keyboard::Ptr& ptr , int number )
{
	if( number < 0 || number >= getKeyboardCount() )
	{
		return;
	}

	ptr.reset();

	ptr = InputHandling::keyboard;
}

void Context::get( core::Mouse::Ptr& ptr , int number )
{
	if( number < 0 || number >= getMouseCount() )
	{
		return;
	}

	ptr.reset();

	ptr = InputHandling::mouse;
}

void Context::get( core::Touch::Ptr& ptr , int number )
{
	if( number < 0 || number >= getTouchCount() )
	{
		return;
	}

	ptr.reset();

	ptr = InputHandling::touchMap[ number ];
//	if( !ptr )
//	{
//		ptr = core::Touch::Ptr( new core::Touch );
//		InputHandling::touchMap[ number ] = ptr;
//	}
}

int Context::getJoystickCount()
{
	return 16;
}

int Context::getKeyboardCount()
{
	return 1;
}

int Context::getMouseCount()
{
	return 1;
}

int Context::getTouchCount()
{
	return 0;
}

void Context::present()
{
	GL_TEST_START();
	glfwSwapBuffers();
	glfwSleep( 0.02 );
	GL_TEST_END();
}

} // namespace core 
