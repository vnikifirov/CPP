#pragma once

#include "Figure.h"

class Triangle : public Figure {
public:
	Triangle();
	Triangle(int);

	void pushSide(int);
	void showArea();
};