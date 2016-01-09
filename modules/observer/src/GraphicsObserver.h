/*
 * GraphicsObserver.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef OBSERVER_SRC_GRAPHICSOBSERVER_H_
#define OBSERVER_SRC_GRAPHICSOBSERVER_H_

namespace com {
namespace thiagoh {

class GraphicsObserver: public Observer {
public:
   GraphicsObserver() {

   }
   virtual ~GraphicsObserver() {

   }

   void onNotify(const Unit& unit, const Event& event) {
      printf("GraphicsObserver onNotify for unit %s of the event '%s'\n", (const char*) unit, (const char*) event);
   }
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* OBSERVER_SRC_GRAPHICSOBSERVER_H_ */
