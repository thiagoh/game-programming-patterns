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

#include <cstdio>
#include <string>

class Unit {
public:

   Unit(std::string name) :
         _name(name) {

      init();
      printf("Unit string constructor\n");
   }

   Unit(const Unit& copy) :
         _name(copy._name) {
      init();
      printf("Unit copy constructor\n");
   }

   Unit& operator=(const Unit& lhs) {

      _name = lhs._name;

      printf("Unit operator= constructor\n");

      return *this;
   }

   ~Unit() {
      printf("Unit %s died\n", _name.c_str());
   }

   std::string id() const {
      return _name;
   }

private:
   std::string _name;

   void init() {
      printf("Unit %s created\n", _name.c_str());
   }
};

class GeneralTest: public CppUnit::TestFixture {

public:

   void setUp() {

   }

   void tearDown() {

   }

   void test_generic() {

      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", true);
   }

   void test_delete_copied_pointer() {

      printf("test_delete_copied_pointer started\n");

      printf("\n1: ");
      Unit* unit1 = new Unit("UNIT_NAME test_delete_copied_pointer");
      printf("\n2: ");
      Unit* unit2 = unit1;
      printf("\n3: ");
      Unit unit3(*unit2);
      printf("\n4: ");
      Unit unit4 = *unit2;

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

   void test_delete_reference_pointer() {

      printf("test_delete_reference_pointer started\n\n");

      Unit* unit1 = new Unit("UNIT_NAME test_delete_reference_pointer");
      Unit* unit2 = unit1;

      _test_delete_reference_pointer(unit1, unit2);

      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", unit1 == 0);
      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", unit2 == 0);

      CPPUNIT_ASSERT_MESSAGE("Should not point to NULL", unit1 == NULL);
      CPPUNIT_ASSERT_MESSAGE("Should not point to NULL", unit2 == NULL);

      printf("test_delete_reference_pointer ended\n\n");
   }

private:

   void _test_delete_reference_pointer(Unit* &unit1, Unit* &unit2) {

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

      CPPUNIT_ASSERT_MESSAGE("Should not point to NULL", unit1 == NULL);
      CPPUNIT_ASSERT_MESSAGE("Should not point to NULL", unit2 == NULL);
   }
};

int main(int argc, char **argv) {

   // Create the event manager and test controller
   CppUnit::TestResult controller;
   CppUnit::TestResultCollector result;
   controller.addListener(&result);

   // ####
   // #### Can do it this way
   // ####
   CppUnit::TestSuite suite("Simple Tests");
   suite.addTest(
         new CppUnit::TestCaller<GeneralTest>("test_delete_copied_pointer", &GeneralTest::test_delete_copied_pointer));
   suite.addTest(
         new CppUnit::TestCaller<GeneralTest>("test_delete_reference_pointer",
               &GeneralTest::test_delete_reference_pointer));

   suite.run(&controller);

   // ####
   // #### Or this way
   // ####
   // Add the top suite to the test runner
   CppUnit::TestRunner runner;
   runner.addTest(new CppUnit::TestCaller<GeneralTest>("test_generic", &GeneralTest::test_generic));
   runner.run(controller);

   // Print test in a compiler compatible format.
   CppUnit::CompilerOutputter outputter(&result, CPPUNIT_NS::stdCOut());
   outputter.write();
}

