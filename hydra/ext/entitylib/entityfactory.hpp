/*
 * entityfactory.hpp
 *
 *  Created on: 9.12.2012
 *      Author: akin
 */

#ifndef ENTITYFACTORY_HPP_
#define ENTITYFACTORY_HPP_

namespace entity {

class Context;
class Factory
{
private:
	Context& context;
public:
	Factory( Context& context );
	~Factory();
};

} // namespace entity
#endif // ENTITYFACTORY_HPP_
