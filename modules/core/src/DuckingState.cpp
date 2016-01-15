/*
 * DuckingState.cpp
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#include <State.h>
#include <DuckingState.h>
#include <StandingState.h>

using com::thiagoh::State;
using com::thiagoh::DuckingState;
using com::thiagoh::StandingState;

DuckingState::DuckingState() :
      State() {
}

DuckingState::~DuckingState() {
}

void DuckingState::enter(Unit& unit) {
   printf("duck!\n");
   _deltaTime = 0;
}

void DuckingState::update(Unit& unit, long deltaTime) {
   _deltaTime += deltaTime;
}

State* DuckingState::handleInput(Unit& unit, Input input) {

   State* state = NULL;

   if (RELEASE_DOWN == input) {
      state = new StandingState();
   }

   return state;
}
