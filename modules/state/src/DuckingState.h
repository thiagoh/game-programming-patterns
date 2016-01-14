/*
 * DuckingState.h
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#ifndef DUCKINGSTATE_H_
#define DUCKINGSTATE_H_

#include <stdio.h>

#include "../../core/headers/Input.h"
#include "../../core/headers/State.h"
#include "../../core/headers/Unit.h"

namespace com {
namespace thiagoh {

class DuckingState: public State {
public:

	DuckingState() {

	}

	virtual ~DuckingState() {

	}

	void enter(Unit& unit) {
		printf("duck!");
	}

	State* handleInput(Unit& unit, Input input) {

		if (Input::BUTTON_DOWN == input) {

		}

		return NULL;
	}

};

} /* namespace thiagoh */
} /* namespace com */

#endif /* DUCKINGSTATE_H_ */
