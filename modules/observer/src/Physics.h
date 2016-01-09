/*
 * Physics.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <ctime>
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
      time_t t;
      time(&t);
      srand((unsigned) t);
   }
   virtual ~Physics() {
      delete _subject;
   }
   void updateUnit(Unit& unit) {

      printf("Physics update unit, %s\n", unit.id().c_str());

      Event* event = 0;
      double r = (double) rand() / (double) RAND_MAX;

      if (r < 0.3) {
         event = &Events::CAR_HIT;

      } else if (r > 0.3 && r < 0.55) {
         event = &Events::CAR_EXPLODE;

      } else if (r > 0.55 && r < 0.85) {
         event = &Events::MAN_HIT;

      } else {
         event = &Events::CAR_FALL;
      }

      _subject->notify(unit, *event);

      //printf("All observers were advised properly\n\n");
      printf("\n\n");
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
