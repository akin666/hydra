/*
 * graphicsshader.cpp
 *
 *  Created on: 19.4.2010
 *      Author: akin
 */

#include "graphicsshader.hpp"
#include <stdgl>

#define GRAPHICS_SHADER_NONE		0x0000
#define GRAPHICS_SHADER_COMPILED	0x0001

namespace graphics {

Shader::Shader( )
: id( GL_NULL )
, type( Unknown )
, state( 0 )
{
}

Shader::~Shader()
{
	release();
}

void Shader::setCompiled( bool status )
{
	status ? ( state |= GRAPHICS_SHADER_COMPILED ) : ( state &= ~GRAPHICS_SHADER_COMPILED );
}

void Shader::set( const String8& source )
{
	this->source = source;
}

void Shader::setType( Type type )
{
	this->type = type;
}

Shader::Type Shader::getType() const
{
	return type;
}

uint Shader::getID() const
{
	return id;
}

bool Shader::initialize()
{
	GL_TEST_RAII;
	if( id == GL_NULL )
	{
		switch( type )
		{
			case Vertex :
			{
				id = glCreateShader( GL_VERTEX_SHADER );
				break;
			}
			case Fragment :
			{
				id = glCreateShader( GL_FRAGMENT_SHADER );
				break;
			}
	#if defined(GL_GEOMETRY_SHADER)
			case Geometry :
			{
				id = glCreateShader( GL_GEOMETRY_SHADER );
				break;
			}
	#elif defined(GL_GEOMETRY_SHADER_EXT)
			case Geometry :
			{
				id = glCreateShader( GL_GEOMETRY_SHADER_EXT );
				break;
			}
	#endif
	#if defined(GL_TESS_CONTROL_SHADER)
			case Control :
			{
				id = glCreateShader( GL_TESS_CONTROL_SHADER );
				break;
			}
	#elif defined(GL_TESS_CONTROL_SHADER_EXT)
			case ShaderControl :
			{
				id = glCreateShader( GL_TESS_CONTROL_SHADER_EXT );
				break;
			}
	#endif
	#if defined(GL_TESS_EVALUATION_SHADER)
			case Evaluation :
			{
				id = glCreateShader( GL_TESS_EVALUATION_SHADER );
				break;
			}
	#elif defined(GL_TESS_EVALUATION_SHADER_EXT)
			case ShaderEvaluation :
			{
				id = glCreateShader( GL_TESS_EVALUATION_SHADER_EXT );
				break;
			}
	#endif
			default :
			{
				return false;
			}
		}
	}
	return initialized();
}

bool Shader::initialized() const
{
	return id != GL_NULL;
}

void Shader::compile()
{
	setCompiled( false );

	if( id == GL_NULL || source.size() < 1 )
	{
		return;
	}

	GL_TEST_RAII;
	const GLchar *dat = source.c_str();
	GLint size = source.size();

	glShaderSource( id , 1 , (const GLchar**)&dat , &size );
	glCompileShader( id );

	GLint status;
	glGetShaderiv( id , GL_COMPILE_STATUS , &status );

	setCompiled( status == GL_TRUE );
}

bool Shader::compiled() const
{
	return (state & GRAPHICS_SHADER_COMPILED) != 0;
}

void Shader::release()
{
	if( initialized() )
	{
		GL_TEST_RAII;
		glDeleteShader( id );
		id = GL_NULL;
	}
}

bool Shader::hasError() const
{
	if( !initialized() )
	{
		return true;
	}


	GL_TEST_RAII;

	GLint status;
	glGetShaderiv( id , GL_COMPILE_STATUS , &status );

	return status != GL_TRUE;
}

String8 Shader::getError() const
{
	if( !initialized() )
	{
		return "Shader not initialized.";
	}

	GL_TEST_RAII;

	GLint loglen = 0;
	glGetShaderiv( id  , GL_INFO_LOG_LENGTH , &loglen );

	if (loglen > 0)
	{
		String8 msg;
		msg.resize( loglen );

		glGetShaderInfoLog( id , loglen , NULL , &(msg[0]) );
		return msg;
	}
	return "";
}

/*	void Shader::setTypeString( String8 type )
{
	if( type == "fragment" )
	{
		setType( FRAGMENT );
	}
	else if( type == "vertex" )
	{
		setType( VERTEX );
	}
#if defined(GL_GEOMETRY_SHADER) or defined(GL_GEOMETRY_SHADER_EXT)
	else if( type == "geometry" )
	{
		setType( GEOMETRY );
	}
#endif
#if defined(GL_TESS_CONTROL_SHADER) or defined(GL_TESS_CONTROL_SHADER_EXT)
	else if( type == "control" )
	{
		setType( CONTROL );
	}
#endif
#if defined(GL_TESS_EVALUATION_SHADER) or defined(GL_TESS_EVALUATION_SHADER_EXT)
	else if( type == "evaluation" )
	{
		setType( EVALUATION );
	}
#endif
}*/

} // namespace graphics

