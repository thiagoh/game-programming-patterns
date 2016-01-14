/*
 * State.h
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#ifndef STATE_H_
#define STATE_H_

#include "Input.h"
#include "Unit.h"

namespace com {
namespace thiagoh {

class Unit;

class State {

public:
	State() {
	}
	virtual ~State() {
	}

	virtual State* handleInput(Unit& unit, Input input) = 0;
	virtual void enter(Unit& unit) = 0;

};

} /* namespace thiagoh */
} /* namespace com */

#endif /* STATE_H_ */
