/*
 * buffer.hpp
 *
 *  Created on: 16.7.2012
 *      Author: akin
 */

#ifndef SOFTIMAGE_BUFFER_HPP_
#define SOFTIMAGE_BUFFER_HPP_

#include <stdtypes>
#include <pixelformat>
#include <glm/glm>
#include <mbuf/mbufbuffer.hpp>

namespace simg
{

class Buffer
{
protected:
	int8 *buffer;		// does not have ownership
	int8 *realbuffer; 	// ownership
	mbuf::Iterator *iterator;
	int totalSize;
	pixel::Format mode;
	glm::ivec2 resolution;
	uint8 bytespp;
public:
	Buffer();
	// Wrap Buffer around existing buffer, does not transfer ownership.
	Buffer( const glm::ivec2& resolution , pixel::Format mode , void *pixelbuffer );
	Buffer( const glm::ivec2& resolution , pixel::Format mode , mbuf::Buffer& pixelbuffer );
	~Buffer();

	void setMode( pixel::Format mode );
	void setResolution( const glm::ivec2& resolution );

	pixel::Format getMode() const;
	glm::ivec2 getResolution() const;

	void *access() const;

	bool initialize();
	bool initialized() const;
	void release();

	bool drawRect( const glm::ivec2& position , const Buffer& other );
	bool drawRect( const glm::ivec2& position , const glm::ivec2& rect , void *pixelbuffer );
	bool drawRect( const glm::ivec2& min , const glm::ivec2& max , const void *pixel );
	bool drawLine( const glm::ivec2& p1 , const glm::ivec2& p2 , const void *pixel );
};

} // namespace simg
#endif // SOFTIMAGE_BUFFER_HPP_
