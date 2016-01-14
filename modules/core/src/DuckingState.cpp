/*
 * DuckingState.cpp
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#include <State.h>
#include <DuckingState.h>
#include <StandingState.h>

using com::thiagoh::DuckingState;

DuckingState::DuckingState() :
		State() {
}

DuckingState::~DuckingState() {
}

void DuckingState::enter(Unit& unit) {
	printf("duck!");
	_deltaTime = 0;
}

void DuckingState::update(Unit& unit, long deltaTime) {
	_deltaTime += deltaTime;
}

State* DuckingState::handleInput(Unit& unit, Input input) {


	if (Input::RELEASE_DOWN == input) {
//		return new StandingState();
	}

	return NULL;
}
