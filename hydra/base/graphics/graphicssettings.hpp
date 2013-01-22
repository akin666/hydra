/*
 * graphicssettings.hpp
 *
 *  Created on: 12.7.2012
 *      Author: akin
 */

#ifndef GRAPHICSSETTINGS_HPP_
#define GRAPHICSSETTINGS_HPP_

#include <commontypes.h>
#include <json>

namespace graphics {

class Settings
{
protected:
	glm::ivec2 dimensions;
	glm::ivec4 colors;
	float32 dpi;
	int32 stencil;
	int32 depth;
	int32 flags;
public:
	Settings();
    Settings( const Settings& other );
	~Settings();

	void parse( Json::Value *value );

	int32 getAlpha() const;
	void setAlpha(int32 alpha);

	int32 getBlue() const;
	void setBlue(int32 blue);

	int32 getDepth() const;
	void setDepth(int32 depth);

	const glm::ivec2& getDimensions() const;
	void setDimensions(const glm::ivec2& dimensions);

	void setWidth( int width );
	void setHeight( int height );

	float32 getDpi() const;
	void setDpi(float32 dpi);

	int32 getGreen() const;
	void setGreen(int32 green);

	int32 getRed() const;
	void setRed(int32 red);

	int32 getStencil() const;
	void setStencil(int32 stencil);

	bool getFullscreen() const;
	void setFullscreen(bool val);
};

typedef std::vector<Settings> SettingsSet;

} // namespace graphics 

#endif // GRAPHICSSETTINGS_HPP_
