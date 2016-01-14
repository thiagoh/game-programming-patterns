/*
 * StandingState.cpp
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#include <State.h>
#include <DuckingState.h>
#include <StandingState.h>

using com::thiagoh::StandingState;

StandingState::StandingState() :
		State() {
}

StandingState::~StandingState() {
}

void StandingState::enter(Unit& unit) {
	printf("stand up!");
}

void StandingState::update(Unit& unit, long deltaTime) {
	_deltaTime += deltaTime;
}

State* StandingState::handleInput(Unit& unit, Input input) {

	if (Input::BUTTON_DOWN == input) {
		return new DuckingState();
	}

	return NULL;
}
