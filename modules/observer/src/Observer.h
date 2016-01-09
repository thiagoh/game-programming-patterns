/*
 * Observer.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <stdio.h>

#include "Event.h"
#include "Unit.h"

namespace com {
namespace thiagoh {

class Observer {
public:

   Observer() {

   }

   virtual ~Observer() {

   }

   virtual void onNotify(const Unit& unit, const Event& event) = 0;
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* OBSERVER_H_ */
