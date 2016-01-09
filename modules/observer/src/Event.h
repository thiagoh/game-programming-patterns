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



   bool operator==(const Event& rhs) {
      return this == &rhs || _type.compare(rhs._type) == 0;
   };

   bool operator!=(const Event& rhs) {
      return !((*this) == rhs);
   };

private:
   const std::string _type;
};

}
}

#endif /* EVENT_H_ */
