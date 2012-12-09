/*
 * ALLOCATIONpool.hpp
 *
 *  Created on: 7.12.2012
 *      Author: akin
 */

#ifndef ALLOCATIONPOOL_HPP_
#define ALLOCATIONPOOL_HPP_

#include <vector>

namespace allocation {

template <class CDataType , size_t basesize = 256 , size_t maxsize = 2048>
class Pool
{
private:
	typedef std::vector<CDataType*> CDataTypeSet;

	size_t alloccount;
	CDataTypeSet frees;
	CDataTypeSet allocs;
public:
	Pool()
	: alloccount( basesize )
	{
		size_t objectSize = sizeof( CDataType );
		alloccount = basesize / objectSize;
	}

	~Pool()
	{
		clear();
	}

	CDataType *construct()
	{
		if( frees.size() < 1 )
		{
			add( alloccount );

			// grow allocation count linearly to max.
			// linearly grows the added amount of objects, until MAX is hit,
			// whereafter the amount of objects added, stays the same, max.
			size_t objectSize = sizeof( CDataType );
			size_t maxim = maxsize / objectSize;
			if( alloccount < maxim )
			{
				alloccount += basesize / objectSize;
				if( alloccount > maxim )
				{
					alloccount = maxim;
				}
			}
		}

		CDataType *tmp = frees.back();
		frees.pop_back();

		tmp->constructor();
		return tmp;
	}

	void destruct( CDataType *unit )
	{
		unit->destructor();
		frees.push_back( unit );
	}

	void add( size_t count )
	{
		CDataType *array = new CDataType[ alloccount ];
		for( int i = 0 ; i < alloccount ; ++i )
		{
			frees.push_back( &array[i] );
		}
		allocs.push_back( array );
	}

	void clear()
	{
		frees.clear();
		for( auto iter = allocs.begin() ; iter != allocs.end() ; ++iter )
		{
			delete[] *iter;
		}
		allocs.clear();
		size_t objectSize = sizeof( CDataType );
		alloccount = basesize / objectSize;
	}
};

} //namespace entity
#endif // ENTITYDATAPOOL_HPP_
