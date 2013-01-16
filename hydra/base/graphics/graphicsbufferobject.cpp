/*
 *
 *  Created on: 5.7.2011
 *      Author: akin
 */

#include "graphicsbufferobject.hpp"
#include <stdgl>

namespace graphics {

BufferObject::BufferObject( )
: bsize( 0 )
, id( GL_NULL )
{
}

BufferObject::~BufferObject()
{
	if( id != GL_NULL )
	{
		glDeleteBuffers( 1 , &id );
		id = GL_NULL;
	}
}

void BufferObject::initialize()
{
	// create ID.
	if( id == GL_NULL )
	{
		glGenBuffers( 1 , &id );
	}
}

bool BufferObject::hasInitialized()
{
	return id != GL_NULL;
}

void BufferObject::reserve( const unsigned int bytesize , Residence residence , Updates updates )
{
	set( bytesize , 0 , residence , updates );
}

void BufferObject::set( const unsigned int bytesize , const void *data , Residence residence , Updates updates )
{
	GL_TEST_ERROR("BufferObject:set START.");
	initialize();

	const int hint = resolveResidenceUpdates( residence , updates );

	bind( WRITE );
	glBufferData( GL_PIXEL_PACK_BUFFER , bytesize , data , hint );
	release( WRITE );

	GL_TEST_ERROR("BufferObject:set END.");
}


void BufferObject::bind( const BindStyle style ) const
{
	int bindStyle;

	switch( style )
	{
		case WRITE : bindStyle = GL_PIXEL_PACK_BUFFER; break;
		case READ : bindStyle = GL_PIXEL_UNPACK_BUFFER; break;
		case ARRAYBUFFER : bindStyle = GL_ARRAY_BUFFER; break;
		default : bindStyle = GL_PIXEL_PACK_BUFFER; break;
	}

	glBindBuffer( bindStyle , id );
}

void BufferObject::release( const BindStyle style ) const
{
	int bindStyle;

	switch( style )
	{
		case WRITE : bindStyle = GL_PIXEL_PACK_BUFFER; break;
		case READ : bindStyle = GL_PIXEL_UNPACK_BUFFER; break;
		case ARRAYBUFFER : bindStyle = GL_ARRAY_BUFFER; break;
		default : bindStyle = GL_PIXEL_PACK_BUFFER; break;
	}

	glBindBuffer( bindStyle , GL_NULL );
}

unsigned char *BufferObject::bindMemoryMap( const BindStyle style ) const
{
	GL_TEST_ERROR("BufferObject:bindMemoryMap START.");
	int buffstyle;

	switch( style )
	{
		case READ : buffstyle = GL_READ_ONLY; break;
		case WRITE : buffstyle = GL_WRITE_ONLY; break;
		case READANDWRITE : buffstyle = GL_READ_WRITE; break;
		default: buffstyle = GL_READ_ONLY; break;
	}

	GLubyte* ptr = (GLubyte*)glMapBufferARB( (style == WRITE ? GL_PIXEL_PACK_BUFFER : GL_PIXEL_UNPACK_BUFFER ) , buffstyle );

	GL_TEST_ERROR("BufferObject:bindMemoryMap END.");

	return ptr;
}

void BufferObject::releaseMemoryMap( const BindStyle style ) const
{
	glUnmapBuffer( (style == WRITE ? GL_PIXEL_PACK_BUFFER : GL_PIXEL_UNPACK_BUFFER ) );
}

unsigned int BufferObject::getID() const
{
	return id;
}

unsigned int BufferObject::size() const
{
	return bsize;
}

} // graphics
