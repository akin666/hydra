/*
 * resourcehandle.hpp
 *
 *  Created on: 18.1.2013
 *      Author: akin
 *
 *  Factory
 *  ->
 *    Handle
 *      TextureHandle
 *      AudioHandle
 *       - OGGHandle
 *       - WavHandle
 *      TextHandle
 *      JSONHandle
 *      XMLHandle
 */

#ifndef RESOURCEHANDLE_HPP_
#define RESOURCEHANDLE_HPP_

#include <commontypes.h>

namespace resource {

class Cache;
class Handle
{
public:
	typedef std::shared_ptr<Handle> Ptr;
private:
	Cache *parent;
	std::string name;
public:
	Handle( const std::string& name = "" , Cache *parent = nullptr );
	virtual ~Handle();

	const std::string& getName() const;
	void setName( const std::string& name );

	virtual bool isLoaded() const;
	virtual void load();
	virtual void unload();

	virtual void getNullObject( Ptr& nullObjectPtr );
};

} // namespace resource
#endif // RESOURCEHANDLE_HPP_
