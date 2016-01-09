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
   void updateUnit(Unit* unit) {
      printf("Physics update unit, %s", unit->id().c_str());
   }

private:
   Subject* _subject;
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* PHYSICS_H_ */
