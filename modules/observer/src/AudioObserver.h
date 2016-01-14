/*
 * AudioObserver.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef AUDIOOBSERVER_H_
#define AUDIOOBSERVER_H_

#include <stdio.h>

#include <Event.h>
#include <Unit.h>

#include "Observer.h"

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
         printf("AudioObserver play the sound of a car explosion!\n");
      } else if (event == Events::CAR_HIT) {
         printf("AudioObserver play the sound of a car hit!\n");
      } else if (event == Events::MAN_HIT) {
         printf("AudioObserver play the sound of a man hit!\n");
      } else {
         printf("#WARN: AudioObserver i'm not interested on this event. Discard it! Unit %s of the event '%s'\n",
               (const char*) unit, (const char*) event);
      }

   }
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* AUDIOOBSERVER_H_ */
