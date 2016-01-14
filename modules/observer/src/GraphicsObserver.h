/*
 * GraphicsObserver.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef OBSERVER_SRC_GRAPHICSOBSERVER_H_
#define OBSERVER_SRC_GRAPHICSOBSERVER_H_

#include "Observer.h"
#include "Unit.h"
#include "Event.h"

namespace com {
namespace thiagoh {

class GraphicsObserver: public Observer {
public:
   GraphicsObserver() {

   }
   virtual ~GraphicsObserver() {

   }

   void onNotify(const Unit& unit, const Event& event) {

      if (event == Events::CAR_EXPLODE) {
         printf("GraphicsObserver print a CAR EXPLOSION!\n");
      } else {
         printf("#WARN: GraphicsObserver i'm not interested on this event. Discard it! Unit %s of the event '%s'\n",
               (const char*) unit, (const char*) event);
      }
   }
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* OBSERVER_SRC_GRAPHICSOBSERVER_H_ */
