/*
 * resourcecache.hpp
 *
 *  Created on: 18.1.2013
 *      Author: akin
 *
 *   Cache
 *     - TextureCache
 *     - AudioCache
 *       - OGGCache
 *       - WAVCache
 *     - TXTCache
 *     - ScriptCache
 */

#ifndef RESOURCECACHE_HPP_
#define RESOURCECACHE_HPP_

#include <commontypes.h>

namespace resource {

class Handle;
class Cache
{
public:
	typedef std::shared_ptr<Cache> Ptr;
	typedef std::weak_ptr<Cache> WeakPtr;
public:
	Cache();
	virtual ~Cache();
};

} // namespace resource 
#endif // RESOURCECACHE_HPP_ 
