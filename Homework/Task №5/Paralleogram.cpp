#include <iostream>
#include <iomanip>

#include "Parallelogram.h"

using namespace std;

Parallelogram::Parallelogram() : Figure() {}
Parallelogram::Parallelogram(int SIZE) : Figure(SIZE) {}

void Parallelogram::pushSide(int pNum) {
	Figure::pushSide(pNum);
}