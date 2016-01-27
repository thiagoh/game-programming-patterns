/*
 * main.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: thiago
 */

#include <stdio.h>
#include <string>
#include <functional>

using std::string;

void call(std::function<void()> func) {

   func();
   func();
}

std::function<float()> getLambda(int ix) {

   if (ix == 1) {

      return [=] {return 3.14;};

   } else if (ix >= 2 && ix < 10) {
      int value = 4;

      return [=] {return ix * value;};

   } else {

      double value1 = 13.3;
      string name = "foo bar";
      static string myStaticString = "foo static string bar";

      // this cannot be done because name is a local reference
      // so when the method is over the reference may not exist anymore
      //return [=, &name] {return ix * value1 * name.size();};

      // this cannot be done because myStaticString is a local static
      // variable, so event without "&myStaticString" it will be
      // caught by reference
      // return [=, &myStaticString] {return ix * value1 * name.size()* myStaticString.size();};

      return [=] {return ix * value1 * name.size()* myStaticString.size();}; // lambda catching myStaticString by reference
   }
}

std::function<float()> getLambda2(int ix, int *p) {

   return [=] {return ix * (*p);}; // lambda catching myStaticString by reference
}

int main(int argc, char **argv) {

   printf("\n\nBEGIN OF PROGRAM\n\n");

   auto firstLambda = [] {printf("my first lambda\n");};
   firstLambda();

   string name = string("antonius carlo");
   auto lambdaRef1 = [&] {printf("my lambda with outside ref %s\n", name.c_str());};
   lambdaRef1();

   // modifier 1
   auto modifierLambda1 = [&] {name = name + " is the one!";};
   modifierLambda1();
   printf("New name is %s\n", name.c_str());

   // modifier 2
   [&] {name = name + " He is even better!";}();
   printf("New name is %s\n", name.c_str());

   auto modifierLambda3 = [&] {name = name + " He is almost the best!";};
   call(modifierLambda3);
   printf("New name is %s\n", name.c_str());

   auto lambdaWithParams =
         [&] (int a, int b, string c) {return c + " " + std::to_string(a) + " and " + std::to_string(b);};
   printf("New name is %s\n", lambdaWithParams(1, 2, "valores: ").c_str());

   auto lambdaFor1 = getLambda(1);
   auto lambdaFor2 = getLambda(2);
   auto lambdaFor5 = getLambda(5);
   auto lambdaFor10 = getLambda(10);

   printf("lambdaFor1 is %0.2f\n", lambdaFor1());
   printf("lambdaFor2 is %0.2f\n", lambdaFor2());
   printf("lambdaFor5 is %0.2f\n", lambdaFor5());
   printf("lambdaFor10 is %0.2f\n", lambdaFor10());

   printf("\n\nEND OF PROGRAM\n");
}

