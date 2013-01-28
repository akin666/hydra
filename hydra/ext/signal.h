/*
 *  signal.h
 *  CoreGame
 *  A lightweight signals and slots implementation using fast delegates
 *
 *  Created by Patrick Hogan on 5/18/09.
 *
 *  Original source: https://github.com/pbhogan/Signals
 *
 *  -> The author mentions that the source is under MIT license (added here):
 *
 *  The MIT License (MIT)
 *	Copyright (c) 2009 <Patrick Hogan>
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 *  -> mods: changed filenames to lowercase. changed namespace.
 */

#ifndef _Signal_H_
#define _Signal_H_

#include "delegate.h"
#include <set>

namespace signal {

template< class Param0 = void >
class Signal0
{
public:
	typedef Delegate0< void > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)() )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)() const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)() )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)() const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit() const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))();
		}
	}

	void operator() () const
	{
		Emit();
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


template< class Param1 >
class Signal1
{
public:
	typedef Delegate1< Param1 > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1 ) )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1 ) const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1 ) )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1 ) const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit( Param1 p1 ) const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))( p1 );
		}
	}

	void operator() ( Param1 p1 ) const
	{
		Emit( p1 );
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


template< class Param1, class Param2 >
class Signal2
{
public:
	typedef Delegate2< Param1, Param2 > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2 ) )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2 ) const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2 ) )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2 ) const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit( Param1 p1, Param2 p2 ) const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))( p1, p2 );
		}
	}

	void operator() ( Param1 p1, Param2 p2 ) const
	{
		Emit( p1, p2 );
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


template< class Param1, class Param2, class Param3 >
class Signal3
{
public:
	typedef Delegate3< Param1, Param2, Param3 > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3 ) )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3 ) const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3 ) )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3 ) const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit( Param1 p1, Param2 p2, Param3 p3 ) const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))( p1, p2, p3 );
		}
	}

	void operator() ( Param1 p1, Param2 p2, Param3 p3 ) const
	{
		Emit( p1, p2, p3 );
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


template< class Param1, class Param2, class Param3, class Param4 >
class Signal4
{
public:
	typedef Delegate4< Param1, Param2, Param3, Param4 > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4 ) )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4 ) const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4 ) )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4 ) const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit( Param1 p1, Param2 p2, Param3 p3, Param4 p4 ) const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))( p1, p2, p3, p4 );
		}
	}

	void operator() ( Param1 p1, Param2 p2, Param3 p3, Param4 p4 ) const
	{
		Emit( p1, p2, p3, p4 );
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


template< class Param1, class Param2, class Param3, class Param4, class Param5 >
class Signal5
{
public:
	typedef Delegate5< Param1, Param2, Param3, Param4, Param5 > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5 ) )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5 ) const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5 ) )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5 ) const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5 ) const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))( p1, p2, p3, p4, p5 );
		}
	}

	void operator() ( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5 ) const
	{
		Emit( p1, p2, p3, p4, p5 );
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


template< class Param1, class Param2, class Param3, class Param4, class Param5, class Param6 >
class Signal6
{
public:
	typedef Delegate6< Param1, Param2, Param3, Param4, Param5, Param6 > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6 ) )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6 ) const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6 ) )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6 ) const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6 ) const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))( p1, p2, p3, p4, p5, p6 );
		}
	}

	void operator() ( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6 ) const
	{
		Emit( p1, p2, p3, p4, p5, p6 );
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


template< class Param1, class Param2, class Param3, class Param4, class Param5, class Param6, class Param7 >
class Signal7
{
public:
	typedef Delegate7< Param1, Param2, Param3, Param4, Param5, Param6, Param7 > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7 ) )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7 ) const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7 ) )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7 ) const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7 ) const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))( p1, p2, p3, p4, p5, p6, p7 );
		}
	}

	void operator() ( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7 ) const
	{
		Emit( p1, p2, p3, p4, p5, p6, p7 );
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


template< class Param1, class Param2, class Param3, class Param4, class Param5, class Param6, class Param7, class Param8 >
class Signal8
{
public:
	typedef Delegate8< Param1, Param2, Param3, Param4, Param5, Param6, Param7, Param8 > _Delegate;

private:
	typedef std::set<_Delegate> DelegateList;
	typedef typename DelegateList::const_iterator DelegateIterator;
	DelegateList delegateList;

public:
	void Connect( _Delegate delegate )
	{
		delegateList.insert( delegate );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8 ) )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Connect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8 ) const )
	{
		delegateList.insert( MakeDelegate( obj, func ) );
	}

	void Disconnect( _Delegate delegate )
	{
		delegateList.erase( delegate );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8 ) )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	template< class X, class Y >
	void Disconnect( Y * obj, void (X::*func)( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8 ) const )
	{
		delegateList.erase( MakeDelegate( obj, func ) );
	}

	void Clear()
	{
		delegateList.clear();
	}

	void Emit( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8 ) const
	{
		for (DelegateIterator i = delegateList.begin(); i != delegateList.end(); )
		{
			(*(i++))( p1, p2, p3, p4, p5, p6, p7, p8 );
		}
	}

	void operator() ( Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8 ) const
	{
		Emit( p1, p2, p3, p4, p5, p6, p7, p8 );
	}

	bool Empty() const
	{
        return delegateList.empty();
    }
};


} // namespace

// Example:
/*
 *
 *  Example.cpp
 *  Signals and Slots example code.
 *
 *  Created by Patrick Hogan on 5/18/09.
 *
 * /

#include <stdio.h>

#include "Delegate.h"
#include "Signal.h"
using namespace Gallant;


class Button
{
public:
	Signal0< void > update0;
	Signal1< int > update1;
	Signal2< int,float & > update2;

	void ClickButton( void )
	{
		update0();
		update1( 1 );
		float f = 34.5;
		update2( 2, f );
	}
};


class Label
{
public:
	virtual void Update0( void ) const
	{
		printf( "Update0( void ) \n" );
	}

	void Update1( int i )
	{
		printf( "Update1( %d ) \n", i );
	}

	void Update2( int i, float & f )
	{
		printf( "Update2( %d, %.1f )\n", i, f );
	}

	static void Static( void )
	{
		printf( "Static( void ) \n" );
	}
};


class Label2 : public Label
{
public:
	virtual void Update0( void ) const
	{
		printf( "virtual Update0( void ) \n" );
	}
};


void Global( void )
{
	printf( "Global( void ) \n" );
}


int main()
{
	Label l;
	Label2 l2;
	Button b;

	// Test plain delegate
	Delegate1< int > delegate;
	delegate.Bind( &l, &Label::Update1 );
	delegate( 5 );

	// Connect a bunch of signals
	b.update0.Connect( &l, &Label::Update0 ); // zero parameter
	b.update2.Connect( &l, &Label::Update2 ); // two parameters
	b.update0.Connect( &l2, &Label::Update0 ); // virtual method
	b.update0.Connect( &Global ); // global function
	b.update0.Connect( &Label::Static ); // static method

	#define Connect( a, signal, b, slot ) a.signal.Connect( &b, &slot )
	Connect( b, update1, l, Label::Update1 ); // we could do QT style with a macro

	b.ClickButton(); // emit signals

	printf( "Disconnect Update0, Update1 and Global \n" );
	b.update0.Disconnect( &l, &Label::Update0 );
	b.update0.Disconnect( &l2, &Label::Update0 );
	b.update1.Disconnect( &l, &Label::Update1 );
	b.update0.Disconnect( &Global );

	b.ClickButton(); // emit signals again, shouldn't see disconnected slots firing
}
 */

#endif //_SIGNAL_H_
