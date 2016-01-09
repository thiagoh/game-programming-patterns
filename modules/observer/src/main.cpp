/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */
#include <stdio.h>
#include <iostream>

#include "Physics.h"
#include "Subject.h"
#include "Unit.h"
#include "Observer.h"
#include "AudioObserver.h"
#include "GraphicsObserver.h"

using com::thiagoh::Physics;
using com::thiagoh::Subject;
using com::thiagoh::Unit;
using com::thiagoh::Observer;
using com::thiagoh::AudioObserver;
using com::thiagoh::GraphicsObserver;

int main(int argc, char **argv) {

   printf("\n\nBEGIN OF PROGRAM\n\n");

   Physics physics;
   Unit unit("foo");

   AudioObserver audioObserver;
   GraphicsObserver graphicsObserver;
   Observer baseObserver;

   physics.subject()->addObserver(&audioObserver);
   physics.subject()->addObserver(&graphicsObserver);
   physics.subject()->addObserver(&baseObserver);

   for (unsigned int i = 0; i < 6; i++) {
      physics.updateUnit(unit);

      if (i == 3) {
         physics.subject()->removeObserver(&baseObserver);
         printf("#INFO: Base Observer removed\n");
      }
   }

   printf("\n\nEND OF PROGRAM\n");
}

