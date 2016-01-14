/*
 * DuckingState.h
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#ifndef DUCKINGSTATE_H_
#define DUCKINGSTATE_H_

#include <stdio.h>
#include <Input.h>
#include <State.h>
#include <Unit.h>

namespace com {
namespace thiagoh {

class DuckingState: public State {
public:

	DuckingState();
	virtual ~DuckingState();

	void enter(Unit& unit);
	void update(Unit& unit, long deltaTime);
	State* handleInput(Unit& unit, Input input);
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* DUCKINGSTATE_H_ */
