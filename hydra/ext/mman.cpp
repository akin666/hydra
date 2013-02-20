/*
 * mman.cpp
 *
 *  Created on: 20.2.2013
 *      Author: akin
 */

#include "mman"


#if defined(OS_WINDOWS)
int mmapGetPageSize()
{
	return 0;
}
#else
// Unixeh!
int mmapGetPageSize()
{
	return sysconf(_SC_PAGE_SIZE);
}
#endif
