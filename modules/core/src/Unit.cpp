/*
 * Unit.cpp
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */


#include <StandingState.h>
#include <Unit.h>

using com::thiagoh::Unit;
using com::thiagoh::StandingState;

Unit::Unit(std::string id) :
		_id(id), state(0) {
	this->state = new StandingState();
}

Unit::~Unit() {

}

void Unit::handleInput(Input input) {

	State* newState = state->handleInput(*this, input);

	if (newState != NULL) {
		delete state;
		state = newState;

		// Call the enter action on the new state.
		newState->enter(*this);
	}
}
