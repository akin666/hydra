/*
 * log.cpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#include <log>

#ifdef USE_COMMON_LOG

#include <iostream>
#include <native>
#include <stdarg.h>
#include <stdio.h>

#define MAX_LOG_MSG_LEN 2048

Log::Log()
{
}

Log::~Log()
{
}

void Log::printMessage( const string8& message )
{
	::orion::message( message.c_str() );
}

void Log::printError( const string8& message )
{
	::orion::alert( message.c_str() );
}

void Log::printWarning( const string8& message )
{
	::orion::warning( message.c_str() );
}

void Log::message( const char* format , ... )
{
	char buffer[ MAX_LOG_MSG_LEN];
	va_list args;
	va_start( args, format );
	vsnprintf( buffer, (MAX_LOG_MSG_LEN - 1), format, args);
	va_end( args );
	string8 msg(buffer)
	printMessage( msg );
}

void Log::error( const char* format , ... )
{
	char buffer[ MAX_LOG_MSG_LEN];
	va_list args;
	va_start( args, format );
	vsnprintf( buffer, (MAX_LOG_MSG_LEN - 1), format, args);
	va_end( args );
	string8 msg(buffer)
	printError( msg) );
}

void Log::warning( const char* format , ... )
{
	char buffer[ MAX_LOG_MSG_LEN];
	va_list args;
	va_start( args, format );
	vsnprintf( buffer, (MAX_LOG_MSG_LEN - 1), format, args);
	va_end( args );
	string8 msg(buffer)
	printWarning( msg );
}

#endif

