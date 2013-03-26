/*
 * graphicsprogram.cpp
 *
 *  Created on: 19.4.2010
 *      Author: akin
 */

#include "graphicsprogram.hpp"
#include "graphicsuniform.hpp"
#include "graphicsshader.hpp"
#include <stdgl>
#include "graphicsshader.hpp"

#define GRAPHICS_PROGRAM_NONE	0x0000
#define GRAPHICS_PROGRAM_LINKED	0x0001

namespace graphics {

Program::Program()
: id( GL_NULL )
, state( GRAPHICS_PROGRAM_NONE )
{
}

Program::~Program()
{
	release();
}

void Program::setLinking( bool val )
{
	val ? (state |= GRAPHICS_PROGRAM_LINKED) : (state &= ~GRAPHICS_PROGRAM_LINKED);
}

sint Program::getUniformID( const std::string& key ) const
{
	GL_TEST_RAII;
	if( hasError() )
	{
		return -1;
	}
	return glGetUniformLocation( id , (const GLchar*)key.c_str() );
}

uint Program::getID() const
{
	return id;
}

bool Program::initialize()
{
	if( !initialized() )
	{
		GL_TEST_RAII;
		id = glCreateProgram();

		setLinking( false );

		return true;
	}
	return false;
}

bool Program::initialized() const
{
	return id != GL_NULL;
}

void Program::release()
{
	if( initialized() )
	{
		GL_TEST_RAII;
		glDeleteProgram( id );
		id = GL_NULL;
	}
}

Attribute Program::getAttribute( const std::string& key ) const
{
	GL_TEST_RAII;
	if( hasError() )
	{
		return graphics::Attribute( key );
	}

	sint aid = glGetAttribLocation( id , (const GLchar*)key.c_str() );

	return graphics::Attribute( key , aid );
}

void Program::setAttribute( const Attribute& attribute )
{
	GL_TEST_RAII;
	glBindAttribLocation( id , attribute.getID() , (const GLchar*)attribute.getName().c_str() );
}

void Program::bind() const
{
	GL_TEST_RAII;
	glUseProgram( id );
}

void Program::bindDefault()
{
	GL_TEST_RAII;
	glUseProgram( GL_NULL );
}

void Program::attach( const Shader& piece )
{
	GL_TEST_RAII;
	glAttachShader( id , piece.getID() );
	setLinking( false );
}

void Program::detach( const Shader& piece )
{
	GL_TEST_RAII;
	glDetachShader( id , piece.getID() );
}

void Program::link()
{
	GL_TEST_RAII;
	glLinkProgram( id );

	GLint tmp;
	glGetProgramiv( id , GL_LINK_STATUS , &tmp );

	if( tmp == GL_TRUE )
	{
		setLinking( true );
	}
	else
	{
		setLinking( false );
	}
}

bool Program::hasError() const
{
	if( !initialized() )
	{
		return true;
	}

	GL_TEST_RAII;
	GLint loglen = 0;
	glGetProgramiv( id , GL_INFO_LOG_LENGTH , &loglen );

	return loglen > 0;
}

std::string Program::getError() const
{
	if( !initialized() )
	{
		return "Program not initialized.";
	}


	GL_TEST_RAII;
	GLint loglen = 0;
	glGetProgramiv( id , GL_INFO_LOG_LENGTH , &loglen );

	if (loglen > 0)
	{
		std::string msg;
		msg.resize( loglen );

		glGetProgramInfoLog( id , loglen , NULL , &(msg[0]) );

		return msg;
	}

	return "";
}

bool Program::linked() const
{
	if( !initialized() )
	{
		return false;
	}
	return (state & GRAPHICS_PROGRAM_LINKED) != 0;
}

} // namespace graphics

#undef GGNOTINITIALIZED
