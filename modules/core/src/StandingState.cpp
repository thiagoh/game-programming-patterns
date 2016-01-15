/*
 * StandingState.cpp
 *
 *  Created on: Jan 14, 2016
 *      Author: thiagoh
 */

#include <State.h>
#include <DuckingState.h>
#include <StandingState.h>

using com::thiagoh::State;
using com::thiagoh::StandingState;
using com::thiagoh::DuckingState;

StandingState::StandingState() :
      State() {
}

StandingState::~StandingState() {
}

void StandingState::enter(Unit& unit) {
   printf("stand up!\n");
   _deltaTime = 0;
}

void StandingState::update(Unit& unit, long deltaTime) {
   _deltaTime += deltaTime;
}

State* StandingState::handleInput(Unit& unit, Input input) {

   State* state = NULL;

   if (BUTTON_DOWN == input) {
      state = new DuckingState();
   }

   return state;
}
