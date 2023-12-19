#pragma once

#include "vector.h"

#include <string>

class Book {
public :
	Book() {}
	virtual std::string getFullName() = 0;

};