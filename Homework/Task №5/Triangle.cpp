#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Triangle.h"

using namespace std;

Triangle::Triangle() : Figure() {}
Triangle::Triangle(int SIZE) : Figure(SIZE) {}

void Triangle::pushSide(int tNum) {
	try {
		if ((arrNum[0] >= tNum) && top > 0)
			throw "Error values cann't be:";
		Figure::pushSide(tNum);
	}
	catch (const char* errNotEqual) {
		cerr << errNotEqual << arrNum[0] << setw(2) << tNum << endl;
	}
}

void Triangle::showArea() {
	cout << "| Area:" << setw(17)
		<< (arrNum[0] * arrNum[1]) / 2 << endl;
}