/*
 * renderrenderer.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef RENDERRENDERER_HPP_
#define RENDERRENDERER_HPP_

#include <protothread>

namespace render {

class Renderer : public Protothread
{
public:
	Renderer();
	virtual ~Renderer();
};

} // namespace render
#endif // RENDERRENDERER_HPP_
