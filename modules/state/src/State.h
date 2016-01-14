/*
 * State.h
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#ifndef STATE_H_
#define STATE_H_

#include "../../core/src/Input.h"
#include "../../core/src/Unit.h"

namespace com {
namespace thiagoh {

class State {

public:
	State::State() {

	}

	virtual State::~State() {
	}

	State* handleInput(Unit& unit, Input input) {

	}
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* STATE_H_ */
