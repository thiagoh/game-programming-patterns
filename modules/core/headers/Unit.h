/*
 * Unit.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: thiago
 */

#ifndef UNIT_H_
#define UNIT_H_

#include <Input.h>
#include <State.h>
#include <string>

namespace com {
namespace thiagoh {

class State;

class Unit {

public:

	Unit(std::string id);
	virtual ~Unit();

	std::string id() const {
		return _id;
	}

	operator std::string() const {
		return _id;
	}

	operator const char*() const {
		return _id.c_str();
	}

	void handleInput(Input input);

private:
	std::string _id;
	State* state;
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* UNIT_H_ */
