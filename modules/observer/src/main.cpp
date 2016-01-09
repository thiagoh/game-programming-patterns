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

using com::thiagoh::Physics;

int main(int argc, char **argv) {

	printf("\n BEGIN OF PROGRAM\n");

	Physics physics;

	while(true) {

	   physics.updateUnit(0);
	}

	printf("\n\n\n\n END OF PROGRAM\n");
}



