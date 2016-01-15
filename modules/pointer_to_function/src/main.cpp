/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#include <stdio.h>
#include <string>

#include "Foo.h"

using std::string;
using namespace com::thiagoh;

int main(int argc, char **argv) {

	printf("\n\nBEGIN OF PROGRAM\n\n");

	Foo animal("fox");

	printf("animal.getValue: %s\n", animal.getValue("foo", "bar").c_str());

	string (Foo::*_getValuePointer)(string, string) = &Foo::getValue;

	printf("(animal.*_getValuePointer): %s\n", (animal.*_getValuePointer)("foo", "bar").c_str());

	string (*processValuePointer)(string, string) = &Foo::processValue;

	printf("processValuePointer: %s\n", processValuePointer("foo", "bar").c_str());

	printf("(*processValuePointer): %s\n", (*processValuePointer)("foo", "bar").c_str());

	printf("\n\nEND OF PROGRAM\n");
}

