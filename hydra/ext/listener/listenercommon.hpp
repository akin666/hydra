/*
 * listenercommon.hpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#ifndef LISTENERCOMMON_HPP_
#define LISTENERCOMMON_HPP_

namespace listener {

enum Button
{
	LEFT,
	RIGHT,
	MIDDLE,
	ADDON_1,
	ADDON_2,
	ADDON_3,
	ADDON_4,
	ADDON_5,
	ADDON_6,
	ADDON_LAST
};

enum State
{
	BEGIN,
	END,
	MOVED,
	CANCELLED
};

}

#endif // LISTENERCOMMON_HPP_ 
