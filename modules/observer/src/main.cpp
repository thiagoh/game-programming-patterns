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

using com::thiagoh::Physics;
using com::thiagoh::Subject;
using com::thiagoh::Unit;

int main(int argc, char **argv) {

   printf("\n BEGIN OF PROGRAM\n");

   Physics physics;
   Unit unit("foo");

   for (unsigned int i = 0; i < 100; i++) {
      physics.updateUnit(unit);
   }

   printf("\n\n\n\n END OF PROGRAM\n");
}

