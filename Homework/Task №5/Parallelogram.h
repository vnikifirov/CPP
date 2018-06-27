#pragma once

#include "Figure.h"

class Parallelogram : public Figure {
public:
	Parallelogram();
	Parallelogram(int);

	void pushSide(int);
};