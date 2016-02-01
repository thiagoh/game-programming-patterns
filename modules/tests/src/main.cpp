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
         _name(""), _phones(0) {

      init(name, std::vector<std::string>());
      printf("Unit string constructor\n");
   }

   Unit(const Unit& copy) :
         _name(""), _phones(0) {

      init(copy._name, copy._phones);
      printf("Unit copy constructor\n");
   }

   Unit& operator=(const std::string name) {

      printf("Unit %s became Unit %s\n", _name.c_str(), name.c_str());

      _name = name;

      printf("Unit operator= std::string implicit cast\n");

      return *this;
   }

   Unit& operator=(const Unit& rhs) {

      if (this == &rhs) {
         return *this;
      }

      printf("Unit %s became Unit %s\n", _name.c_str(), rhs._name.c_str());

      _name = rhs._name;

      printf("Unit operator= constructor\n");

      return *this;
   }

   ~Unit() {
      printf("Unit %s died\n", _name.c_str());
   }

   std::string id() const {
      return _name;
   }

   void phones(const std::vector<std::string> phoneNumbers) {

      std::vector<std::string>::const_iterator i1 = _phones.begin();
      for (std::vector<std::string>::const_iterator i2 = phoneNumbers.begin(); i2 != phoneNumbers.end(); i2++, i1++) {
         _phones.insert(i1, *i2);
      }
   }

private:
   std::string _name;
   static const int FAMILY_NAMES = 3;
   std::vector<std::string> _phones;

   static int counter() {
      static int c = 0;
      return ++c;
   }

   void init(std::string name, const std::vector<std::string> phoneNumbers) {

      _name = name + "_" + std::to_string(counter());
      phones(phoneNumbers);

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

   void test_delete_local_pointer() {

      printf("test_delete_copied_pointer started\n");

      printf("\n1: ");
      Unit* unit1 = new Unit("simple");
      printf("\n2: ");
      Unit* unit2 = unit1;
      printf("\n3: ");
      Unit unit3(*unit2);
      printf("\n4: ");
      Unit unit4("");
      unit4 = *unit2;
      printf("\n5: ");
      unit4 = "cast";

      printf("\n");
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

      printf("test_delete_copied_pointer ended\n\n");
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

   void test_delete_copy_pointer() {

      printf("test_delete_copy_pointer started\n\n");

      Unit* unit1 = new Unit("UNIT_NAME test_delete_reference_pointer");
      Unit* unit2 = unit1;

      // unit1 and unit2 are copied when method is called
      _test_delete_copy_pointer(unit1, unit2);

      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", unit1 != 0);
      CPPUNIT_ASSERT_MESSAGE("Should not point to 0", unit2 != 0);

      CPPUNIT_ASSERT_MESSAGE("Should not point to NULL", unit1 != NULL);
      CPPUNIT_ASSERT_MESSAGE("Should not point to NULL", unit2 != NULL);

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

   void _test_delete_copy_pointer(Unit* unit1, Unit* unit2) {

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
         new CppUnit::TestCaller<GeneralTest>("test_delete_local_pointer", &GeneralTest::test_delete_local_pointer));
   suite.addTest(
         new CppUnit::TestCaller<GeneralTest>("test_delete_copy_pointer", &GeneralTest::test_delete_copy_pointer));
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

