#include <iostream>
#include <iomanip>

#include "Square.h"

using namespace std;

Square::Square() : Figure() {}
Square::Square(int SIZE) : Figure(SIZE) {}

void Square::pushSide(int sNum) {
	try {
		if ((arrNum[0] != sNum) && top > 0)
			throw "Error values should be equal ";
		Figure::pushSide(sNum);
	}
	catch (const char* errNotEqual) {
		cerr << errNotEqual << arrNum[0] << setw(2) << sNum << endl;
	}
}