/*
 * Event.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <string>

namespace com {
namespace thiagoh {

class Event {

public:

   Event(const std::string type) :
         _type(type) {
   }
   virtual ~Event() {

   }

   std::string type() const {
      return _type;
   }

   bool operator==(const Event& rhs) {
      return this == &rhs || _type.compare(rhs._type) == 0;
   }

   bool operator!=(const Event& rhs) {
      return !((*this) == rhs);
   }

   operator std::string() const {
      return _type;
   }

   operator const char*() const {
      return _type.c_str();
   }

private:
   const std::string _type;
};

namespace Events {
Event CAR_FALL("car-fall");
Event CAR_HIT("car-hit");
Event CAR_EXPLODE("car-explode");
Event MAN_HIT("man-hit");
}

}
}

#endif /* EVENT_H_ */
