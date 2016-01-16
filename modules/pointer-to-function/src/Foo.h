/*
 * Foo.h
 *
 *  Created on: Jan 15, 2016
 *      Author: thiagoh
 */

#ifndef FOO_H_
#define FOO_H_

#include <string>

namespace com {
namespace thiagoh {

class Foo {
public:
	Foo(std::string name) :
			_name(name) {
	}
	virtual ~Foo() {
	}

	std::string getValue(std::string s1, std::string s2) {
		return s1 + " " + _name + " " + s2;
	}

	static std::string processValue(std::string s1, std::string s2) {
		return s1 + " genericName " + s2;
	}

private:
	std::string _name;
};

} /* namespace thiagoh */
} /* namespace com */

#endif /* FOO_H_ */
