/*
 * Unit.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef UNIT_H_
#define UNIT_H_

#include <string>

namespace com {
namespace thiagoh {

class Unit {

public:

   Unit(std::string id) :
         _id(id) {
   }

   virtual ~Unit() {

   }

   std::string id() const {
      return _id;
   }

   operator std::string() const {
      return _id;
   }

   operator const char*() const {
      return _id.c_str();
   }

private:
   std::string _id;
};

}
}
#endif /* UNIT_H_ */
