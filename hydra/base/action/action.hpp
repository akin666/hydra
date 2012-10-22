/*
 * action.hpp
 *
 *  Created on: 1.7.2012
 *      Author: akin
 */

#ifndef HYDRA_ACTION_HPP_
#define HYDRA_ACTION_HPP_

namespace hydra
{

class Action
{
public:
	Action();
	virtual ~Action();

	virtual void act() = 0;
};

} // namespace hydra
#endif // HYDRA_ACTION_HPP_
