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

   auto lambdaWithParams = [&] (int a, int b, string c) {return c + " " + std::to_string(a) + " and " + std::to_string(b);};
   printf("New name is %s\n", lambdaWithParams(1, 2, "valores: ").c_str());

   printf("\n\nEND OF PROGRAM\n");
}

