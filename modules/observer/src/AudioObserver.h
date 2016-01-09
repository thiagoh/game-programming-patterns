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

   void onNotify(const Unit& unit, const Event& event) {

      if (event == Events::CAR_EXPLODE) {
         printf("AudioObserver play the sound of a car explosion!");
      } else if (event == Events::CAR_HIT) {
         printf("AudioObserver play the sound of a car hit!");
      } else {
         printf("AudioObserver play the generic sound. For unit %s of the event '%s'\n", (const char*) unit,
               (const char*) event);
      }

   }
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* AUDIOOBSERVER_H_ */
