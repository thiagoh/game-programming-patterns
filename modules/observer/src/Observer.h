/*
 * Observer.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <stdio.h>

#include "../../core/src/Event.h"
#include "../../core/src/Unit.h"

namespace com {
namespace thiagoh {

class Observer {
public:

   Observer() {

   }

   virtual ~Observer() {

   }

   virtual void onNotify(const Unit& unit, const Event& event) {
      printf("Base Observer onNotify for unit %s of the event '%s'\n", (const char*) unit, (const char*) event);
   }
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* OBSERVER_H_ */
