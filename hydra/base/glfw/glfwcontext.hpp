/*
 * coreglfwcontext.hpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#ifndef GLFWCONTEXT_HPP_
#define GLFWCONTEXT_HPP_

#include <core/corecontext.hpp>

namespace glfw {

class Context : public core::Context
{
public:
	Context();
	virtual ~Context();

	virtual bool initialize( Json::ValuePtr& config );

	virtual graphics::RenderTarget::Ptr getRenderTarget();
};

} // namespace glfw
#endif // GLFWCONTEXT_HPP_
