/*
 * bufferutils.h
 *
 *  Created on: 27.2.2013
 *      Author: akin
 */

#ifndef BUFFERUTILS_H_
#define BUFFERUTILS_H_

#include <pixelformat>

namespace buffer {
namespace utils {

bool transformColor( const void *source , size_t slen , pixel::Format sformat , void *target , size_t tlen , pixel::Format tformat , const glm::ivec2& dimensions );

} // namespace utils
} // namespace buffer
#endif // BUFFERUTILS_H_
