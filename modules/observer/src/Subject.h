/*
 * Subject.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <string>
#include "Observer.h"
#include "ObserverNode.h"

namespace com {
namespace thiagoh {

class Subject {
public:
   Subject(std::string name) :
         _name(name), _head(0) {
   }
   virtual ~Subject() {
   }

   std::string name() {
      return _name;
   }

   void addObserver(Observer* observer) {
      _head->_next = _head;
      _head = new ObserverNode(observer);
   }

   bool removeObserver(Observer* observer) {

      if (_head == NULL) {
         return false;
      }

      if (_head->_observer == observer) {
         _head = _head->_next;
//         _head->_next = nullptr;
         delete _head->_next;
         return true;
      }

      ObserverNode* node = _head;

      while (node->_next != NULL) {

         if (node->_next->_observer == observer) {
            ObserverNode* next = node->_next;
            node->_next = next->_next;
//            next->_next = nullptr;
            delete next;
            return true;
         }

         node = node->_next;
      }

      return false;
   }

protected:

   void notify(const Unit& unit, Event event) {

      ObserverNode* node = _head;

      while (node != NULL) {
         node->_observer->onNotify(unit, event);
         node = node->_next;
      }
   }

private:

   std::string _name;
   ObserverNode* _head;
}
;

} /* namespace thiagoh */
} /* namespace com */

#endif /* SUBJECT_H_ */
