/*
 * filebuffer.cpp
 *
 *  Created on: 19.2.2013
 *      Author: akin
 */

#include "filebuffer.hpp"

#define FBFLAGS_NONE 			0x0000
#define FBFLAGS_CREATE	 		0x0001
#define FBFLAGS_READ	 		0x0002
#define FBFLAGS_WRITE	 		0x0004
#define FBFLAGS_FULL	 		0x0008
#define FBFLAGS_DEFAULT 		( FBFLAGS_CREATE | FBFLAGS_READ | FBFLAGS_WRITE | FBFLAGS_FULL )

namespace file {

Buffer::Buffer()
: fd( -1 )
, size( 0 )
, position( 0 )
, root( nullptr )
, buffer( nullptr )
, flags( FBFLAGS_DEFAULT )
{
}

Buffer::~Buffer()
{
	close();
}

Buffer& Buffer::setFilename( const String8& filename )
{
	this->filename = filename;
	return *this;
}

Buffer& Buffer::setPosition( size_t position )
{
	this->position = position;
	return *this;
}

Buffer& Buffer::setSize( size_t size )
{
	this->size = size;
	return *this;
}

Buffer& Buffer::setCreate( bool flag )
{
	flag ? flags |= FBFLAGS_CREATE : flags &= ~FBFLAGS_CREATE;
	return *this;
}

Buffer& Buffer::setRead( bool flag )
{
	flag ? flags |= FBFLAGS_READ : flags &= ~FBFLAGS_READ;
	return *this;
}

Buffer& Buffer::setWrite( bool flag )
{
	flag ? flags |= FBFLAGS_WRITE : flags &= ~FBFLAGS_WRITE;
	return *this;
}

Buffer& Buffer::setWholeFile( bool flag )
{
	flag ? flags |= FBFLAGS_FULL : flags &= ~FBFLAGS_FULL;
	return *this;
}

bool Buffer::hasCreate() const
{
	return ( flags & FBFLAGS_CREATE ) != 0;
}

bool Buffer::hasRead() const
{
	return ( flags & FBFLAGS_READ ) != 0;
}

bool Buffer::hasWrite() const
{
	return ( flags & FBFLAGS_WRITE ) != 0;
}

bool Buffer::hasWholeFile() const
{
	return ( flags & FBFLAGS_FULL ) != 0;
}

size_t Buffer::getSize() const
{
	return size;
}

size_t Buffer::getPosition() const
{
	return position;
}

void Buffer::open()
{
	if( filename.empty() )
	{
		LOG->error( "%s:%i Empty filename provided." , __FILE__ , __LINE__);
		throw std::runtime_error("Empty filename provided!");
	}

	bool create = hasCreate();
	bool read = hasRead();
	bool write = hasWrite();

	struct stat st;
	switch( stat(filename.c_str(), &st) )
	{
		case 0 :
			break; // all ok
		case ENOENT :
		{
			if( create )
			{
				break; // all ok
			}
			LOG->error( "%s:%i File does not exist and create is not allowed [%s]." , __FILE__ , __LINE__ , filename.c_str() );
			throw std::runtime_error("File does not exist!");
		}
		default:
		{
			LOG->error( "%s:%i File error [%s]." , __FILE__ , __LINE__ , filename.c_str() );
			throw std::runtime_error("File error!");
		}
	}

	int mmapflags = 0;
	int openflags = 0;
	if( read )
	{
		mmapflags |= PROT_READ;
		openflags |= O_RDONLY;
	}
	if( write )
	{
		mmapflags |= PROT_WRITE;
		openflags |= O_WRONLY;
	}
	if( read && write )
	{
		openflags = O_RDWR;
	}

	if( create )
	{
		openflags |= ::O_CREAT;
	}

	fd = ::open( filename.c_str() , openflags );
	if( fd == -1 )
	{
		LOG->error( "%s:%i File error [%s]." , __FILE__ , __LINE__ , filename.c_str() );
		throw std::runtime_error("File error!");
	}

	root = mmap( 0 , size, mmapflags , MAP_SHARED, fd , 0 );

	if( data == MAP_FAILED )
	{
		::close( fd );
		return false;
	}
	return true;
}

void Buffer::close()
{
}

bool Buffer::isOpen() const
{
	return false;
}

void *Buffer::access() const
{
	return buffer;
}


} // namespace file 
