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
	String8 name;
public:
	Handle( const String8& name = "" , Cache *parent = nullptr );
	virtual ~Handle();

	const String8& getName() const;
	void setName( const String8& name );

	virtual bool isLoaded() const;
	virtual void load();
	virtual void unload();

	virtual void getNullObject( Ptr& nullObjectPtr );
};

} // namespace resource
#endif // RESOURCEHANDLE_HPP_
