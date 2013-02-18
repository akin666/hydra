/*
 * filebuffer.hpp
 *
 *  Created on: 19.2.2013
 *      Author: akin
 */

#ifndef FILEBUFFER_HPP_
#define FILEBUFFER_HPP_

#include <commontypes.h>

namespace file {

class Buffer
{
private:
	String8 filename;
	int fd;
	size_t size;
	size_t position;
	void *root;
	void *buffer;
	uint32 flags;
public:
	Buffer();
	~Buffer();

	Buffer& setFilename( const String8& filename );
	Buffer& setPosition( size_t position );
	Buffer& setSize( size_t size );
	Buffer& setCreate( bool flag );
	Buffer& setRead( bool flag );
	Buffer& setWrite( bool flag );
	Buffer& setWholeFile( bool flag );

	bool hasCreate() const;
	bool hasRead() const;
	bool hasWrite() const;
	bool hasWholeFile() const;

	size_t getSize() const;
	size_t getPosition() const;

	void open();
	void close();

	bool isOpen() const;

	void *access() const;
};

} // namespace file 
#endif // FILEBUFFER_HPP_ 
