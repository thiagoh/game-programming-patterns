/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/portability/Stream.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#include <Unit.h>
#include <cstdio>
#include <string>

using com::thiagoh::Unit;

class GeneralTest: public CppUnit::TestFixture {

public:

   void setUp() {

   }

   void tearDown() {

   }

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

      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", unit1 != 0);
      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", unit2 != 0);

      unit1 = NULL; // not a dangling pointer anymore
      unit2 = NULL; // not a dangling pointer anymore

      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", unit1 == 0);
      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", unit2 == 0);

      printf("unit1 address: %p\n", unit1);
      printf("unit2 address: %p\n", unit2);

      if (unit2 != NULL) {
         printf("unit2 pointer: %s\n", unit2->id().c_str());
      } else {
         printf("unit2 pointer is null\n");
      }
   }
};

int main(int argc, char **argv) {

   printf("\n\nBEGIN OF PROGRAM\n\n");

   CppUnit::TestCaller<GeneralTest> * test = new CppUnit::TestCaller<GeneralTest>("testEquality", &GeneralTest::test1);

   // Create the event manager and test controller
   CppUnit::TestResult controller;
   CppUnit::TestResultCollector result;
   controller.addListener(&result);

   // Add the top suite to the test runner
   CppUnit::TestRunner runner;
   runner.addTest(test);
   runner.run(controller);

   // Print test in a compiler compatible format.
   CppUnit::CompilerOutputter outputter(&result, CPPUNIT_NS::stdCOut());
   outputter.write();

   printf("\n\nEND OF PROGRAM\n");
}

