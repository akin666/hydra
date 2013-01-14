/*
 * graphicsuniform.cpp
 *
 *  Created on: 19.4.2010
 *      Author: akin
 */

#include "graphicsuniform.hpp"
#include <glm/transform>
#include <stdgl>

namespace graphics {

template <> void Uniform<float>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniform1f( id , value );
	committed = value;
}

template <> void Uniform<glm::vec2>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniform2f( id , value.x , value.y );
	committed = value;
}

template <> void Uniform<glm::vec3>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniform3f( id , value.x , value.y , value.z );
	committed = value;
}

template <> void Uniform<glm::vec4>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniform4f( id , value.x , value.y , value.z , value.w );
	committed = value;
}

template <> void Uniform<int>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniform1i( id , value );
	committed = value;
}

template <> void Uniform<glm::ivec2>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniform2i( id , value.x , value.y );
	committed = value;
}

template <> void Uniform<glm::ivec3>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniform3i( id , value.x , value.y , value.z );
	committed = value;
}

template <> void Uniform<glm::ivec4>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniform4i( id , value.x , value.y , value.z , value.w );
	committed = value;
}

template <> void Uniform<glm::mat4>::commit()
{
	if( value == committed )
	{
		return;
	}
	GL_TEST_RAII;
	glUniformMatrix4fv( id , 16 , GL_FALSE , &value[0][0] );
	committed = value;
}


/*
	void Uniform::setMatrix4( const float *v , int size )
	{
		GL_TEST_RAII;
		glUniformMatrix4fv( id , size , GL_FALSE , v );
	}

  	void Uniform::set( const TextureUnit& texture )
	{
		GL_TEST_RAII;
		glUniform1i( id , texture.getID() );
	}
*/
} // namespace graphics



