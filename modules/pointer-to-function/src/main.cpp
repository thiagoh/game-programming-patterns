/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#include <stdio.h>
#include <string>

#include "../../pointer-to-function/src/Foo.h"

using std::string;
using namespace com::thiagoh;

double div(double a, double b) {
   return a / b;
}

double percent(double a, double b) {
   return b * 100.0 / a;
}

int main(int argc, char **argv) {

   /*
    * More about Poiter to member function at
    * http://www.codeguru.com/cpp/cpp/article.php/c17401/C-Tutorial-PointertoMember-Function.htm
    */
   printf("\n\nBEGIN OF PROGRAM\n\n");

   Foo animal("fox");

   printf("animal.getValue: %s\n", animal.getValue("foo", "bar").c_str());

   string (Foo::*_getValuePointer)(string, string) = &Foo::getValue;

   printf("(animal.*_getValuePointer): %s\n", (animal.*_getValuePointer)("foo", "bar").c_str());

   string (*processValuePointer)(string, string) = &Foo::processValue;

   printf("processValuePointer: %s\n", processValuePointer("foo", "bar").c_str());

   printf("(*processValuePointer): %s\n", (*processValuePointer)("foo", "bar").c_str());

   /* the ampersand is actually optional */
   double (*func1)(double, double) = &div;
   /* the ampersand is actually optional */
   double (*func2)(double, double) = &percent;
   /* the ampersand is actually optional */
   auto *func3 = &percent;
   /* the ampersand is actually optional */
   auto func4 = &percent;

   printf("(*func1): %.2f\n", (*func1)(10, 5));
   printf("func1: %.2f\n", func1(10, 5));

   printf("(*func2): %.2f\n", (*func2)(10, 5));
   printf("func2: %.2f\n", func2(10, 5));

   printf("auto *func3: %.2f\n", func3(100, 5));
   printf("auto func4: %.2f\n", func4(100, 9));

   auto name = string("julius");
   printf("auto string name: %s\n", name.c_str());

   printf("\n\nEND OF PROGRAM\n");
}

