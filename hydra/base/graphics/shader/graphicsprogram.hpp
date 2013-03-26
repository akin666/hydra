/*
 * graphicsprogram.h
 *
 *  Created on: 19.4.2010
 *      Author: akin
 */

#ifndef GRAPHICSPROGRAM_H_
#define GRAPHICSPROGRAM_H_

#include <commontypes.h>
#include "graphicsuniform.hpp"
#include "graphicsattribute.hpp"

namespace graphics {

class Shader;
class Program
{
private:
	uint id;
	uint state;

	void setLinking( bool val );
	sint getUniformID( const std::string& key ) const;
public:
	static const unsigned int null;

	Program();
	~Program();

	uint getID() const;

	bool initialize();
	bool initialized() const;
	void release();

	template <class CType> Uniform<CType> getUniform( const std::string& key ) const
	{
		return Uniform<CType>( getUniformID( key ) );
	}

	Attribute getAttribute( const std::string& key ) const;

	void setAttribute( const Attribute& attribute );

	void bind() const;
	static void bindDefault();

	void attach( const Shader& piece );
	void detach( const Shader& piece );
	void link();

	bool hasError() const;
	std::string getError() const;
	bool linked() const;
};

} // namespace graphics

#endif // GRAPHICSPROGRAM_H_
