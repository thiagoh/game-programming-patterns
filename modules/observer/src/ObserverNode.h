/*
 * ObserverNode.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef OBSERVERNODE_H_
#define OBSERVERNODE_H_

#include "ObserverNode.h"
#include "Observer.h"
#include "Subject.h"

namespace com {
namespace thiagoh {

class ObserverNode {

   friend class Subject;

public:
   ObserverNode(Observer* observer) :
         _observer(observer), _next(0) {
   }
   virtual ~ObserverNode() {
   }
private:
   Observer* _observer;
   ObserverNode* _next;
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* OBSERVERNODE_H_ */
