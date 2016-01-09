/*
 * AudioObserver.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef AUDIOOBSERVER_H_
#define AUDIOOBSERVER_H_

#include <iostream>
#include "Unit.h"
#include "Event.h"

namespace com {
namespace thiagoh {

class AudioObserver: public Observer {
public:

   AudioObserver() {

   }

   virtual ~AudioObserver() {

   }

   void onNotify(const Unit& unit, Event& event) {
      printf("AudioObserver onNotify for unit %s of the event '%s'");//, unit.id().c_str(), event.name()
   }
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* AUDIOOBSERVER_H_ */
