/*
 * Subject.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <cstdio>
#include <string>

#include "../../core/src/Event.h"
#include "../../core/src/Unit.h"
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

   static Subject& base() {
      static Subject _base("Base subject");
      return _base;
   }

   void addObserver(Observer* observer) {

      ObserverNode* node = new ObserverNode(observer);

      if (_head == NULL) {
         _head = node;
      } else {
         node->_next = _head;
         _head = node;
      }
   }

   bool removeObserver(Observer* observer) {

      if (_head == NULL) {
         return false;
      }

      ObserverNode* cur = _head;

      if (cur->_observer == observer) {
         _head = _head->_next;
         delete cur;
         return true;
      }

      while (cur->_next != NULL) {

         ObserverNode* next = cur->_next;

         if (next->_observer == observer) {
            cur->_next = next->_next;
            delete next;
            return true;
         }

         cur = next;
      }

      return false;
   }

   void notify(const Unit& unit, const Event& event) {

      printf("------------------------------------------------\n");
      printf("Start of Subject notify '%s'\n", _name.c_str());

      ObserverNode* node = _head;

      while (node != NULL) {
         node->_observer->onNotify(unit, event);
         node = node->_next;
      }

      if (this != &base()) {
         base().notify(unit, event);
      }
   }

protected:

private:

   std::string _name;
   ObserverNode* _head;
}
;

} /* namespace thiagoh */
} /* namespace com */

#endif /* SUBJECT_H_ */
