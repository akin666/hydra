/*
 * glfwrendertarget.hpp
 *
 *  Created on: 30.1.2013
 *      Author: akin
 */

#ifndef GLFWRENDERTARGET_HPP_
#define GLFWRENDERTARGET_HPP_

#include <graphics/graphicsrendertarget.hpp>
#include <json>

namespace glfw {

class RenderTarget : public graphics::RenderTarget
{
private:
	uint32 state;

	color::Type colormode;
	color::Type depthmode;
	glm::ivec2 dimensions;
	glm::ivec2 clipping;
public:
	RenderTarget();
	virtual ~RenderTarget();

	// Current modes
	virtual color::Type getColorMode() const;
	virtual color::Type getDepthMode() const;
	virtual glm::ivec2 getDimensions() const;

	// Clipping
	virtual void setClipping( const glm::ivec2& dimensions );
	virtual glm::ivec2 getClipping() const;
	virtual void enableClipping( bool state );
	virtual bool isClipping() const;

	// Clearing (depth, color, whatever)
	virtual void clear();

	virtual void bind();
	virtual void unbind();

	bool initialize( Json::ValuePtr& config );
};

} // namespace glfw 
#endif // GLFWRENDERTARGET_HPP_ 
