/*
 * commonnative.cpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#include <native>

#define USE_COMMON_NATIVELIB
#ifdef USE_COMMON_NATIVELIB

#include <iostream>
#include <cstdio>

#include <fstream>
#include <string>
#include <cerrno>

#include <stb_image.h>
#include <TGAImage.h>

#include <pixelformat>
#include <log>

#include <sys/time.h>
#include <mman>

#ifndef MAX_TEXT_FILE_SIZE
# define MAX_TEXT_FILE_SIZE 1048576 // 1Megs
#endif

#ifndef MAX_IMAGE_FILE_SIZE
# define MAX_IMAGE_FILE_SIZE 33554432 // 32Megs
#endif

#ifndef MAX_IMAGE_RESOLUTION
# define MAX_IMAGE_RESOLUTION 8192 // So, max to be 8192*8192 ~ 268,435,456 bytes, 268Mb, thats quite alot..
#endif

using namespace pixel;

namespace native {

void log( const std::string& hint , const char *message )
{
	std::cout << hint << " : " << message << std::endl;
}

// Time
// Precise UTC Time
void getTime( Time& time )
{
	// TODO!
	timeval tmp;
	gettimeofday( &tmp , NULL );

	time.us = tmp.tv_usec + (tmp.tv_sec * S_TO_US);
}

// Local Time
void getTime( LocalTime& time )
{
	time_t rawtime;
	struct tm * info;
	::time ( &rawtime );
	info = localtime ( &rawtime );

	time.setYear( info->tm_year + 1900 );
	time.setMonth( info->tm_mon + 1 );
	time.setDay( info->tm_mday );
	time.setHour( info->tm_hour );
	time.setMinute( info->tm_min );
	time.setSecond( info->tm_sec );
	time.setWeekday( info->tm_wday + 1 );
	time.setDayOfYear( info->tm_yday + 1 );
	time.setTimezone( 666 );
}


// File I/O
FILE *openFileRead( const std::string& hint , const std::string& path )
{
	return fopen ( path.c_str() , "rb" );
}

FILE *openFileWrite( const std::string& hint , const std::string& path )
{
	return fopen ( path.c_str() , "wb" );
}

void closeFile( FILE *file )
{
	fclose( file );
}

bool readFile( const std::string& hint , const std::string& path , std::string& content )
{
	std::ifstream file( path , std::ios::in | std::ios::binary );
	if( file )
	{
		file.seekg( 0, std::ios::end );
		content.resize( file.tellg() );
		file.seekg( 0, std::ios::beg );
		file.read( &content[0] , content.size() );
		file.close();
		return true;
	}
	return false;
}

// File information
// returns true, if exists
bool fileInfo( const std::string& hint , File& file )
{
	struct stat st;
	if( stat( file.getPath().c_str(), &st) == -1 )
	{
		return false;
	}

	file.setModified( st.st_mtime );
	file.setSize( st.st_size );
	file.setDirectory( (st.st_mode & S_IFMT) == S_IFDIR );

	return true;
}

// Directory listing.. in C ... needs a lot of refactoring, to bring the code to this century..
// http://www.java-samples.com/showtutorial.php?tutorialid=573
#define NAME_MAX   14
#ifndef DIRSIZ
# define DIRSIZ  14
#endif
typedef struct { long ino; char name[NAME_MAX+1]; } Dirent;
typedef struct { int fd; Dirent d; } DIR;
struct direct { ino_t d_ino; char  d_name[DIRSIZ]; };

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;

	if( (dfd = opendir(dir)) == NULL )
	{
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	while( (dp = readdir(dfd)) != NULL )
	{
		if( strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") )
		{
		   continue;
		}
		if( strlen(dir)+strlen(dp->name)+2 > sizeof(name) )
		{
		   fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
		}
		else
		{
		   sprintf(name, "%s/%s", dir, dp->name);
		   (*fcn)(name);
		}
	}
	closedir(dfd);
}

DIR *opendir(char *dirname)
{
	int fd;
	struct stat stbuf;
	DIR *dp;

	if( (fd = open(dirname, O_RDONLY, 0) ) == -1 )
	{
		return NULL;
	}

	if( fstat(fd, &stbuf) == -1 )
	{
		return NULL;
	}

	if( ( stbuf.st_mode & S_IFMT ) != S_IFDIR )
	{
		return NULL;
	}

	if( ( dp = (DIR *)malloc( sizeof(DIR) ) ) == NULL )
	{
		return NULL;
	}

	dp->fd = fd;
	return dp;
}

void closedir(DIR *dp)
{
	if( dp )
	{
		close(dp->fd);
		free(dp);
	}
}

Dirent *readdir(DIR *dp)
{
   struct direct dirbuf;  /* local directory structure */
   static Dirent d;      /* return: portable structure */

   while( read(dp->fd, (char *) &dirbuf, sizeof(dirbuf) ) == sizeof(dirbuf) )
   {
	   if (dirbuf.d_ino == 0)
	   {
		   continue;
	   }
	   d.ino = dirbuf.d_ino;
	   strncpy(d.name, dirbuf.d_name, DIRSIZ);
	   d.name[DIRSIZ] = '\0';  /* ensure termination */
	   return &d;
   }
   return NULL;
}

bool directoryListing( const std::string& hint , File& file , File::Set& set )
{
	struct stat st;
	if( stat( file.getPath().c_str(), &st) == -1 )
	{
		return false;
	}

	file.setModified( st.st_mtime );
	file.setSize( st.st_size );
	file.setDirectory( (st.st_mode & S_IFMT) == S_IFDIR );

	if( !file.isDirectory() )
	{
		return false;
	}

	// now populate the set.

	// TODO

	return true;
}

// MMAP File I/O
void *openMMAP( const std::string& hint , const String8& path , int& totalSize , int& offset , int& fd , int requestedOffset , int requestedSize , unsigned int accessFlags )
{
	return nullptr;
}

void closeMMAP( void *ptr , int size , int fd )
{
}

// Image loading functionality _always_ happens through softimage
bool loadImageFile( const std::string path , simg::Buffer& softimage )
{
	// define MAX_IMAGE_FILE_SIZE 33554432
	// define MAX_IMAGE_RESOLUTION 8192
	FILE * file = openFileRead( "" , path );

	if( file == NULL )
	{
		return false;
	}

	int64 size;
	int8 *buffer;

	fseek( file , 0L , SEEK_END);
	size = ftell( file );
	rewind( file );

	if( size > MAX_IMAGE_FILE_SIZE )
	{
		closeFile( file );
		return false;
	}

	buffer = new int8[size + 1];

	if( buffer == NULL )
	{
		closeFile( file );
		return false;
	}

	if( fread( buffer , size, 1 , file ) != 1 )
	{
		delete[] buffer;
		closeFile( file );
		return false;
	}

	closeFile( file );

	// Load image..
	glm::ivec2 resolution;
	int req_comp = 4; // req RGBA

	stbi_uc *data = stbi_load_from_memory( (stbi_uc *)buffer , size , &resolution.x, &resolution.y, &req_comp , req_comp );

	// free filedata buffer.
	delete[] buffer;

	if( resolution.x > MAX_IMAGE_RESOLUTION || resolution.y > MAX_IMAGE_RESOLUTION || req_comp < 1 || req_comp > 4 )
	{
		stbi_image_free( data );
		LOG->error("%s @%i MAX_IMAGE tests failed!" , __FUNCTION__ , __LINE__ );
		return false;
	}

	switch( req_comp )
	{
		case 1 : softimage.setMode( ALPHA8 ); break;
		case 3 : softimage.setMode( RGB8 ); break;
		case 4 : softimage.setMode( RGBA8 ); break;
		default:
		{
			// error..
			LOG->error("%s @%i req_comp tests failed! %i count." , __FUNCTION__ , __LINE__ , req_comp );
			stbi_image_free( data );
			return false;
		}
	}

	softimage.setResolution( resolution );
	if( !softimage.initialize() )
	{
		LOG->error("%s @%i softimage.initialize failed!" , __FUNCTION__ , __LINE__ );
		stbi_image_free( data );
		return false;
	}
	if( !softimage.drawRect( glm::ivec2(0,0) , resolution , data ) )
	{
		LOG->error("%s @%i softimage.drawRect failed!" , __FUNCTION__ , __LINE__ );
		stbi_image_free( data );
		return false;
	}

	// free imagedata
	stbi_image_free( data );
	return true;
}

bool saveImageFile( const std::string path , simg::Buffer& softimage )
{
	switch( softimage.getMode() )
	{
	case RGBA8 :
		return imagesaver::RGBA8write( path + ".tga" , softimage.getResolution().x , softimage.getResolution().y , softimage.access() );
	case RGB8 :
		return imagesaver::RGB8write( path + ".tga" , softimage.getResolution().x , softimage.getResolution().y , softimage.access() );
	case ALPHA8 	:
	case LUMINANCE 	:
	case INTENSITY 	:
		return imagesaver::ALPHA8write( path + ".tga" , softimage.getResolution().x , softimage.getResolution().y , softimage.access() );
	default :
		break;
	}
	return false;
}

} // native

#endif // USE_COMMON_NATIVE

