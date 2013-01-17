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

namespace resource {

class Handle;
class Cache
{
public:
	Cache();
	virtual ~Cache();
};

} // namespace resource 
#endif // RESOURCECACHE_HPP_ 
