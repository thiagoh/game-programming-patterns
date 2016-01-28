/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#include <stdio.h>
#include <Unit.h>
#include <string>

using com::thiagoh::Unit;

void test1() {

	Unit* unit1 = new Unit("UNIT_NAME 1");
	Unit* unit2 = unit1;

	printf("unit1 pointer: %s\n", unit1->id().c_str());

	if (unit2 != NULL) {
		printf("unit2 pointer: %s\n", unit2->id().c_str());
	} else {
		printf("unit2 pointer is null\n");
	}

	/*
	 * http://stackoverflow.com/a/2910694/889213
	 *
	 * calling delete on a pointer does not set the pointer to NULL
	 * it still points to the address of memory that previously was allocated
	 */

	delete unit1;

	/*
	 * A pointer to memory that is no longer allocated is called a
	 * pointer and accessing it will usually cause strange program behaviour
	 * and crashes, since its contents are probably not what you expect
	 */
	unit1; // dangling pointer
	unit2; // dangling pointer

	unit1 = NULL; // not a dangling pointer anymore
	unit2 = NULL; // not a dangling pointer anymore

	printf("unit1 address: %p\n", unit1);
	printf("unit2 address: %p\n", unit2);

	if (unit2 != NULL) {
		printf("unit2 pointer: %s\n", unit2->id().c_str());
	} else {
		printf("unit2 pointer is null\n");
	}

}

int main(int argc, char **argv) {

	printf("\n\nBEGIN OF PROGRAM\n\n");

	test1();

	printf("\n\nEND OF PROGRAM\n");
}

