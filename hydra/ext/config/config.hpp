/*
 * config.hpp
 *
 *  Created on: 17.6.2012
 *      Author: akin
 */

#ifndef CFG_CONFIG_HPP_
#define CFG_CONFIG_HPP_

#include <json>
#include <cassert>
#include <stdexcept>
#include <stdtypes>

namespace cfg {

class Config
{
protected:
	Json::Value root;

	Json::Value *getValue( String8 key );

	// by default we do not recognize the type.
	template <class CType>
	bool getValue( String8 key , CType& type )
	{
		return false;
	}

	template <class CType>
	void setValue( String8 key , CType& type )
	{
	}
public:
	bool loadFromPath( const String8 path );
	bool loadFromString( const String8& data );
	bool loadFromStream( std::istream& input );

	bool saveToString( String8& data , bool styled = true );
	bool saveToStream( std::ostream& output );

	template <class CType>
	CType get( String8 key , CType def )
	{
		CType val;
		if( !getValue( key , val ) )
		{
			return def;
		}
		return val;
	}

	template <class CType>
	CType require( String8 key )
	{
		CType val;
		if( !getValue( key , val ) )
		{
			throw std::runtime_error("Failed badly at config requirement.");
			return val;
		}
		return val;
	}

	template <class CType>
	void set( String8 key , CType def )
	{
		setValue( key , def );
	}

	bool has( String8 key );
};


// specializations
// getters
template <> bool Config::getValue<float32>( String8 key , float32& type );
template <> bool Config::getValue<float64>( String8 key , float64& type );
template <> bool Config::getValue<String8>( String8 key , String8& type );
template <> bool Config::getValue<int32>( String8 key , int32& type );
template <> bool Config::getValue<uint32>( String8 key , uint32& type );
template <> bool Config::getValue<bool>( String8 key , bool& type );
// setters
template <> void Config::setValue<float32>( String8 key , float32& type );
template <> void Config::setValue<float64>( String8 key , float64& type );
template <> void Config::setValue<String8>( String8 key , String8& type );
template <> void Config::setValue<int32>( String8 key , int32& type );
template <> void Config::setValue<uint32>( String8 key , uint32& type );
template <> void Config::setValue<bool>( String8 key , bool& type );

} // namespace cfg
#endif // CONFIG_HPP_
