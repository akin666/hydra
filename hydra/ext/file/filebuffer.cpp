/*
 * filebuffer.cpp
 *
 *  Created on: 19.2.2013
 *      Author: akin
 */

#include "filebuffer.hpp"
#include <mman>
#include <fcntl.h> // open, O_ flags.

namespace file {

Buffer::Buffer()
: fd( -1 )
, size( 0 )
, realSize( 0 )
, offset( 0 )
, root( MAP_FAILED )
, buffer( nullptr )
, flags( ACCESS_NONE )
{
}

Buffer::~Buffer()
{
	close();
}

// cases:
// a) whole file
Buffer& Buffer::setup( const String8& filename , int accessflags )
{
	if( isOpen() )
	{
		LOG->error( "%s:%i Buffer is already open, close first." , __FILE__ , __LINE__);
		throw std::runtime_error("Buffer already open.");
	}

	this->filename = filename;
	this->flags = accessflags;

	size = 0;
	offset = 0;
	fd = -1;
	root = MAP_FAILED;
	buffer = nullptr;

	return *this;
}

// b) part of the file
Buffer& Buffer::setup( const String8& filename , size_t offset , size_t size  , int accessflags )
{
	if( isOpen() )
	{
		LOG->error( "%s:%i Buffer is already open, close first." , __FILE__ , __LINE__);
		throw std::runtime_error("Buffer already open.");
	}

	this->filename = filename;
	this->flags = accessflags;
	this->size = size;
	this->offset = offset;

	fd = -1;
	root = MAP_FAILED;
	buffer = nullptr;

	return *this;
}

// c) new whole file
Buffer& Buffer::setup( const String8& filename , size_t size  , int accessflags )
{
	if( isOpen() )
	{
		LOG->error( "%s:%i Buffer is already open, close first." , __FILE__ , __LINE__);
		throw std::runtime_error("Buffer already open.");
	}

	this->filename = filename;
	this->flags = accessflags;
	this->size = size;

	offset = 0;
	fd = -1;
	root = MAP_FAILED;
	buffer = nullptr;

	return *this;
}

uint32 Buffer::getFlags() const
{
	return flags;
}

size_t Buffer::getSize() const
{
	return size;
}

size_t Buffer::getOffset() const
{
	return offset;
}

Buffer& Buffer::open()
{
	if( filename.empty() )
	{
		LOG->error( "%s:%i Empty filename provided." , __FILE__ , __LINE__);
		throw std::runtime_error("Empty filename provided!");
	}

	bool create = (flags & ACCESS_CREATE) == ACCESS_CREATE;
	bool read = (flags & ACCESS_READ) == ACCESS_READ;
	bool write = (flags & ACCESS_WRITE) == ACCESS_WRITE;

	struct stat st;
	switch( stat(filename.c_str(), &st) )
	{
		case 0 :
			break; // all ok
		case ENOENT :
		{
			if( create )
			{
				if( size < 1 )
				{
					LOG->error( "%s:%i File create not allowed for size less than 1 [%s]." , __FILE__ , __LINE__ , filename.c_str() );
					throw std::runtime_error("File creation not allowed for less than 1 byte size!");
				}
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
		openflags |= O_CREAT;
	}

	fd = ::open( filename.c_str() , openflags );
	if( fd == -1 )
	{
		LOG->error( "%s:%i File error [%s]." , __FILE__ , __LINE__ , filename.c_str() );
		throw std::runtime_error("File error!");
	}

	// resolve page differences..
	int pageOffset = mmapResolvePage( offset );
	int pagePadding = 0;
	if( pageOffset != offset )
	{
		pagePadding = offset - pageOffset;
	}

	realSize = size + pagePadding;

	root = mmap( 0 , realSize, mmapflags , MAP_SHARED, fd , pageOffset );
	if( root == MAP_FAILED )
	{
		::close( fd );
		fd = -1;
		LOG->error( "%s:%i Failed to mmap [%s]." , __FILE__ , __LINE__ , filename.c_str() );
		throw std::runtime_error("File mmap error!");
	}

	// dislocate buffer to be at right spot.
	buffer = root + pagePadding;

    return *this;
}

Buffer& Buffer::close()
{
	if( fd == -1 )
	{
	    return *this;
	}
    if( munmap( root , realSize ) == -1)
    {
		LOG->error( "%s:%i Failed to close mmap [%s]." , __FILE__ , __LINE__ , filename.c_str() );
		throw std::runtime_error("File close mmap error!");
    }
    root = MAP_FAILED;

    ::close( fd );
    fd = -1;

    return *this;
}

bool Buffer::isOpen() const
{
	return root != MAP_FAILED;
}

void *Buffer::access() const
{
	if( !isOpen() )
	{
		LOG->error( "%s:%i Failed to access mmap [%s]." , __FILE__ , __LINE__ , filename.c_str() );
		throw std::runtime_error("File access mmap error!");
	}
	return buffer;
}


} // namespace file 
