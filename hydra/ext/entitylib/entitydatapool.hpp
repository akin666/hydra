/*
 * entitydatapool.hpp
 *
 *  Created on: 7.12.2012
 *      Author: akin
 */

#ifndef ENTITYDATAPOOL_HPP_
#define ENTITYDATAPOOL_HPP_

namespace entity {

template <class CDataType , int basecount = 32 , int maxcount = 2048>
class DataPool
{
private:
	int alloccount;
	std::vector<CDataType*> frees;
	std::vector<CDataType*> allocs;
public:
	DataPool()
	: alloccount( basecount )
	{
	}

	~DataPool()
	{
		clear();
	}

	CDataType *construct()
	{
		if( frees.size() < 1 )
		{
			CDataType *array = new CDataType[ alloccount ];
			for( int i = 0 ; i < alloccount ; ++i )
			{
				frees.push_back( &array[i] );
			}
			allocs.push_back( array );
			if( alloccount < maxcount )
			{
				alloccount += basecount;
				if( alloccount > maxcount )
				{
					alloccount = maxcount;
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

	void clear()
	{
		frees.clear();
		for( auto iter = allocs.begin() ; iter != allocs.end() ; ++iter )
		{
			delete[] *iter;
		}
		allocs.clear();
	}
};

} //namespace entity
#endif // ENTITYDATAPOOL_HPP_
