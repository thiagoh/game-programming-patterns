/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#include <stdio.h>
#include <Unit.h>

using com::thiagoh::Unit;
using com::thiagoh::Input;

int main(int argc, char **argv) {

   printf("\n\nBEGIN OF PROGRAM\n\n");

   Unit unit1("player 1");

   for (unsigned int i = 0; i < 6; i++) {

      if (i == 1) {
         unit1.handleInput(Input::BUTTON_DOWN);
      }

      if (i == 2) {
         unit1.handleInput(Input::BUTTON_Y);
      }

      if (i == 4) {
         unit1.handleInput(Input::RELEASE_DOWN);
      }
   }

   printf("\n\nEND OF PROGRAM\n");

   return 0;
}

