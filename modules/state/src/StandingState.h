/*
 * StandingState.h
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#ifndef STANDINGSTATE_H_
#define STANDINGSTATE_H_

#include <stdio.h>

#include "../../core/headers/Input.h"
#include "../../core/headers/State.h"
#include "../../core/headers/Unit.h"

namespace com {
namespace thiagoh {

class StandingState: public State {
public:

	StandingState() {

	}

	virtual ~StandingState() {

	}

	void enter(Unit& unit) {
		printf("stand up!");
	}

	State* handleInput(Unit& unit, Input input) {

		if (Input::BUTTON_DOWN == input) {

		}

		return NULL;
	}
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* STANDINGSTATE_H_ */
