/*
 * AudioObserver.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef AUDIOOBSERVER_H_
#define AUDIOOBSERVER_H_

#include <iostream>

namespace com {
namespace thiagoh {

class AudioObserver: public Observer {
public:

   AudioObserver() {

   }

   virtual ~AudioObserver() {

   }

   void onNotify(const Unit& unit, Event event) {
      printf("AudioObserver onNotify");
   }
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* AUDIOOBSERVER_H_ */