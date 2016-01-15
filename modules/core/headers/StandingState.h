/*
 * StandingState.h
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#ifndef STANDINGSTATE_H_
#define STANDINGSTATE_H_

#include <stdio.h>

#include <Input.h>
#include <State.h>

namespace com {
namespace thiagoh {

class Unit;

class StandingState: public State {
public:

	StandingState();
	virtual ~StandingState();

	void enter(Unit& unit);
	void update(Unit& unit, long deltaTime);
	State* handleInput(Unit& unit, Input input);

};

} /* namespace thiagoh */
} /* namespace com */

#endif /* STANDINGSTATE_H_ */
