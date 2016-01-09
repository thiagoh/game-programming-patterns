/*
 * Physics.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <stdio.h>
#include <string>
#include <stdlib.h>

#include "Subject.h"
#include "Unit.h"

namespace com {
namespace thiagoh {

class Physics {

public:
   Physics() :
         _subject(0) {
      _subject = new Subject("physics");
   }
   virtual ~Physics() {
      delete _subject;
   }
   void updateUnit(Unit& unit) {

      printf("Physics update unit, %s\n", unit.id().c_str());

      Event* event = 0;
      double r = rand() / RAND_MAX;

      if (r < 0.3) {
         event = &Events::CAR_HIT;

      } else if (r > 0.3 && r < 0.6) {

         event = &Events::CAR_EXPLODE;

      } else {

         event = &Events::CAR_FALL;
      }
      _subject->notify(unit, *event);

      printf("All observers were advised properly\n\n");
   }
   Subject* subject() {
      return _subject;
   }

private:
   Subject* _subject;
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* PHYSICS_H_ */
