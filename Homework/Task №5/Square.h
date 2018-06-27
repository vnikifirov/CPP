#pragma once

#include "Figure.h"

class Square : public Figure {
public:
	Square();
	Square(int);

	void pushSide(int);
};